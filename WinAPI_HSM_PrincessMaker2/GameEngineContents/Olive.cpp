#include "Olive.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnums.h"

Olive* Olive::OlivePlayer;

Olive::Olive()
{

}

Olive::~Olive()
{

}

void Olive::SetFirstStatus()
{
	if (Zodiac::염소자리 == OliveZodiac)
	{
		Olive::Status Capricorn = { 25, 20, 17, 15, 10, 38, 20, 0, 13, 0, 17, 15, 2, 0, 28, 15, 8, 5, 41, 20, 10, 11, 69, 19, 22, 28 };
		SetStatus(Capricorn);
	}
	else if (Zodiac::물병자리 == OliveZodiac)
	{
		Olive::Status Aquarius = { 17,18,42,12,10,13,8,0,28,0,17,15,2,0,50,15,12,23,55,11,22,22,44,15,23,6 };
		SetStatus(Aquarius);
	}
	else if (Zodiac::물고기자리 == OliveZodiac)
	{
		Olive::Status Pisces = { 16,15,15,32,31,27,30,0,45,0,12,10,2,0,56,18,20,18,59,24,20,15,48,16,14,18 };
		SetStatus(Pisces);
	}
	else if (Zodiac::양자리 == OliveZodiac)
	{
		Olive::Status Aries = { 45,45,13,10,7,14,21,0,6,0,43,38,5,0,32,8,14,10,35,10,15,10,40,18,18,4 };
		SetStatus(Aries);
	}
	else if (Zodiac::황소자리 == OliveZodiac)
	{
		Olive::Status Taurus = { 33,28,23,25,24,32,20,0,19,0,13,10,3,0,60,17,18,25,49,21,20,8,58,19,16,23 };
		SetStatus(Taurus);
	}
	else if (Zodiac::쌍둥이자리 == OliveZodiac)
	{
		Olive::Status Gemini = { 19,18,36,14,14,7,10,0,35,0,16,14,2,0,52,18,19,15,65,10,25,30,29,8,10,11 };
		SetStatus(Gemini);
	}
	else if (Zodiac::게자리 == OliveZodiac)
	{
		Olive::Status Cancer = { 18,18,25,29,33,25,30,0,33,0,17,15,2,0,75,24,28,23,57,17,20,20,54,17,20,17 };
		SetStatus(Cancer);
	}
	else if (Zodiac::사자자리 == OliveZodiac)
	{
		Olive::Status Leo = { 50,50,7,42,18,23,10,0,9,0,37,32,5,0,16,2,6,8,38,15,8,15,18,7,9,2 };
		SetStatus(Leo);
	}
	else if (Zodiac::처녀자리 == OliveZodiac)
	{
		Olive::Status Virgo = { 14,5,28,45,30,32,35,0,31,0,8,7,1,0,65,15,18,32,58,25,18,15,89,29,30,30 };
		SetStatus(Virgo);
	}
	else if (Zodiac::천칭자리 == OliveZodiac)
	{
		Olive::Status Libra = { 25,22,30,24,20,20,21,0,26,0,16,14,2,0,42,13,14,15,64,18,18,28,46,16,15,15 };
		SetStatus(Libra);
	}
	else if (Zodiac::전갈자리 == OliveZodiac)
	{
		Olive::Status Scorpio = { 28,20,22,9,42,10,27,0,39,0,12,10,2,0,80,30,30,20,39,14,21,4,31,12,11,8 };
		SetStatus(Scorpio);
	}
	else if (Zodiac::사수자리 == OliveZodiac)
	{
		Olive::Status Sagittarius = { 38,35,24,23,11,10,12,0,20,0,23,19,4,0,43,19,12,12,37,8,6,13,44,21,13,10 };
		SetStatus(Sagittarius);
	}
	else
	{
		MsgAssert("별자리가 없습니다, 생일을 정해주지 않았습니다.");
	}
}

void Olive::SetStatus(Status _Value)
{
	SetConstitution(_Value.Constitution);
	SetStrength(_Value.Strength);
	SetIntelligence(_Value.Intelligence);
	SetRefinement(_Value.Refinement);
	SetCharisma(_Value.Charisma);
	SetMorality(_Value.Morality);
	SetFaith(_Value.Faith);
	SetSin(_Value.Sin);
	SetSensitivity(_Value.Sensitivity);
	SetStress(_Value.Stress);
	
	SetCombatSkill(_Value.CombatSkill);
	SetCombatAttack(_Value.CombatAttack);
	SetCombatDefense(_Value.CombatDefense);
	UpdateFighter();

	SetMagicSkill(_Value.MagicSkill);
	SetMagicAttack(_Value.MagicAttack);
	SetMagicDefense(_Value.MagicDefense);
	UpdateMagical();
	
	SetDecorum(_Value.Decorum);
	SetArt(_Value.Art);
	SetConversation(_Value.Conversation);
	UpdateSocial();
	
	SetCooking(_Value.Cooking);
	SetCleaning(_Value.Cleaning);
	SetTemperament(_Value.Temperament);
	UpdateHouseWork();
}

