/*
学籍番号：j17086
名前：亀田朋来
*/

#pragma once
#include <DxLib.h>

#define DEF_FSIZE		30// デフォルトの大きさ
#define DEF_FTHINCK		 5// デフォルトのポイント

class Font
{
private:
	int fHandle;
	int fSize;
	int fThinck;
	int fType;

public:
	Font(const char *fontName = NULL, int type = DX_FONTTYPE_NORMAL) 
	{
		fHandle	 = 0;
		fSize	 = DEF_FSIZE;
		fThinck	 = DEF_FTHINCK;
		fType	 = type;
		fHandle =  CreateFontToHandle(fontName, fSize, fThinck, fType);
	};
	~Font() 
	{
		if (fHandle != -1)
		{
			DeleteFontToHandle(fHandle);
			fHandle = 0;
		}
		fSize	 = 0;
		fThinck	 = 0;
		fType	 = 0;
	};
	int GetHandle()
	{
		return fHandle;
	}
	int SetFont(const char *fontName = NULL, int size = DEF_FSIZE, int thinck = DEF_FTHINCK,int type = DX_FONTTYPE_NORMAL)
	{
		if (fHandle != -1)
		{
			DeleteFontToHandle(fHandle);
			fHandle = 0;
		}
		fSize	 = size;
		fThinck	 = thinck;
		fType	 = type;
		fHandle	 = CreateFontToHandle(fontName, fSize, fThinck, fType);
	}
};