#include "FormHome.h"
#include "FormPlay.h"
#include "FormAbout.h"
#include "Util.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

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

	return r;
}

result
FormHome::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}

void
FormHome::OnActionPerformed(const Osp::Ui::Control& source, int actionId)
{
	switch(actionId)
	{
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


