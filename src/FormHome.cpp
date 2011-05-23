#include "FormHome.h"
#include "FormPlay.h"
#include "FormAbout.h"
#include "Util.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::App;

FormHome::FormHome(void)
{
}

FormHome::~FormHome(void)
{
}

bool
FormHome::Initialize()
{
	// Construct an XML form
	Construct(L"IDF_FORMHOME");

	return true;
}

result
FormHome::OnInitializing(void)
{
	result r = E_SUCCESS;

	SetSoftkeyActionId(SOFTKEY_0, ID_SOFTKEY_0);
	AddSoftkeyActionListener(SOFTKEY_0, *this);
	SetSoftkeyActionId(SOFTKEY_1, ID_SOFTKEY_1);
	AddSoftkeyActionListener(SOFTKEY_1, *this);

	int minutes = Util::GetInfoInt(MusicRelaxation::TIME, 20);
	//Get Control from UI and attach event listeners
	pSlider = static_cast<Slider *>(GetControl("SLIDER_TIME"));
	if (pSlider){
		pSlider->AddAdjustmentEventListener(*this);
		pSlider->SetValue(minutes);
	}else{
		AppLogException("Can not get the Slider");
	}

	pList = static_cast<List *>(GetControl("LIST"));
	if (pList){
		pList->AddItemEventListener(*this);
		Util::GetApp()->getEngine()->PopulateList(pList);
	}else{
		AppLogException("Can not get the List");
	}

	pBtnAdd = static_cast<Button *>(GetControl("BTN_ADD"));
	if (pBtnAdd){
		pBtnAdd->AddActionEventListener(*this);
		pBtnAdd->SetActionId(ID_ADD);
	}else{
		AppLogException("Can not get the Button");
	}

	pLblInTime = static_cast<Label *>(GetControl("LBL_IN_TIME"));
	if (pLblInTime == null){
		AppLogException("Can not get the Label");
	}

	//Adjust the display based on saved value
	OnAdjustmentValueChanged(*pSlider, minutes);
	return r;
}

result
FormHome::OnTerminating(void)
{
	result r = E_SUCCESS;

	return r;
}

void
FormHome::OnActionPerformed(const Osp::Ui::Control& source, int actionId)
{
	switch(actionId){
	case ID_ADD:{
		AppLog("Add Button is clicked! \n");

		//Fire an AppControl request
		ArrayList* pDataList = null;
		pDataList = new ArrayList();
		pDataList->Construct();

		String* pData =  new String(L"type:audio");
		pDataList->Add(*pData);

		String* pData2 = new String(L"selectionType:multiple");
		pDataList->Add(*pData2);

		AppControl* pAc = AppManager::FindAppControlN(APPCONTROL_MEDIA, OPERATION_PICK);
		if(pAc){
			pAc->Start(pDataList, this);
			delete pAc;
		}
		pDataList->RemoveAll(true);
		delete pDataList;
	};	break;
	case ID_SOFTKEY_0:{
		FormPlay * form = new FormPlay();
		form->Initialize();
		Util::SwitchForm(form, this, true);
	}; break;
	case ID_SOFTKEY_1:{
		FormAbout * form = new FormAbout();
		form->Initialize(this);
		Util::SwitchForm(form, this, false);
	}; break;
	default:
		break;
	}
}


void
FormHome::OnAdjustmentValueChanged(const Osp::Ui::Control &source, int adjustment)
{
	if(pSlider != null){
		String minutes;
		int value = pSlider->GetValue();
		Util::SaveInfoInt(MusicRelaxation::TIME, value);
		minutes.Append(value);
		if(pLblInTime != null){
			String lbl = Util::GetLocaledString("IN_MINUTES");
			lbl.Replace("%d", minutes);
			pLblInTime->SetText(lbl);
			pLblInTime->RequestRedraw(true);
		}else{
			AppLogException("pLblInTime is null");
		}
	}else{
		AppLogException("pSlider is null");
	}

}

void
FormHome::OnItemStateChanged(const Osp::Ui::Control &source, int index, int itemId, Osp::Ui::ItemStatus status)
{
	AppLogDebug("List Event Received: %d", index);
	MusicEngine * engine = Util::GetApp()->getEngine();
	if( engine->GetSongsCount() > 0 ){
		engine->RemoveSongAt(index);
		engine->PopulateList(pList);
		Util::SaveInfoStr(MusicRelaxation::MUSIC_LIST, engine->GetListString());
	}else{
		AppLogException("WTF???");
	}
}

void
FormHome::OnAppControlCompleted(const Osp::Base::String& appControlId, const Osp::Base::String& operationId, const Osp::Base::Collection::IList* pResultList){
	String* pMediaResult = null;
	if (appControlId.Equals(APPCONTROL_MEDIA)
		&& operationId.Equals(OPERATION_PICK)){

		pMediaResult = (String*)pResultList->GetAt(0);
		if (pMediaResult->Equals(String(APPCONTROL_RESULT_SUCCEEDED))){
			AppLog("Media list success.");
			int numOfResults = pResultList->GetCount();
			MusicEngine * engine = Util::GetApp()->getEngine();
			for(int i = 1; i < numOfResults; i++){
				String * file = (String*)pResultList->GetAt(i);
				AppLogDebug("Music Files: %S", file->GetPointer());
				engine->AddSong(*file);
			}
			Util::SaveInfoStr(MusicRelaxation::MUSIC_LIST, engine->GetListString());
			engine->PopulateList(pList);
		} else if (pMediaResult->Equals(String(APPCONTROL_RESULT_CANCELED))){
			AppLogDebug("Media list canceled.");
		} else if (pMediaResult->Equals(String(APPCONTROL_RESULT_FAILED))) {
			AppLogDebug("Media list failed.");
		}
	}
}
