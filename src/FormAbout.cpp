
#include "FormAbout.h"
#include "Util.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;


FormAbout::FormAbout(void)
{
}

FormAbout::~FormAbout(void)
{
}

bool
FormAbout::Initialize(Form * lastForm)
{
	Form::Construct(L"IDF_FORMABOUT");
	pLastForm = lastForm;
	return true;
}

result
FormAbout::OnInitializing(void)
{
	result r = E_SUCCESS;

	SetSoftkeyActionId(SOFTKEY_0, ID_SOFTKEY_0);
	AddSoftkeyActionListener(SOFTKEY_0, *this);

	return r;
}

result
FormAbout::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}



void
FormAbout::OnActionPerformed(const Osp::Ui::Control &source, int actionId)
{
	switch (actionId) {
	case ID_SOFTKEY_0:{
		if(pLastForm != null){
			Util::SwitchForm(pLastForm, this, true);
		}
	}; break;
	default:
		break;
	}

}
