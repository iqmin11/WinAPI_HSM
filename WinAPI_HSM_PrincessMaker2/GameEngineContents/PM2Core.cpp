#include "PM2Core.h"
#include "TitleLevel.h"
#include "FirstSetLevel.h"
#include "OpeningLevel.h"
#include "RaisingSimLevel.h"
#include "RPGLevel.h"
#include "EndingLevel.h"

PM2Core PM2Core::Core; //PM2Core.cpp���Ͼȿ��� �����ϴ� �������� PM2Core

void PM2Core::Start()
{
	CreateLevel<TitleLevel>("Title");
	CreateLevel<FirstSetLevel>("FirstSet");
	CreateLevel<OpeningLevel>("Opening");
	CreateLevel<RaisingSimLevel>("RaisingSim");
	CreateLevel<RPGLevel>("RPG");
	CreateLevel<EndingLevel>("Ending");

	ChangeLevel("RaisingSim");
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
