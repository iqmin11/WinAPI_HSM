#include "PM2Core.h"
#include "TitleLevel.h"

PM2Core PM2Core::Core; //PM2Core.cpp���Ͼȿ��� �����ϴ� �������� PM2Core

void PM2Core::Start()
{
	CreateLevel<TitleLevel>("Title");
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

