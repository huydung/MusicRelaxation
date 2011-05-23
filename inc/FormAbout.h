
#ifndef _FORMABOUT_H_
#define _FORMABOUT_H_

#include <FBase.h>
#include <FUi.h>



class FormAbout :
	public Osp::Ui::Controls::Form,
 	public Osp::Ui::IActionEventListener
{

// Construction
public:
	FormAbout(void);
	virtual ~FormAbout(void);
	bool Initialize(Osp::Ui::Controls::Form * lastForm);
	result OnInitializing(void);
	result OnTerminating(void);

	static const int ID_SOFTKEY_0 = 102;


// Implementation
protected:
	Osp::Ui::Controls::Form * pLastForm;
// Generated call-back functions
public:


	virtual void OnActionPerformed(const Osp::Ui::Control &source, int actionId);
};

#endif
