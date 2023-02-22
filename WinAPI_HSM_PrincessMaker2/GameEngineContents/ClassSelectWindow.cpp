#include "ClassSelectWindow.h"
#include <GameEngineCore/GameEngineLevel.h>
#include "IconButton.h"

ClassSelectWindow::ClassSelectWindow()
{

}

ClassSelectWindow::~ClassSelectWindow()
{

}

void ClassSelectWindow::On()
{
	GameEngineObject::On();
	Painting -> On();
	Dance	 -> On();
	Magic	 -> On();
	Protocol -> On();
	Fencing	 -> On();
	Fighting -> On();
	Theology -> On();
	Strategy -> On();
	Science	 -> On();
	Poetry	 -> On();
}

void ClassSelectWindow::Off()
{
	GameEngineObject::Off();
	Painting->Off();
	Dance->Off();
	Magic->Off();
	Protocol->Off();
	Fencing->Off();
	Fighting->Off();
	Theology->Off();
	Strategy->Off();
	Science->Off();
	Poetry->Off();
}

void ClassSelectWindow::Start()
{
	GameEngineLevel* Level = GetLevel();
	Painting     = Level->CreateActor<IconButton>(PM2ActorOrder::Menu2_Button);
	Dance     = Level->CreateActor<IconButton>(PM2ActorOrder::Menu2_Button);
	Magic     = Level->CreateActor<IconButton>(PM2ActorOrder::Menu2_Button);
	Protocol     = Level->CreateActor<IconButton>(PM2ActorOrder::Menu2_Button);
	Fencing     = Level->CreateActor<IconButton>(PM2ActorOrder::Menu2_Button);
	Fighting     = Level->CreateActor<IconButton>(PM2ActorOrder::Menu2_Button);
	Theology     = Level->CreateActor<IconButton>(PM2ActorOrder::Menu2_Button);
	Strategy     = Level->CreateActor<IconButton>(PM2ActorOrder::Menu2_Button);
	Science     = Level->CreateActor<IconButton>(PM2ActorOrder::Menu2_Button);
	Poetry     = Level->CreateActor<IconButton>(PM2ActorOrder::Menu2_Button);
	
	Painting->SetIconButton(IconCode::�̼�, "�̼�", "�ʱ�", 40, Button1Pos);
	Dance->SetIconButton(IconCode::����, "����", "�ʱ�", 50, Button2Pos);
	Magic->SetIconButton(IconCode::����, "����", "�ʱ�", 60, Button3Pos);
	Protocol->SetIconButton(IconCode::����, "����", "�ʱ�", 40, Button4Pos);
	Fencing->SetIconButton(IconCode::�˼�, "�˼�", "�ʱ�", 40, Button5Pos);
	Fighting->SetIconButton(IconCode::������, "������", "�ʱ�", 30, Button6Pos);
	Theology->SetIconButton(IconCode::����, "����", "�ʱ�", 40, Button7Pos);
	Strategy->SetIconButton(IconCode::������, "������	", "�ʱ�", 50, Button8Pos);
	Science->SetIconButton(IconCode::�ڿ�����, "�ڿ�����", "�ʱ�", 30, Button9Pos);
	Poetry->SetIconButton(IconCode::�ù���, "�ù�", "�ʱ�", 40, Button10Pos);

	Off();
}
