#include "BasicInfo.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>

#include "Olive.h"
#include "ContentsEnums.h"

BasicInfo::BasicInfo()
{

}

BasicInfo::~BasicInfo()
{

}

void BasicInfo::Start()
{
	SetPos(ActorPos);
	//SetStar(Zodiac::사자자리); // 이건 아이콘 액터를 만들고 렌더하자
	
	BasicInfoFrame = CreateRender("BasicInfo.bmp",PM2RenderOrder::Menu0); // 베이직 인포 프레임 렌더
	BasicInfoFrame->SetScaleToImage();

	FirstNameRender = CreateRender(PM2RenderOrder::Menu0_Display);
	FirstNameRender->SetText(OliveFirstName, TextHeight, TextType, TextAlign::Center, TextColor, TextBoxScale);
	FirstNameRender->SetPosition(FirstNameRenderPos);
	
	LastNameRender = CreateRender(PM2RenderOrder::Menu0_Display);
	LastNameRender->SetText(OliveLastName, TextHeight, TextType, TextAlign::Center, TextColor, TextBoxScale);
	LastNameRender->SetPosition(LastNameRenderPos);

	AgeRender.SetOwner(this);
	AgeRender.SetImage("Num_Age.bmp", { 20, 20 }, static_cast<int>(PM2RenderOrder::Menu0_Display), RGB(255, 0, 255));
	AgeRender.SetAlign(Align::Center);
	AgeRender.SetValue(Age);
	AgeRender.SetRenderPos({ -70,-20 });
	
	GoldRender.SetOwner(this);
	GoldRender.SetImage("Num.bmp", { 10, 19 }, static_cast<int>(PM2RenderOrder::Menu0_Display), RGB(255, 0, 255));
	GoldRender.SetAlign(Align::Right);
	GoldRender.SetValue(Gold);
	GoldRender.SetRenderPos({ 65,-12 });

	HeightRender.SetOwner(this);
	HeightRender.SetImage("Num.bmp", { 10, 20 }, static_cast<int>(PM2RenderOrder::Menu0_Display), RGB(255, 0, 255));
	HeightRender.SetAlign(Align::Center);
	HeightRender.SetValue(static_cast<int>(Height));
	HeightRender.SetRenderPos({ -75, 89 });

	WeightRender.SetOwner(this);
	WeightRender.SetImage("Num.bmp", { 10, 20 }, static_cast<int>(PM2RenderOrder::Menu0_Display), RGB(255, 0, 255));
	WeightRender.SetAlign(Align::Center);
	WeightRender.SetValue(static_cast<int>(Weight));
	WeightRender.SetRenderPos({ -35, 89 });

	BustRender.SetOwner(this);
	BustRender.SetImage("Num.bmp", { 10, 20 }, static_cast<int>(PM2RenderOrder::Menu0_Display), RGB(255, 0, 255));
	BustRender.SetAlign(Align::Center);
	BustRender.SetValue(static_cast<int>(Bust));
	BustRender.SetRenderPos({ -5, 89 });

	WaistRender.SetOwner(this);
	WaistRender.SetImage("Num.bmp", { 10, 20 }, static_cast<int>(PM2RenderOrder::Menu0_Display), RGB(255, 0, 255));
	WaistRender.SetAlign(Align::Center);
	WaistRender.SetValue(static_cast<int>(Waist));
	WaistRender.SetRenderPos({ 37, 89 });

	HipRender.SetOwner(this);
	HipRender.SetImage("Num.bmp", { 10, 20 }, static_cast<int>(PM2RenderOrder::Menu0_Display), RGB(255, 0, 255));
	HipRender.SetAlign(Align::Center);
	HipRender.SetValue(static_cast<int>(Hip));
	HipRender.SetRenderPos({ 79, 89 });

	//StarRender = CreateRender("", PM2RenderOrder::Menu0_Display);
}

void BasicInfo::Update(float _DeltaTime)
{
	if (OliveFirstName != Olive::OlivePlayer->GetOliveFirstName())
	{
		OliveFirstName = Olive::OlivePlayer->GetOliveFirstName();
		FirstNameRender->SetText(OliveFirstName, TextHeight, TextType, TextAlign::Center, TextColor, TextBoxScale);
	}
	
	if (OliveLastName != Olive::OlivePlayer->GetOliveLastName())
	{
		OliveLastName = Olive::OlivePlayer->GetOliveLastName();
		LastNameRender->SetText(OliveLastName, TextHeight, TextType, TextAlign::Center, TextColor, TextBoxScale);
	}

	if (Age != Olive::OlivePlayer->GetOliveAge())
	{
		Age = Olive::OlivePlayer->GetOliveAge();
		AgeRender.SetValue(Age);
	}
	
	//if (Star != Olive::OlivePlayer->GetOliveZodiac())
	//{
	//	Star = Olive::OlivePlayer->GetOliveZodiac();
	//}
	
	if (Gold != Olive::OlivePlayer->GetGold())
	{
		Gold = Olive::OlivePlayer->GetGold();
		GoldRender.SetValue(Gold);
	}
}

void BasicInfo::Render(float _Time)
{
	//HDC TestDC = GameEngineWindow::GetDoubleBufferImage()->GetImageDC();
	//TextOutA(TestDC, GetPos().ix(), GetPos().iy(), OliveName.c_str(), OliveName.size());
}
