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
	
	Painting->SetIconButton(IconCode::미술, "미술", "초급", 40, Button1Pos);
	Dance->SetIconButton(IconCode::무용, "무도", "초급", 50, Button2Pos);
	Magic->SetIconButton(IconCode::마법, "마법", "초급", 60, Button3Pos);
	Protocol->SetIconButton(IconCode::예법, "예법", "초급", 40, Button4Pos);
	Fencing->SetIconButton(IconCode::검술, "검술", "초급", 40, Button5Pos);
	Fighting->SetIconButton(IconCode::격투술, "격투술", "초급", 30, Button6Pos);
	Theology->SetIconButton(IconCode::신학, "신학", "초급", 40, Button7Pos);
	Strategy->SetIconButton(IconCode::군사학, "군사학	", "초급", 50, Button8Pos);
	Science->SetIconButton(IconCode::자연과학, "자연과학", "초급", 30, Button9Pos);
	Poetry->SetIconButton(IconCode::시문학, "시문", "초급", 40, Button10Pos);

	Off();
}
