#include "PM2Core.h"
#include <GameEnginePlatform/GameEngineWindow.h>

#include "TitleLevel.h"
#include "FirstSetLevel.h"
#include "OpeningLevel.h"
#include "RaisingSimLevel.h"
#include "RPGLevel.h"
#include "EndingLevel.h"

PM2Core PM2Core::Core; 

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