void Olive::UpdateZodiac()
{

	if (OliveBirthDay >= Date{1200, 12, 22} ||
		OliveBirthDay <= Date{ 1200, 12, 31 } ||
		OliveBirthDay >= Date{ 1200, 1, 1 } ||
		OliveBirthDay <= Date{ 1200, 1, 19 })
	{
		OliveZodiac = Zodiac::염소자리;
		OlivePatronGod = PatronGod::토성신_새턴;
		PatronGodSex = 1;
	}
	else if (OliveBirthDay >= Date{ 1200, 1, 20 } ||
		OliveBirthDay <= Date{ 1200, 2, 18 })
	{
		OliveZodiac = Zodiac::물병자리;
		OlivePatronGod = PatronGod::천왕성신_우라누스;
		PatronGodSex = 1;
	}
	else if (OliveBirthDay >= Date{ 1200, 2, 19 } ||
		OliveBirthDay <= Date{ 1200, 3, 20 })
	{
		OliveZodiac = Zodiac::물고기자리;
		OlivePatronGod = PatronGod::해왕성신_넵튠;
		PatronGodSex = 1;
	}
	else if (OliveBirthDay >= Date{ 1200, 3, 21 } ||
		OliveBirthDay <= Date{ 1200, 4, 19 })
	{
		OliveZodiac = Zodiac::양자리;
		OlivePatronGod = PatronGod::화성신_마스;
		PatronGodSex = 0;
	}
	else if (OliveBirthDay >= Date{ 1200, 4, 20 } ||
		OliveBirthDay <= Date{ 1200, 5, 20 })
	{
		OliveZodiac = Zodiac::황소자리;
		OlivePatronGod = PatronGod::금성신_비너스;
		PatronGodSex = 1;
	}
	else if (OliveBirthDay >= Date{ 1200, 5, 21 } ||
		OliveBirthDay <= Date{ 1200, 6, 21 })
	{
		OliveZodiac = Zodiac::쌍둥이자리;
		OlivePatronGod = PatronGod::수성신_머큐리;
		PatronGodSex = 1;
	}
	else if (OliveBirthDay >= Date{ 1200, 6, 22 } ||
		OliveBirthDay <= Date{ 1200, 7, 22 })
	{
		OliveZodiac = Zodiac::게자리;
		OlivePatronGod = PatronGod::달신_더문;
		PatronGodSex = 1;
	}
	else if (OliveBirthDay >= Date{ 1200, 7, 23 } ||
		OliveBirthDay <= Date{ 1200, 8, 22 })
	{
		OliveZodiac = Zodiac::사자자리;
		OlivePatronGod = PatronGod::태양신_솔;
		PatronGodSex = 0;
	}
	else if (OliveBirthDay >= Date{ 1200, 8, 23 } ||
		OliveBirthDay <= Date{ 1200, 9, 22 })
	{
		OliveZodiac = Zodiac::처녀자리;
		OlivePatronGod = PatronGod::수성신_머큐리;
		PatronGodSex = 1;
	}
	else if (OliveBirthDay >= Date{ 1200, 9, 23 } ||
		OliveBirthDay <= Date{ 1200, 10, 23 })
	{
		OliveZodiac = Zodiac::천칭자리;
		OlivePatronGod = PatronGod::금성신_비너스;
		PatronGodSex = 1;
	}
	else if (OliveBirthDay >= Date{ 1200, 10, 24 } ||
		OliveBirthDay <= Date{ 1200, 11, 22 })
	{
		OliveZodiac = Zodiac::전갈자리;
		OlivePatronGod = PatronGod::명왕성신_하데스;
		PatronGodSex = 0;
	}
	else if (OliveBirthDay >= Date{ 1200, 11, 23 } ||
		OliveBirthDay <= Date{ 1200, 12, 21 })
	{
		OliveZodiac = Zodiac::사수자리;
		OlivePatronGod = PatronGod::목성신_주피터;
		PatronGodSex = 0;
	}
	else
	{
		MsgAssert("생일을 정해주지 않았습니다.");
	}
}


void Olive::Start()
{
	OlivePlayer = this;

	SetPos(GameEngineWindow::GetScreenSize().half());
	BodyRender = CreateRender("body_10_nomal.BMP", PM2RenderOrder::Olive); 
	BodyRender->SetScaleToImage();
	SetMove(float4::Down * ((GameEngineWindow::GetScreenSize().half()) - (BodyRender->GetImage()->GetImageScale().half())));
	HeadRender = CreateRender("head_10_nomal.BMP", PM2RenderOrder::Olive);
	HeadRender->SetScaleToImage();
	HeadRender->SetPosition(float4::Up * ((BodyRender->GetImage()->GetImageScale().half()) + (HeadRender->GetImage()->GetImageScale().half())));

	Off();
}

void Olive::Update(float _DeltaTime)
{
	/*if (true == GameEngineInput::IsPress("LeftMove"))
	{
		SetMove(float4::Left * MoveSpeed * _DeltaTime);
	}

	if (true == GameEngineInput::IsPress("RightMove"))
	{
		SetMove(float4::Right * MoveSpeed * _DeltaTime);
	}

	if (true == GameEngineInput::IsPress("UpMove"))
	{
		SetMove(float4::Up * MoveSpeed * _DeltaTime);
	}

	if (true == GameEngineInput::IsPress("DownMove"))
	{
		SetMove(float4::Down * MoveSpeed * _DeltaTime);
	}*/
}

void Olive::Render(float _Time)
{
	/*HDC DoubleDC = GameEngineWindow::GetDoubleBufferImage()->GetImageDC();
	float4 ActorPos = GetPos();

	Rectangle(DoubleDC,
		ActorPos.ix() - 5,
		ActorPos.iy() - 5,
		ActorPos.ix() + 5,
		ActorPos.iy() + 5
	);*/ // 디버깅용
}
