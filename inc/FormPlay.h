
#ifndef _FORMPLAY_H_
#define _FORMPLAY_H_

#include <FBase.h>
#include <FUi.h>



class FormPlay :
	public Osp::Ui::Controls::Form,
 	public Osp::Ui::IActionEventListener
{

// Construction
public:
	FormPlay(void);
	virtual ~FormPlay(void);
	bool Initialize();
	result OnInitializing(void);
	result OnTerminating(void);

	static const int ID_SOFTKEY_0 = 102;
	static const int ID_SOFTKEY_1 = 103;

// Implementation
protected:

// Generated call-back functions
public:


	virtual void OnActionPerformed(const Osp::Ui::Control &source, int actionId);
};

#endif
