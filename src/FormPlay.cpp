
#include "FormPlay.h"
#include "FormAbout.h"
#include "FormHome.h"
#include "Util.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;


FormPlay::FormPlay(void)
{
}

FormPlay::~FormPlay(void)
{
}

bool
FormPlay::Initialize()
{
	Form::Construct(L"IDF_FORMPLAY");

	return true;
}

result
FormPlay::OnInitializing(void)
{
	result r = E_SUCCESS;

	SetSoftkeyActionId(SOFTKEY_0, ID_SOFTKEY_0);
	AddSoftkeyActionListener(SOFTKEY_0, *this);
	SetSoftkeyActionId(SOFTKEY_1, ID_SOFTKEY_1);
	AddSoftkeyActionListener(SOFTKEY_1, *this);

	return r;
}

result
FormPlay::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}



void
FormPlay::OnActionPerformed(const Osp::Ui::Control &source, int actionId)
{
	switch(actionId){
		case ID_SOFTKEY_0:{
			//Call form About
			FormHome * form = new FormHome();
			form->Initialize();
			Util::SwitchForm(form, this, true);
		}; break;
		case ID_SOFTKEY_1:{
			FormAbout * form = new FormAbout();
			form->Initialize(this);
			Util::SwitchForm(form, this, false);
		}; break;
	}
}
