#pragma once
#include <string>
#include "MenuFrame.h"
#include "Date.h"

class GameEngineRender;
class PersonalInformationWindow : public MenuFrame
{
public:
	// construtor destructor
	PersonalInformationWindow();
	~PersonalInformationWindow();

	// delete Function
	PersonalInformationWindow(const PersonalInformationWindow& _Other) = delete;
	PersonalInformationWindow(PersonalInformationWindow&& _Other) noexcept = delete;
	PersonalInformationWindow& operator=(const PersonalInformationWindow& _Other) = delete;
	PersonalInformationWindow& operator=(PersonalInformationWindow&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override; 

private:
	float4 Scale = { 260, 184 };
	float4 ActorPos = { 154, 195 };

	std::string FirstName = std::string();
	std::string LastName = std::string();
	BloodType BloodType = BloodType::Null;
	int Age = 0;
	Date BirthDay = Date();
	Zodiac OliveZodiac = Zodiac::Null;
	PatronGod OlivePatronGod = PatronGod::Null;
	
	GameEngineRender* interface_FirstName = nullptr;
	GameEngineRender* interface_LastName = nullptr;
	GameEngineRender* interface_BloodType = nullptr;
	GameEngineRender* interface_Age= nullptr;
	GameEngineRender* interface_BirthDay= nullptr;
	GameEngineRender* interface_Zodiac= nullptr;
	GameEngineRender* interface_PatronGod= nullptr;
	float4 interface_FirstNamePos = {-118 , -80};
	float4 interface_LastNamePos = { -118 , -57 };
	float4 interface_BloodTypePos = { -118 , -34 };
	float4 interface_AgePos = { -118 , -11 };
	float4 interface_BirthDayPos = { -118 , 12 };
	float4 interface_ZodiacPos = { -118 , 35 };
	float4 interface_PatronGodPos = { -118 , 58 };

	GameEngineRender* FirstNameRender = nullptr;
	GameEngineRender* LastNameRender = nullptr;
	GameEngineRender* BloodTypeRender = nullptr;
	GameEngineRender* AgeRender = nullptr;
	GameEngineRender* BirthDayRender = nullptr;
	GameEngineRender* ZodiacRender = nullptr;
	GameEngineRender* PatronGodRender = nullptr;
	float4 FirstNamePos = { -38 , -80 };
	float4 LastNamePos = { -38 , -57 };
	float4 BloodTypePos = { -38 , -34 };
	float4 AgePos = { -38 , -11 };
	float4 BirthDayPos = { -38 , 12 };
	float4 ZodiacPos = { -38 , 35 };
	float4 PatronGodPos = { -38 , 58 };

	int TextHeight = 18;
	std::string TextType = "±¼¸²";
	COLORREF TextColor = RGB(255, 255, 255);
	float4 TextBoxScale1 = { 80,20 };
	float4 TextBoxScale2 = { 160,20 };

	void UpdatePersonalInformationWindow();

};

