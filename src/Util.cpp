/*
 * Util.cpp
 *
 *  Created on: May 23, 2011
 *      Author: huydung.com
 */

#include "Util.h"
using namespace Osp::Base;
using namespace Osp::Ui::Controls;

Util::Util() {
	// TODO Auto-generated constructor stub

}

Util::~Util() {
	// TODO Auto-generated destructor stub
}

MusicRelaxation *
Util::GetApp(){
	return (MusicRelaxation*) Osp::App::Application::GetInstance();
}

String
Util::GetInfoString( int key ){
	String str;
	str.Append(key);
	String result;
	Osp::App::AppRegistry* appRegistry = Osp::App::Application::GetInstance()->GetAppRegistry();
	String tmp;
	if( IsFailed(appRegistry->Get(str, tmp)) ){
		appRegistry->Add(str, result);
		return result;
	}
	return tmp;
};

String
Util::GetInfoString( int key, String defaultStr ){
	if(defaultStr == ""){defaultStr = " ";}
	String str;
	str.Append(key);
	String result;
	Osp::App::AppRegistry* appRegistry = Osp::App::Application::GetInstance()->GetAppRegistry();
	if( IsFailed(appRegistry->Get(str, result)) ){
		appRegistry->Add(str, defaultStr);
		result = defaultStr;
	}
	if(result == " "){ return ""; }
	return result;
};

void
Util::SaveInfoStr( int key, Osp::Base::String value ){
	if( value.GetLength() == 0 ){ value = " ";};
	String str;
	str.Append(key);
	Osp::App::AppRegistry* appRegistry = Osp::App::Application::GetInstance()->GetAppRegistry();
	String tmp;
	if( IsFailed(appRegistry->Get(str, tmp)) ){
		appRegistry->Add(str, value);
	}else{
		appRegistry->Set(str, value);
	}
	return;
};

int
Util::GetInfoInt(int key){
	String str;
	str.Append(key);
	int i = 0;
	int tmp = 0;
	Osp::App::AppRegistry* appRegistry = Osp::App::Application::GetInstance()->GetAppRegistry();
	if( IsFailed(appRegistry->Get(str, tmp)) ){
		appRegistry->Add(str, i);
		return i;
	}
	return tmp;
}

int
Util::GetInfoInt(int key, int defaultInt){
	String str;
	str.Append(key);
	int i = 0;
	Osp::App::AppRegistry* appRegistry = Osp::App::Application::GetInstance()->GetAppRegistry();
	if( IsFailed(appRegistry->Get(str, i)) ){
		appRegistry->Add(str, defaultInt);
		return defaultInt;
	}
	return i;
}

void
Util::SaveInfoInt( int key, int value ){
	String str;
	str.Append(key);
	Osp::App::AppRegistry* appRegistry = Osp::App::Application::GetInstance()->GetAppRegistry();
	int tmp;
	if( IsFailed(appRegistry->Get(str, tmp)) ){
		appRegistry->Add(str, value);
	}else{
		appRegistry->Set(str, value);
	}
};

void Util::SwitchForm(Form * form, Form * currentForm, bool deleteCurrentForm = true){
	Frame * frame = Util::GetApp()->GetAppFrame()->GetFrame();
	if( frame != form->GetParent() ){
		frame->AddControl(*form);
	}
	frame->SetCurrentForm(*form);
	form->Draw();
	form->Show();
	if(deleteCurrentForm){
		frame->RemoveControl(*currentForm);
	}
}

String
Util::GetFileName(String &fullPath){
	int indexOfLastSlash;
	fullPath.LastIndexOf("/", fullPath.GetLength()-1, indexOfLastSlash);
	if(indexOfLastSlash < 0){indexOfLastSlash = 0;}
	String fileName;
	fullPath.SubString(indexOfLastSlash+1, fileName);
	return fileName;
};

String
Util::GetLocaledString(String key){
	String message;
	Osp::App::Application::GetInstance()->GetAppResource()->GetString(key, message);
	return message;
}
