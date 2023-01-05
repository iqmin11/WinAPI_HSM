#include "PM2Core.h"
#include "TitleLevel.h"
#include "FirstSetLevel.h"
#include "OpeningLevel.h"
#include "RaisingSimLevel.h"
#include "RPGLevel.h"
#include "EndingLevel.h"

PM2Core PM2Core::Core; //PM2Core.cpp파일안에서 존재하는 전역변수 PM2Core

void PM2Core::Start()
{
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
	int a = 0;
}

void PM2Core::End()
{
	int a = 0;
}

PM2Core::PM2Core()
{

}

PM2Core::~PM2Core()
{

}

