/*
 * MusicEngine.cpp
 *
 *  Created on: May 23, 2011
 *      Author: huydung.com
 */

#include "MusicEngine.h"
#include <FMedia.h>
#include "Util.h"

using namespace Osp::Base::Utility;
using namespace Osp::Graphics;

MusicEngine::MusicEngine():
_files(null),_songs(null),pBmpDel(null){
	// TODO Auto-generated constructor stub

}

MusicEngine::~MusicEngine() {
	if( _files != null ){
		delete _files;
	}
	if( _songs != null ){
		_songs->RemoveAll(true);
		delete _songs;
	}
}

result
MusicEngine::Construct(String files){
	AppLogDebug("Construct engine with: %S", files.GetPointer());
	SetSongsList(files);
	//Create the delete image
	Osp::Media::Image * image = new Osp::Media::Image();
	if(!IsFailed(image->Construct())){
		pBmpDel = image->DecodeN("/Res/480x800/116.png", BITMAP_PIXEL_FORMAT_ARGB8888);
		delete image;
	}else{
		AppLogException("Can not construct Image");
	}
};

bool
MusicEngine::SetSongsList(String files){

	if( _files != null ){ delete _files; }

	if( _songs != null ){ _songs->RemoveAll(true); }
	else{ _songs = new ArrayList(); _songs->Construct(); }

	_files = new String( files );
	if( _files->GetLength() > 0 ){
		StringTokenizer tkn(*_files, ",");
		String filePath;
		while(tkn.HasMoreTokens()){
			if(IsFailed(tkn.GetNextToken(filePath))){
				return false;
			};
			filePath.Trim();
			if(IsFailed(_songs->Add(* new String(filePath)))){
				_songs->RemoveAll(true);
				AppLogException("Error when add song %S to List", filePath.GetPointer());
				return false;
			}
		}
		return true;
	}
	return false;
}

int
MusicEngine::IndexOf(String fileName){
	int index = -1;
	if( _songs != null ){
		_songs->IndexOf(fileName, index);
		return index;
	}
	return -1;
};

int
MusicEngine::GetSongsCount(){
	if( _songs != null ){
		return _songs->GetCount();
	}
	return 0;
};

String
MusicEngine::GetListString(){
	return *_files;
}

bool
MusicEngine::AddSong(String fileName){
	if( _songs != null ){
		int index = IndexOf(fileName);
		if( index < 0 ){
			_songs->Add(*(new String(fileName)));
			AppLogDebug("Added song %S", fileName.GetPointer());
			_convertListToString();
			return true;
		}else{
			AppLogDebug("Songs %S already in List at %d", fileName.GetPointer(), index);
			return false;
		}
	}
	return false;
};

bool
MusicEngine::RemoveSong(String fileName){
	int index = IndexOf(fileName);
	if( index > -1 ){
		_songs->RemoveAt( index, true );
		_convertListToString();
		return true;
	}else{
		AppLogDebug("Songs is not in List");
		return false;
	}
};

bool
MusicEngine::RemoveSongAt(int index){
	if( _songs != null ){
		_songs->RemoveAt( index, true );
		_convertListToString();
	};
	return false;
}

void
MusicEngine::_convertListToString(){
	if ( _files != null ){ _files->Clear(); }
	else{ _files = new String(""); }

	if( _songs != null ){
		IEnumerator * iter = _songs->GetEnumeratorN();
		String * file;
		String tmp;
		while( !IsFailed(iter->MoveNext()) ){
			file = (String*)iter->GetCurrent();
			tmp.Append(*file);
			tmp.Append(",");
		}

		if( tmp.GetLength() > 0 ){
			tmp.SubString(0, tmp.GetLength() - 1, *_files);
		};
		AppLogDebug("Current Files: %S", _files->GetPointer());
		delete iter;
	}
}

void
MusicEngine::PopulateList(List * pList){
	pList->RemoveAllItems();
	if( _songs->GetCount() > 0 ){
		IEnumerator * iter = _songs->GetEnumeratorN();
		String * file;
		while( !IsFailed(iter->MoveNext()) ){
			file = (String*)iter->GetCurrent();
			String name = Util::GetFileName(*file);
			pList->AddItem(&name, null, pBmpDel, null, 1);
		}
	}
	pList->RequestRedraw(true);
}
