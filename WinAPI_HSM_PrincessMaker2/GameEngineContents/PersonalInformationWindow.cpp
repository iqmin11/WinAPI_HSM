#include "PersonalInformationWindow.h"
#include <GameEngineCore/GameEngineRender.h>
#include "Olive.h"

PersonalInformationWindow::PersonalInformationWindow()
{

}

PersonalInformationWindow::~PersonalInformationWindow()
{

}

void PersonalInformationWindow::Start()
{
	InitMenuFrameRender(PM2RenderOrder::Menu1, MenuFrameStyleEnum::Nomal);
	SetMenuFrameScale(Scale);
	SetPos(ActorPos);

	interface_FirstName = CreateRender(PM2RenderOrder::Menu1_Display);
	interface_FirstName->SetText("이름", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
	interface_FirstName->SetPosition(interface_FirstNamePos);

	interface_LastName = CreateRender(PM2RenderOrder::Menu1_Display);
	interface_LastName->SetText("성", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
	interface_LastName->SetPosition(interface_LastNamePos);

	interface_BloodType = CreateRender(PM2RenderOrder::Menu1_Display);
	interface_BloodType->SetText("혈액형", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
	interface_BloodType->SetPosition(interface_BloodTypePos);
	
	interface_Age = CreateRender(PM2RenderOrder::Menu1_Display);
	interface_Age->SetText("나이", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
	interface_Age->SetPosition(interface_AgePos);
	
	interface_BirthDay = CreateRender(PM2RenderOrder::Menu1_Display);
	interface_BirthDay->SetText("생일", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
	interface_BirthDay->SetPosition(interface_BirthDayPos);
	
	interface_Zodiac = CreateRender(PM2RenderOrder::Menu1_Display);
	interface_Zodiac->SetText("별자리", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
	interface_Zodiac->SetPosition(interface_ZodiacPos);
	
	interface_PatronGod = CreateRender(PM2RenderOrder::Menu1_Display);
	interface_PatronGod->SetText("수호성", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
	interface_PatronGod->SetPosition(interface_PatronGodPos);

	FirstNameRender = CreateRender(PM2RenderOrder::Menu1_Display);
	FirstNameRender->SetPosition(FirstNamePos);
	LastNameRender = CreateRender(PM2RenderOrder::Menu1_Display);
	LastNameRender->SetPosition(LastNamePos);
	BloodTypeRender = CreateRender(PM2RenderOrder::Menu1_Display);
	BloodTypeRender->SetPosition(BloodTypePos);
	AgeRender = CreateRender(PM2RenderOrder::Menu1_Display);
	AgeRender->SetPosition(AgePos);
	BirthDayRender = CreateRender(PM2RenderOrder::Menu1_Display);
	BirthDayRender->SetPosition(BirthDayPos);
	ZodiacRender = CreateRender(PM2RenderOrder::Menu1_Display);
	ZodiacRender->SetPosition(ZodiacPos);
	PatronGodRender = CreateRender(PM2RenderOrder::Menu1_Display);
	PatronGodRender->SetPosition(PatronGodPos);
}

void PersonalInformationWindow::Update(float _DeltaTime)
{
	UpdatePersonalInformationWindow();
}

void PersonalInformationWindow::UpdatePersonalInformationWindow()
{
	if (FirstName != Olive::OlivePlayer->GetOliveFirstName())
	{
		FirstName = Olive::OlivePlayer->GetOliveFirstName();
		FirstNameRender->SetText(FirstName, TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
	}

	if (LastName != Olive::OlivePlayer->GetOliveLastName())
	{
		LastName = Olive::OlivePlayer->GetOliveLastName();
		LastNameRender->SetText(LastName, TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
	}

	if (BloodType != Olive::OlivePlayer->GetBloodType())
	{
		BloodType = Olive::OlivePlayer->GetBloodType();
		switch (BloodType)
		{
		case BloodType::Null:
			break;
		case BloodType::A:
			BloodTypeRender->SetText("A", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case BloodType::B:
			BloodTypeRender->SetText("B", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case BloodType::O:
			BloodTypeRender->SetText("O", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case BloodType::AB:
			BloodTypeRender->SetText("AB", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		default:
			break;
		}
	}

	if (Age != Olive::OlivePlayer->GetOliveAge())
	{
		Age = Olive::OlivePlayer->GetOliveAge();
		AgeRender->SetText(std::to_string(Age), TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
	}

	if (BirthDay != Olive::OlivePlayer->GetOliveBirthDay())
	{
		BirthDay = Olive::OlivePlayer->GetOliveBirthDay();
		BirthDayRender->SetText(std::to_string(BirthDay.GetYear()) + std::string("/") + std::to_string(BirthDay.GetMonth()) + std::string("/") + std::to_string(BirthDay.GetDay()), TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
	}

	if (OliveZodiac != Olive::OlivePlayer->GetOliveZodiac())
	{
		OliveZodiac = Olive::OlivePlayer->GetOliveZodiac();
		switch (OliveZodiac)
		{
		case Zodiac::Null:
			break;
		case Zodiac::염소자리:
			ZodiacRender->SetText("염소자리", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case Zodiac::물병자리:
			ZodiacRender->SetText("물병자리", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case Zodiac::물고기자리:
			ZodiacRender->SetText("물고기자리", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case Zodiac::양자리:
			ZodiacRender->SetText("양자리", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case Zodiac::황소자리:
			ZodiacRender->SetText("황소자리", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case Zodiac::쌍둥이자리:
			ZodiacRender->SetText("쌍둥이자리", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case Zodiac::게자리:
			ZodiacRender->SetText("게자리", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case Zodiac::사자자리:
			ZodiacRender->SetText("사자자리", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case Zodiac::처녀자리:
			ZodiacRender->SetText("처녀자리", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case Zodiac::천칭자리:
			ZodiacRender->SetText("천칭자리", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case Zodiac::전갈자리:
			ZodiacRender->SetText("전갈자리", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case Zodiac::사수자리:
			ZodiacRender->SetText("사수자리", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		default:
			break;
		}
	}

	if (OlivePatronGod != Olive::OlivePlayer->GetPatronGod())
	{
		OlivePatronGod = Olive::OlivePlayer->GetPatronGod();
		switch (OlivePatronGod)
		{
		case PatronGod::Null:
			break;
		case PatronGod::태양신_솔:
			PatronGodRender->SetText("태양신", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case PatronGod::달신_더문:
			PatronGodRender->SetText("달신", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case PatronGod::화성신_마르스:
			PatronGodRender->SetText("화성신", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case PatronGod::수성신_머큐리:
			PatronGodRender->SetText("수성신", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case PatronGod::목성신_주피터:
			PatronGodRender->SetText("목성신", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case PatronGod::금성신_비너스:
			PatronGodRender->SetText("금성신", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case PatronGod::토성신_새턴:
			PatronGodRender->SetText("토성신", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case PatronGod::천왕성신_우라누스:
			PatronGodRender->SetText("천왕성신", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case PatronGod::해왕성신_넵튠:
			PatronGodRender->SetText("해왕성신", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case PatronGod::명왕성신_하데스:
			PatronGodRender->SetText("명왕성신", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		default:
			break;
		}
	}
}
