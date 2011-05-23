#ifndef _FORMHOME_H_
#define _FORMHOME_H_

#include <FBase.h>
#include <FUi.h>
#include <Util.h>
#include <FApp.h>

class FormHome :
	public Osp::Ui::Controls::Form,
	public Osp::Ui::IActionEventListener,
 	public Osp::Ui::IAdjustmentEventListener,
 	public Osp::Ui::IItemEventListener,
 	public Osp::App::IAppControlEventListener
{

// Construction
public:
	FormHome(void);
	virtual ~FormHome(void);
	bool Initialize(void);

	static const int ID_ADD = 101;
	static const int ID_SOFTKEY_0 = 102;
	static const int ID_SOFTKEY_1 = 103;

// Implementation
protected:
	Button * pBtnAdd;
	Slider * pSlider;
	Label * pLblInTime;
	List * pList;

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);
	virtual void OnAdjustmentValueChanged(const Osp::Ui::Control &source, int adjustment);
	virtual void OnItemStateChanged(const Osp::Ui::Control &source, int index, int itemId, Osp::Ui::ItemStatus status);
	virtual void OnAppControlCompleted(const Osp::Base::String& appControlId, const Osp::Base::String& operationId, const Osp::Base::Collection::IList* pResultList);
};

#endif	//_FORM1_H_
