#ifndef _FORMHOME_H_
#define _FORMHOME_H_

#include <FBase.h>
#include <FUi.h>

class FormHome :
	public Osp::Ui::Controls::Form,
	public Osp::Ui::IActionEventListener
{

// Construction
public:
	FormHome(void);
	virtual ~FormHome(void);
	bool Initialize(void);

	static const int ID_SOFTKEY_0 = 102;
	static const int ID_SOFTKEY_1 = 103;

// Implementation
protected:


public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);
};

#endif	//_FORM1_H_
