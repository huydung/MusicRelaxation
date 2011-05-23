#include "FormHome.h"

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

	default:
		break;
	}
}


