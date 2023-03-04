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

	OliveDietRender = CreateRender(PM2RenderOrder::Menu0_Display);
	SetDietRenderText();
	OliveDietRender->SetText(DietRenderText, TextHeight, TextType, TextAlign::Center, TextColor, TextBoxScale);
	OliveDietRender->SetPosition(OliveDietRenderPos);

	AgeRender.SetOwner(this);
	AgeRender.SetImage("Num_Age.bmp", AgeRenderScale, static_cast<int>(PM2RenderOrder::Menu0_Display), RGB(255, 0, 255));
	AgeRender.SetAlign(Align::Center);
	AgeRender.SetValue(Age);
	AgeRender.SetRenderPos(AgeRenderPos);
	
	GoldRender.SetOwner(this);
	GoldRender.SetImage("Num.bmp", GoldRenderScale, static_cast<int>(PM2RenderOrder::Menu0_Display), RGB(255, 0, 255));
	GoldRender.SetAlign(Align::Right);
	GoldRender.SetValue(Gold);
	GoldRender.SetRenderPos(GoldRenderPos);

	HeightRender.SetOwner(this);
	HeightRender.SetImage("Num.bmp", HeightRenderScale, static_cast<int>(PM2RenderOrder::Menu0_Display), RGB(255, 0, 255));
	HeightRender.SetAlign(Align::Center);
	HeightRender.SetValue(static_cast<int>(Height));
	HeightRender.SetRenderPos(HeightRenderPos);

	WeightRender.SetOwner(this);
	WeightRender.SetImage("Num.bmp", WeightRenderScale, static_cast<int>(PM2RenderOrder::Menu0_Display), RGB(255, 0, 255));
	WeightRender.SetAlign(Align::Center);
	WeightRender.SetValue(static_cast<int>(Weight));
	WeightRender.SetRenderPos(WeightRenderPos);

	BustRender.SetOwner(this);
	BustRender.SetImage("Num.bmp", BustRenderScale, static_cast<int>(PM2RenderOrder::Menu0_Display), RGB(255, 0, 255));
	BustRender.SetAlign(Align::Center);
	BustRender.SetValue(static_cast<int>(Bust));
	BustRender.SetRenderPos(BustRenderPos);

	WaistRender.SetOwner(this);
	WaistRender.SetImage("Num.bmp", WaistRenderScale, static_cast<int>(PM2RenderOrder::Menu0_Display), RGB(255, 0, 255));
	WaistRender.SetAlign(Align::Center);
	WaistRender.SetValue(static_cast<int>(Waist));
	WaistRender.SetRenderPos(WaistRenderPos);

	HipRender.SetOwner(this);
	HipRender.SetImage("Num.bmp", HipRenderScale, static_cast<int>(PM2RenderOrder::Menu0_Display), RGB(255, 0, 255));
	HipRender.SetAlign(Align::Center);
	HipRender.SetValue(static_cast<int>(Hip));
	HipRender.SetRenderPos(HipRenderPos);

	PatronGodIconRender = CreateRender("Icon.bmp", PM2RenderOrder::Menu0_Display);
	PatronGodIconRender->SetScale(IconScale);
	PatronGodIconRender->SetPosition(PatronGodIconPos);
	//PatronGodIconRender->SetFrame(static_cast<int>(OlivePatronGod));

	BloodTypeRender = CreateRender("BloodTypeRender.bmp", PM2RenderOrder::Menu0_Display);
	BloodTypeRender ->SetScale(BloodTypeRenderScale);
	BloodTypeRender ->SetPosition(BloodTypeRenderPos);
	//BloodTypeRender ->SetFrame(static_cast<int>(OliveBloodType));

	DiseaseIcon = CreateRender("Icon.bmp", PM2RenderOrder::Menu0_Display);
	DiseaseIcon->SetScale(IconScale);
	DiseaseIcon->SetPosition(DiseaseIconPos);
	DiseaseIcon->SetFrame(static_cast<int>(IconCode::질병상태));
	DiseaseIcon->Off();

	DelinquentIcon = CreateRender("Icon.bmp", PM2RenderOrder::Menu0_Display);
	DelinquentIcon->SetScale(IconScale);
	DelinquentIcon->SetPosition(DelinquentIconPos);
	DelinquentIcon->SetFrame(static_cast<int>(IconCode::불량상태));
	DelinquentIcon->Off();
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

	if (OliveDiet != Olive::OlivePlayer->GetOliveDiet())
	{
		OliveDiet = Olive::OlivePlayer->GetOliveDiet();
		SetDietRenderText();
		OliveDietRender->SetText(DietRenderText, TextHeight, TextType, TextAlign::Center, TextColor, TextBoxScale);
	}

	if (Age != Olive::OlivePlayer->GetOliveAge())
	{
		Age = Olive::OlivePlayer->GetOliveAge();
		AgeRender.SetValue(Age);
	}
	
	if (OlivePatronGod != Olive::OlivePlayer->GetPatronGod())
	{
		OlivePatronGod = Olive::OlivePlayer->GetPatronGod();
		PatronGodIconRender->SetFrame(static_cast<int>(OlivePatronGod));
	}

	if (OliveBloodType != Olive::OlivePlayer->GetBloodType())
	{
		OliveBloodType = Olive::OlivePlayer->GetBloodType();
		BloodTypeRender->SetFrame(static_cast<int>(OliveBloodType));
	}
	
	if (Gold != Olive::OlivePlayer->GetGold())
	{
		Gold = Olive::OlivePlayer->GetGold();
		GoldRender.SetValue(Gold);
	}

	if (Height != Olive::OlivePlayer->GetHeight())
	{
		Height = Olive::OlivePlayer->GetHeight();
		HeightRender.SetValue(static_cast<int>(Height));
	}

	if (Weight != Olive::OlivePlayer->GetWeight())
	{
		Weight = Olive::OlivePlayer->GetWeight();
		WeightRender.SetValue(static_cast<int>(Weight));
	}

	if (Bust != Olive::OlivePlayer->GetBust())
	{
		Bust = Olive::OlivePlayer->GetBust();
		BustRender.SetValue(static_cast<int>(Bust));
	}

	if (Waist != Olive::OlivePlayer->GetWaist())
	{
		Waist = Olive::OlivePlayer->GetWaist();
		WaistRender.SetValue(static_cast<int>(Waist));
	}

	if (Hip != Olive::OlivePlayer->GetHip())
	{
		Hip = Olive::OlivePlayer->GetHip();
		HipRender.SetValue(static_cast<int>(Hip));
	}

	if (DiseaseState != Olive::OlivePlayer->IsDisease())
	{
		DiseaseState = Olive::OlivePlayer->IsDisease();
		switch (DiseaseState)
		{
		case true:
			DiseaseIcon->On();
			break;
		case false:
			DiseaseIcon->Off();
			break;
		}
	}

	if (DelinquentState != Olive::OlivePlayer->IsDelinquent())
	{
		DelinquentState = Olive::OlivePlayer->IsDelinquent();
		switch (DelinquentState)
		{
		case true:
			DelinquentIcon->On();
			break;
		case false:
			DelinquentIcon->Off();
			break;
		}
	}
}

void BasicInfo::Render(float _Time)
{
	//HDC TestDC = GameEngineWindow::GetDoubleBufferImage()->GetImageDC();
	//TextOutA(TestDC, GetPos().ix(), GetPos().iy(), OliveName.c_str(), OliveName.size());
}
