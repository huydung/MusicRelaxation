/*
 * MusicEngine.h
 *
 *  Created on: May 23, 2011
 *      Author: huydung.com
 */

#ifndef MUSICENGINE_H_
#define MUSICENGINE_H_

#include <FBase.h>
#include <FUi.h>
#include <FGraphics.h>

using namespace Osp::Base;
using namespace Osp::Base::Collection;
using namespace Osp::Ui::Controls;

class MusicEngine {
public:
	MusicEngine();
	virtual ~MusicEngine();

	result Construct(String files);
	bool SetSongsList(String files);
	String GetSongsList();
	bool AddSong(String fileName);
	bool RemoveSong(String fileName);
	bool RemoveSongAt(int index);
	String GetRandomSong();
	String GetListString();

	void PopulateList(List * pList);

	/*For Testing*/
	int IndexOf(String fileName);
	int GetSongsCount();

private:
	Osp::Graphics::Bitmap * pBmpDel;
	String * _files;
	ArrayList * _songs;
	void _convertListToString();
};

#endif /* MUSICENGINE_H_ */
