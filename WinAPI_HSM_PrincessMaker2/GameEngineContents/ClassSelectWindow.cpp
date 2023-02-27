#include "ClassSelectWindow.h"

#include <GameEngineCore/Button.h>
//#include <GameEngineCore/GameEngineLevel.h>
#include "RaisingSimLevel.h"
#include "IconButton.h"

#include "DanceClass.h"
#include "FencingClass.h"
#include "FightingClass.h"
#include "MagicClass.h"
#include "PaintingClass.h"
#include "PoetryClass.h"
#include "ProtocolClass.h"
#include "ScienceClass.h"
#include "StrategyClass.h"
#include "TheologyClass.h"

RaisingSimLevel* ClassSelectWindow::ParentLevel = nullptr;

PaintingClass* ClassSelectWindow::AcPaintingClass = nullptr;
DanceClass* ClassSelectWindow::AcDanceClass = nullptr;
MagicClass* ClassSelectWindow::AcMagicClass = nullptr;
ProtocolClass* ClassSelectWindow::AcProtocolClass = nullptr;
FencingClass* ClassSelectWindow::AcFencingClass = nullptr;
FightingClass* ClassSelectWindow::AcFightingClass = nullptr;
TheologyClass* ClassSelectWindow::AcTheologyClass = nullptr;
StrategyClass* ClassSelectWindow::AcStrategyClass = nullptr;
ScienceClass* ClassSelectWindow::AcScienceClass = nullptr;
PoetryClass* ClassSelectWindow::AcPoetryClass = nullptr;

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
	ParentLevel = dynamic_cast<RaisingSimLevel*>(GetLevel());
	Painting = ParentLevel->CreateActor<IconButton>(PM2ActorOrder::Menu2_Button);
	Dance = ParentLevel->CreateActor<IconButton>(PM2ActorOrder::Menu2_Button);
	Magic = ParentLevel->CreateActor<IconButton>(PM2ActorOrder::Menu2_Button);
	Protocol = ParentLevel->CreateActor<IconButton>(PM2ActorOrder::Menu2_Button);
	Fencing = ParentLevel->CreateActor<IconButton>(PM2ActorOrder::Menu2_Button);
	Fighting = ParentLevel->CreateActor<IconButton>(PM2ActorOrder::Menu2_Button);
	Theology = ParentLevel->CreateActor<IconButton>(PM2ActorOrder::Menu2_Button);
	Strategy = ParentLevel->CreateActor<IconButton>(PM2ActorOrder::Menu2_Button);
	Science = ParentLevel->CreateActor<IconButton>(PM2ActorOrder::Menu2_Button);
	Poetry = ParentLevel->CreateActor<IconButton>(PM2ActorOrder::Menu2_Button);

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

	AcDanceClass = ParentLevel->AcDanceClass;
	AcFencingClass = ParentLevel->AcFencingClass;
	AcFightingClass = ParentLevel->AcFightingClass;
	AcMagicClass = ParentLevel->AcMagicClass;
	AcPaintingClass = ParentLevel->AcPaintingClass;
	AcPoetryClass = ParentLevel->AcPoetryClass;
	AcProtocolClass = ParentLevel->AcProtocolClass;
	AcScienceClass = ParentLevel->AcScienceClass;
	AcStrategyClass = ParentLevel->AcStrategyClass;
	AcTheologyClass = ParentLevel->AcTheologyClass;

	Painting->GetButton()->SetClickCallBack(ClickPainting);

	Off();
}

void ClassSelectWindow::ClickPainting(Button* _Button)
{
	ParentLevel->GoToNextDay();
	Olive::OlivePlayer->OliveStatus += AcPaintingClass->GetStatusVariance();
}


