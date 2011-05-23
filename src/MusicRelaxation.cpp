/**
 * Name        : MusicRelaxtion
 * Version     : 
 * Vendor      : 
 * Description : 
 */


#include "MusicRelaxation.h"
#include "FormHome.h"

using namespace Osp::App;
using namespace Osp::Base;
using namespace Osp::System;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

MusicRelaxation::MusicRelaxation():
_engine(null)
{
}

MusicRelaxation::~MusicRelaxation()
{
}

Application*
MusicRelaxation::CreateInstance(void)
{
	// Create the instance through the constructor.
	return new MusicRelaxation();
}

MusicEngine *
MusicRelaxation::getEngine(){
	return _engine;
};

bool
MusicRelaxation::OnAppInitializing(AppRegistry& appRegistry)
{
	_engine = new MusicEngine();
	String key;
	key.Append(MUSIC_LIST);
	String list = "";
	appRegistry.Get(key, list);
	_engine->Construct(list);

	// Create a form
	FormHome *pForm1 = new FormHome();
	pForm1->Initialize();

	// Add the form to the frame
	Frame *pFrame = GetAppFrame()->GetFrame();
	pFrame->AddControl(*pForm1);

	// Set the current form
	pFrame->SetCurrentForm(*pForm1);

	// Draw and Show the form
	pForm1->Draw();
	pForm1->Show();

	return true;
}

bool
MusicRelaxation::OnAppTerminating(AppRegistry& appRegistry, bool forcedTermination)
{
	if( _engine != null ){
		delete _engine;
	}
	return true;
}

void
MusicRelaxation::OnForeground(void)
{
	// TODO:
	// Start or resume drawing when the application is moved to the foreground.
}

void
MusicRelaxation::OnBackground(void)
{
	// TODO:
	// Stop drawing when the application is moved to the background.
}

void
MusicRelaxation::OnLowMemory(void)
{
	// TODO:
	// Free unused resources or close the application.
}

void
MusicRelaxation::OnBatteryLevelChanged(BatteryLevel batteryLevel)
{
	// TODO:
	// Handle any changes in battery level here.
	// Stop using multimedia features(camera, mp3 etc.) if the battery level is CRITICAL.
}

void
MusicRelaxation::OnScreenOn (void)
{
	// TODO:
	// Get the released resources or resume the operations that were paused or stopped in OnScreenOff().
}

void
MusicRelaxation::OnScreenOff (void)
{
	// TODO:
	//  Unless there is a strong reason to do otherwise, release resources (such as 3D, media, and sensors) to allow the device to enter the sleep mode to save the battery.
	// Invoking a lengthy asynchronous method within this listener method can be risky, because it is not guaranteed to invoke a callback before the device enters the sleep mode.
	// Similarly, do not perform lengthy operations in this listener method. Any operation must be a quick one.
}
