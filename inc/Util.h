/*
 * Util.h
 *
 *  Created on: May 23, 2011
 *      Author: huydung.com
 */

#ifndef UTIL_H_
#define UTIL_H_

#include <FBase.h>
#include <FUi.h>
#include "MusicRelaxation.h"
using namespace Osp::Base;
using namespace Osp::Ui::Controls;

class Util {
public:
	Util();
	virtual ~Util();

	static const int MUSIC_LIST = 1;
	static const int TIME = 2;

	static MusicRelaxation * GetApp();

	static void SaveInfoStr( int key, Osp::Base::String value );
	static String GetInfoString( int key );
	static String GetInfoString( int key, String defaultStr );

	static void SaveInfoInt( int key, int value );
	static int GetInfoInt(int key);
	static int GetInfoInt(int key, int defaultInt);

	static void SwitchForm(Form * form, Form * currentForm, bool deleteCurrentForm);
};

#endif /* UTIL_H_ */
