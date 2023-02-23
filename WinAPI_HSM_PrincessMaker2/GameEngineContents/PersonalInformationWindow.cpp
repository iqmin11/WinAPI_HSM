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
	interface_FirstName->SetText("�̸�", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
	interface_FirstName->SetPosition(interface_FirstNamePos);

	interface_LastName = CreateRender(PM2RenderOrder::Menu1_Display);
	interface_LastName->SetText("��", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
	interface_LastName->SetPosition(interface_LastNamePos);

	interface_BloodType = CreateRender(PM2RenderOrder::Menu1_Display);
	interface_BloodType->SetText("������", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
	interface_BloodType->SetPosition(interface_BloodTypePos);
	
	interface_Age = CreateRender(PM2RenderOrder::Menu1_Display);
	interface_Age->SetText("����", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
	interface_Age->SetPosition(interface_AgePos);
	
	interface_BirthDay = CreateRender(PM2RenderOrder::Menu1_Display);
	interface_BirthDay->SetText("����", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
	interface_BirthDay->SetPosition(interface_BirthDayPos);
	
	interface_Zodiac = CreateRender(PM2RenderOrder::Menu1_Display);
	interface_Zodiac->SetText("���ڸ�", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
	interface_Zodiac->SetPosition(interface_ZodiacPos);
	
	interface_PatronGod = CreateRender(PM2RenderOrder::Menu1_Display);
	interface_PatronGod->SetText("��ȣ��", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
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
		case Zodiac::�����ڸ�:
			ZodiacRender->SetText("�����ڸ�", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case Zodiac::�����ڸ�:
			ZodiacRender->SetText("�����ڸ�", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case Zodiac::������ڸ�:
			ZodiacRender->SetText("������ڸ�", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case Zodiac::���ڸ�:
			ZodiacRender->SetText("���ڸ�", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case Zodiac::Ȳ���ڸ�:
			ZodiacRender->SetText("Ȳ���ڸ�", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case Zodiac::�ֵ����ڸ�:
			ZodiacRender->SetText("�ֵ����ڸ�", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case Zodiac::���ڸ�:
			ZodiacRender->SetText("���ڸ�", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case Zodiac::�����ڸ�:
			ZodiacRender->SetText("�����ڸ�", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case Zodiac::ó���ڸ�:
			ZodiacRender->SetText("ó���ڸ�", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case Zodiac::õĪ�ڸ�:
			ZodiacRender->SetText("õĪ�ڸ�", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case Zodiac::�����ڸ�:
			ZodiacRender->SetText("�����ڸ�", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case Zodiac::����ڸ�:
			ZodiacRender->SetText("����ڸ�", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
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
		case PatronGod::�¾��_��:
			PatronGodRender->SetText("�¾��", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case PatronGod::�޽�_����:
			PatronGodRender->SetText("�޽�", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case PatronGod::ȭ����_������:
			PatronGodRender->SetText("ȭ����", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case PatronGod::������_��ť��:
			PatronGodRender->SetText("������", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case PatronGod::�񼺽�_������:
			PatronGodRender->SetText("�񼺽�", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case PatronGod::�ݼ���_��ʽ�:
			PatronGodRender->SetText("�ݼ���", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case PatronGod::�伺��_����:
			PatronGodRender->SetText("�伺��", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case PatronGod::õ�ռ���_��󴩽�:
			PatronGodRender->SetText("õ�ռ���", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case PatronGod::�ؿռ���_��ƪ:
			PatronGodRender->SetText("�ؿռ���", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		case PatronGod::��ռ���_�ϵ���:
			PatronGodRender->SetText("��ռ���", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
			break;
		default:
			break;
		}
	}
}
