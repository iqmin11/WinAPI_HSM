#include "PM2Core.h"
#include <GameEnginePlatform/GameEngineWindow.h>

#include "TitleLevel.h"
#include "FirstSetLevel.h"
#include "OpeningLevel.h"
#include "RaisingSimLevel.h"
#include "RPGLevel.h"
#include "EndingLevel.h"

PM2Core PM2Core::Core; //PM2Core.cpp파일안에서 존재하는 전역변수 PM2Core

void PM2Core::Start()
{
	HDC hdc = GameEngineWindow::GetDoubleBufferImage()->GetImageDC();
	//HFONT hFont, OldFont;
	//LOGFONTA lf;
	//lf.lfHeight = 17;
	//lf.lfWidth = 0;
	//lf.lfEscapement = 0;
	//lf.lfOrientation = 0;
	//lf.lfWeight = 0;
	//lf.lfItalic = 0;
	//lf.lfUnderline = 0;
	//lf.lfStrikeOut = 0;
	//lf.lfCharSet = HANGEUL_CHARSET;
	//lf.lfOutPrecision = 0;
	//lf.lfClipPrecision = 0;
	//lf.lfQuality = 0;
	//lf.lfPitchAndFamily = VARIABLE_PITCH | FF_ROMAN;
	//lstrcpy(lf.lfFaceName, TEXT("굴림"));
	//hFont = CreateFontIndirect(&lf);
	//OldFont = static_cast<HFONT>(SelectObject(GameEngineWindow::GetDoubleBufferImage()->GetImageDC(), hFont));
	SetTextAlign(hdc, TA_RIGHT);
	SetTextColor(hdc, RGB( 255,255,255 ));

	CreateLevel<TitleLevel>("Title");
	CreateLevel<FirstSetLevel>("FirstSet");
	CreateLevel<OpeningLevel>("Opening");
	CreateLevel<RaisingSimLevel>("RaisingSim");
	CreateLevel<RPGLevel>("RPG");
	CreateLevel<EndingLevel>("Ending");

	ChangeLevel("Title");
}

void PM2Core::Update()
{

}

void PM2Core::End()
{

}

PM2Core::PM2Core()
{

}

PM2Core::~PM2Core()
{

}

