#include "BasicInfo.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnums.h"

BasicInfo::BasicInfo()
{

}

BasicInfo::~BasicInfo()
{

}

void BasicInfo::Start()
{
	SetName("HwangSeungMin");
	SetPos({700, 109});
	SetAge(10);
	SetStar(Zodiac::Leo); // 이건 아이콘 액터를 만들고 렌더하자
	SetGold(1000);
	SetHeight(130.0f);
	SetWeight(27.0f);
	SetBust(20.0f);
	SetWaist(20.0f);
	SetHip(20.0f);
	
	BasicInfoFrame = CreateRender("BasicInfo.bmp",PM2RenderOrder::Menu0); // 베이직 인포 프레임 렌더

	AgeRender.SetOwner(this);
	AgeRender.SetImage("Num_Age.bmp", { 20, 20 }, static_cast<int>(PM2RenderOrder::Menu0_Display), RGB(255, 0, 255));
	AgeRender.SetAlign(Align::Center);
	AgeRender.SetValue(Age);
	AgeRender.SetMove({ -70,-20 });
	
	GoldRender.SetOwner(this);
	GoldRender.SetImage("Num.bmp", { 10, 19 }, static_cast<int>(PM2RenderOrder::Menu0_Display), RGB(255, 0, 255));
	GoldRender.SetAlign(Align::Right);
	GoldRender.SetValue(Gold);
	GoldRender.SetMove({ 65,-12 });
	
	HeightRender.SetOwner(this);
	HeightRender.SetImage("Num.bmp", { 10, 20 }, static_cast<int>(PM2RenderOrder::Menu0_Display), RGB(255, 0, 255));
	HeightRender.SetAlign(Align::Center);
	HeightRender.SetValue(static_cast<int>(Height));
	HeightRender.SetMove({ -75, 89 });

	WeightRender.SetOwner(this);
	WeightRender.SetImage("Num.bmp", { 10, 20 }, static_cast<int>(PM2RenderOrder::Menu0_Display), RGB(255, 0, 255));
	WeightRender.SetAlign(Align::Center);
	WeightRender.SetValue(static_cast<int>(Weight));
	WeightRender.SetMove({ -35, 89 });
	
	BustRender.SetOwner(this);
	BustRender.SetImage("Num.bmp", { 10, 20 }, static_cast<int>(PM2RenderOrder::Menu0_Display), RGB(255, 0, 255));
	BustRender.SetAlign(Align::Center);
	BustRender.SetValue(static_cast<int>(Bust));
	BustRender.SetMove({ -5, 89 });

	WaistRender.SetOwner(this);
	WaistRender.SetImage("Num.bmp", { 10, 20 }, static_cast<int>(PM2RenderOrder::Menu0_Display), RGB(255, 0, 255));
	WaistRender.SetAlign(Align::Center);
	WaistRender.SetValue(static_cast<int>(Waist));
	WaistRender.SetMove({ 37, 89 });

	HipRender.SetOwner(this);
	HipRender.SetImage("Num.bmp", { 10, 20 }, static_cast<int>(PM2RenderOrder::Menu0_Display), RGB(255, 0, 255));
	HipRender.SetAlign(Align::Center);
	HipRender.SetValue(static_cast<int>(Hip));
	HipRender.SetMove({ 79, 89 });

	//StarRender = CreateRender("", PM2RenderOrder::Menu0_Display);
}

void BasicInfo::Update(float _DeltaTime)
{
}

void BasicInfo::Render(float _Time)
{
	//HDC TestDC = GameEngineWindow::GetDoubleBufferImage()->GetImageDC();
	//TextOutA(TestDC, GetPos().ix(), GetPos().iy(), OliveName.c_str(), OliveName.size());
}
