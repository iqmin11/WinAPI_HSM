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
	//HDC hdc = GameEngineWindow::GetDoubleBufferImage()->GetImageDC();
	
	

	//SetTextColor(hdc, RGB( 255,255,255 ));

	CreateLevel<TitleLevel>("Title");
	CreateLevel<FirstSetLevel>("FirstSet");
	CreateLevel<OpeningLevel>("Opening");
	CreateLevel<RaisingSimLevel>("RaisingSim");
	CreateLevel<RPGLevel>("RPG");
	CreateLevel<EndingLevel>("Ending");

	ChangeLevel("Opening");
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

