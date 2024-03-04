#include "Olive.h"

#include <GameEngineBase/GameEngineRandom.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include "RaisingSimLevel.h"

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

void Olive::SetFirstPhysicalCondition()
{
	GameEngineRandom Random = GameEngineRandom();
	int RandomNum = Random.RandomInt(0,16);
	float fHeight = 136.0f + 1.0f * static_cast<float>(RandomNum);
	float fWeight = 29.2f + 0.95f * static_cast<float>(RandomNum);
	float fBust = 68.0f + 0.5f * static_cast<float>(RandomNum);
	float fWaist = 47.5f + 0.625f * static_cast<float>(RandomNum);
	float fHip = 70.72f + 0.52f * static_cast<float>(RandomNum);

	SetHeight(fHeight);
	SetWeight(fWeight);
	SetBust(fBust);
	SetWaist(fWaist);
	SetHip(fHip);
}

void Olive::SetStatus(const Status& _Value)
{
	OliveStatus.Constitution = _Value.Constitution;
	OliveStatus.Strength = _Value.Strength;
	OliveStatus.Intelligence = _Value.Intelligence;
	OliveStatus.Refinement = _Value.Refinement;
	OliveStatus.Charisma = _Value.Charisma;
	OliveStatus.Morality = _Value.Morality;
	OliveStatus.Faith = _Value.Faith;
	OliveStatus.Sin = _Value.Sin;
	OliveStatus.Sensitivity = _Value.Sensitivity;
	OliveStatus.Stress = _Value.Stress;
	
	OliveStatus.CombatSkill = _Value.CombatSkill;
	OliveStatus.CombatAttack = _Value.CombatAttack;
	OliveStatus.CombatDefense = _Value.CombatDefense;
	UpdateFighter();

	OliveStatus.MagicSkill = _Value.MagicSkill;
	OliveStatus.MagicAttack = _Value.MagicAttack;
	OliveStatus.MagicDefense = _Value.MagicDefense;
	UpdateMagical();
	
	OliveStatus.Decorum = _Value.Decorum;
	OliveStatus.Art = _Value.Art;
	OliveStatus.Conversation = _Value.Conversation;
	UpdateSocial();
	
	OliveStatus.Cooking = _Value.Cooking;
	OliveStatus.Cleaning = _Value.Cleaning;
	OliveStatus.Temperament = _Value.Temperament;
	UpdateHouseWork();
}

void Olive::UpdateZodiac()
{

	if ((OliveBirthDay >= Date{1200, 12, 22} &&
		OliveBirthDay <= Date{ 1200, 12, 31 }) ||
		(OliveBirthDay >= Date{ 1200, 1, 1 } &&
		OliveBirthDay <= Date{ 1200, 1, 19 }))
	{
		OliveZodiac = Zodiac::염소자리;
		OlivePatronGod = PatronGod::토성신_새턴;
		PatronGodSex = 1;
	}
	else if (OliveBirthDay >= Date{ 1200, 1, 20 } &&
		OliveBirthDay <= Date{ 1200, 2, 18 })
	{
		OliveZodiac = Zodiac::물병자리;
		OlivePatronGod = PatronGod::천왕성신_우라누스;
		PatronGodSex = 1;
	}
	else if (OliveBirthDay >= Date{ 1200, 2, 19 } &&
		OliveBirthDay <= Date{ 1200, 3, 20 })
	{
		OliveZodiac = Zodiac::물고기자리;
		OlivePatronGod = PatronGod::해왕성신_넵튠;
		PatronGodSex = 1;
	}
	else if (OliveBirthDay >= Date{ 1200, 3, 21 } &&
		OliveBirthDay <= Date{ 1200, 4, 19 })
	{
		OliveZodiac = Zodiac::양자리;
		OlivePatronGod = PatronGod::화성신_마르스;
		PatronGodSex = 0;
	}
	else if (OliveBirthDay >= Date{ 1200, 4, 20 } &&
		OliveBirthDay <= Date{ 1200, 5, 20 })
	{
		OliveZodiac = Zodiac::황소자리;
		OlivePatronGod = PatronGod::금성신_비너스;
		PatronGodSex = 1;
	}
	else if (OliveBirthDay >= Date{ 1200, 5, 21 } &&
		OliveBirthDay <= Date{ 1200, 6, 21 })
	{
		OliveZodiac = Zodiac::쌍둥이자리;
		OlivePatronGod = PatronGod::수성신_머큐리;
		PatronGodSex = 1;
	}
	else if (OliveBirthDay >= Date{ 1200, 6, 22 } &&
		OliveBirthDay <= Date{ 1200, 7, 22 })
	{
		OliveZodiac = Zodiac::게자리;
		OlivePatronGod = PatronGod::달신_더문;
		PatronGodSex = 1;
	}
	else if (OliveBirthDay >= Date{ 1200, 7, 23 } &&
		OliveBirthDay <= Date{ 1200, 8, 22 })
	{
		OliveZodiac = Zodiac::사자자리;
		OlivePatronGod = PatronGod::태양신_솔;
		PatronGodSex = 0;
	}
	else if (OliveBirthDay >= Date{ 1200, 8, 23 } &&
		OliveBirthDay <= Date{ 1200, 9, 22 })
	{
		OliveZodiac = Zodiac::처녀자리;
		OlivePatronGod = PatronGod::수성신_머큐리;
		PatronGodSex = 1;
	}
	else if (OliveBirthDay >= Date{ 1200, 9, 23 } &&
		OliveBirthDay <= Date{ 1200, 10, 23 })
	{
		OliveZodiac = Zodiac::천칭자리;
		OlivePatronGod = PatronGod::금성신_비너스;
		PatronGodSex = 1;
	}
	else if (OliveBirthDay >= Date{ 1200, 10, 24 } &&
		OliveBirthDay <= Date{ 1200, 11, 22 })
	{
		OliveZodiac = Zodiac::전갈자리;
		OlivePatronGod = PatronGod::명왕성신_하데스;
		PatronGodSex = 0;
	}
	else if (OliveBirthDay >= Date{ 1200, 11, 23 } &&
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
	ParentLevel = dynamic_cast<RaisingSimLevel*>(GetLevel());
	
	OlivePlayer = this;

	SetPos(GameEngineWindow::GetScreenSize().half());
	BodyRender = CreateRender("Body_10_Common.BMP", PM2RenderOrder::Olive); 
	BodyRender->SetScaleToImage();
	HeadRender = CreateRender("Head_10_Nomal_Common.BMP", PM2RenderOrder::Olive);
	HeadRender->SetScaleToImage();
	BodyRender->SetPosition({ 0,300 - BodyRender->GetScale().hy()});
	HeadRender->SetPosition({ 0,300 - HeadRender->GetScale().hy() - BodyRender->GetScale().y});
	
	Off();
}

void Olive::Update(float _DeltaTime)
{
	OliveStatus.UpdateMoreThanMin();
	OliveStatus.UpdateLessThanMax();
	UpdateMonthChange();

	UpdateFighter();
	UpdateMagical();
	UpdateSocial();
	UpdateHouseWork();

	OliveBirthDayCheck();

}

void Olive::Render(float _Time)
{
	
}

void Olive::UpdateMonthChange()
{
	if (ParentLevel->GetToday() == Date::GetMonthLastDate(ParentLevel->GetToday()) && MonthChange == false)
	{
		MonthChange = true;
		BloodTypeMonthUpdate();
		DietMonthUpdate();
		OliveStateUpdate();
		OliveRenderUpdate();
	}
	
	if (ParentLevel->GetToday().GetDay() == 1 && MonthChange == true)
	{
		MonthChange = false;
	}
}

void Olive::BloodTypeMonthUpdate()
{
	switch (OliveBloodType)
	{
	case BloodType::Null:
		break;
	case BloodType::A:
		OliveStatus.Morality += 3;
		OliveStatus.Stress += 2;
		break;
	case BloodType::B:
		OliveStatus.Stress -= 2;
		break;
	case BloodType::O:
		break;
	case BloodType::AB:
		OliveStatus.Sensitivity += 2;
		break;
	default:
		break;
	}
}

void Olive::DietMonthUpdate()
{
	GameEngineRandom Random = GameEngineRandom();
	switch (OliveDiet)
	{
	case Diet::Null:
		break;
	case Diet::무리하지_않는다:
		if (OliveAge <= 15)
		{
			OlivePhysical.Weight += Random.RandomFloat(0.19f, 0.22f);
		}
		else if (OliveAge > 15)
		{
			OlivePhysical.Weight += Random.RandomFloat(0.05f, 0.08f);
		}
		break;
	case Diet::어쨌든_튼튼하게:
		if (OliveAge <= 15)
		{
			OlivePhysical.Weight += Random.RandomFloat(0.28f, 0.35f);
		}
		else if (OliveAge > 15)
		{
			OlivePhysical.Weight += Random.RandomFloat(0.16f, 0.20f);
		}
		OliveStatus.Constitution += 10;
		break;
	case Diet::얌전한_아이로:
		if (OliveAge <= 15)
		{
			OlivePhysical.Weight += Random.RandomFloat(0.10f, 0.13f);
		}
		else if (OliveAge > 15)
		{
			OlivePhysical.Weight += Random.RandomFloat(0.01f, 0.04f);
		}
		OliveStatus.Constitution += -5;
		break;
	case Diet::다이어트_시킨다:
		if (OliveAge <= 15)
		{
			OlivePhysical.Weight += Random.RandomFloat(-0.6f, -0.0f);
		}
		else if (OliveAge > 15)
		{
			OlivePhysical.Weight += Random.RandomFloat(-1.00f, -0.5f);
		}
		OliveStatus.Constitution += -20; 
		break;
	default:
		break;
	}
}

void Olive::OliveStateUpdate()
{
	UpdateFat();
	UpdateDisease();
	UpdateDelinquent();
}

bool Olive::UpdateFat()
{
	if (OlivePhysical.Weight > OlivePhysical.Height * 0.95 - 87 - OliveAge)
	{
		FatState = true;
		return FatState;
	}
	else
	{
		FatState = false;
		return FatState;
	}
}

bool Olive::UpdateDisease()
{
	if (OliveStatus.Stress > OliveStatus.Constitution)
	{
		DiseaseState = true;
		return DiseaseState;
	}
	else
	{
		DiseaseState = false;
		return DiseaseState;
	}
}

bool Olive::UpdateDelinquent()
{
	if (OliveStatus.Stress > OliveStatus.Morality || OliveStatus.Stress > OliveStatus.Faith)
	{
		DelinquentState = true;
		return DelinquentState;
	}
	else
	{
		DelinquentState = false;
		return DelinquentState;
	}
}

void Olive::OliveRenderUpdate()
{
	int AgeCopy = OliveAge;

	if (OliveAge >= 18)
	{
		AgeCopy = 17;
	}

	HeadImageName += std::to_string(AgeCopy);
	if (DiseaseState)
	{
		HeadImageName += "_Sick";
	}
	else if (DelinquentState)
	{
		HeadImageName += "_Degrade";
	}
	else if (OliveStatus.Stress == 0)
	{
		HeadImageName += "_Happy";
	}
	else
	{
		HeadImageName += "_Nomal";
	}

	if (!FatState)
	{
		HeadImageName += "_Common";
	}
	else
	{
		HeadImageName += "_Fat";
	}

	HeadImageName += ".bmp";
	HeadRender->SetImage(HeadImageName);
	HeadRender->SetScaleToImage();
	HeadImageName = "Head_";

	BodyImageName += std::to_string(AgeCopy);
	if (!FatState)
	{
		BodyImageName += "_Common";
	}
	else
	{
		BodyImageName += "_Fat";
	}
	
	BodyImageName += ".bmp";
	BodyRender->SetImage(BodyImageName);
	BodyRender->SetScaleToImage();
	BodyImageName = "Body_";

	BodyRender->SetPosition({ 0,300 - BodyRender->GetScale().hy() });
	HeadRender->SetPosition({ 0,300 - HeadRender->GetScale().hy() - BodyRender->GetScale().y });
}

void Olive::OliveBirthDayCheck()
{
	
	if (IsBirthDay == false && ParentLevel->GetToday().GetYear() != 1210 && ParentLevel->GetToday().GetMonth() == OliveBirthDay.GetMonth() && ParentLevel->GetToday().GetDay() == OliveBirthDay.GetDay())
	{
		OliveAge++;
		IsBirthDay = true;
		OliveRenderUpdate();
	}

	if (IsBirthDay == true && ParentLevel->GetToday().GetMonth() != OliveBirthDay.GetMonth() || ParentLevel->GetToday().GetDay() != OliveBirthDay.GetDay())
	{
		IsBirthDay = false;
	}
}


bool Olive::IsFat()
{
	return FatState;
}

bool Olive::IsDisease()
{
	return DiseaseState;
}

bool Olive::IsDelinquent()
{
	return DelinquentState;
}

Olive::Status& Olive::Status::operator+=(const Status& _Value)
{
	Constitution += _Value.Constitution;
	Strength += _Value.Strength;
	Intelligence += _Value.Intelligence;
	Refinement += _Value.Refinement;
	Charisma += _Value.Charisma;
	Morality += _Value.Morality;
	Faith += _Value.Faith;
	Sin += _Value.Sin;
	Sensitivity += _Value.Sensitivity;
	Stress += _Value.Stress;
	Fighter += _Value.Fighter;
	CombatSkill += _Value.CombatSkill;
	CombatAttack += _Value.CombatAttack;
	CombatDefense += _Value.CombatDefense;
	Magical += _Value.Magical;
	MagicSkill += _Value.MagicSkill;
	MagicAttack += _Value.MagicAttack;
	MagicDefense += _Value.MagicDefense;
	Social += _Value.Social;
	Decorum += _Value.Decorum;
	Art += _Value.Art;
	Conversation += _Value.Conversation;
	HouseWork += _Value.HouseWork;
	Cooking += _Value.Cooking;
	Cleaning += _Value.Cleaning;
	Temperament += _Value.Temperament;

	return *this;
}

bool Olive::Status::operator==(const Status& _Value)
{
	if (
		Constitution == _Value.Constitution &&
		Strength == _Value.Strength &&
		Intelligence == _Value.Intelligence &&
		Refinement == _Value.Refinement &&
		Charisma == _Value.Charisma &&
		Morality == _Value.Morality &&
		Faith == _Value.Faith &&
		Sin == _Value.Sin &&
		Sensitivity == _Value.Sensitivity &&
		Stress == _Value.Stress &&
		Fighter == _Value.Fighter &&
		CombatSkill == _Value.CombatSkill &&
		CombatAttack == _Value.CombatAttack &&
		CombatDefense == _Value.CombatDefense &&
		Magical == _Value.Magical &&
		MagicSkill == _Value.MagicSkill &&
		MagicAttack == _Value.MagicAttack &&
		MagicDefense == _Value.MagicDefense &&
		Social == _Value.Social &&
		Decorum == _Value.Decorum &&
		Art == _Value.Art &&
		Conversation == _Value.Conversation &&
		HouseWork == _Value.HouseWork &&
		Cooking == _Value.Cooking &&
		Cleaning == _Value.Cleaning &&
		Temperament == _Value.Temperament
		)
	{
		return true;
	}
	return false;
}

bool Olive::Status::operator!=(const Status& _Value)
{
	return !Status::operator==(_Value);
}

Olive::Status& Olive::Status::operator=(const Status& _Value)
{
	Constitution  = _Value.Constitution;
	Strength      = _Value.Strength;
	Intelligence  = _Value.Intelligence;
	Refinement    = _Value.Refinement;
	Charisma      = _Value.Charisma;
	Morality      = _Value.Morality;
	Faith         = _Value.Faith;
	Sin           = _Value.Sin;
	Sensitivity   = _Value.Sensitivity;
	Stress        = _Value.Stress;

	Fighter       = _Value.Fighter;
	CombatSkill   = _Value.CombatSkill;
	CombatAttack  = _Value.CombatAttack;
	CombatDefense = _Value.CombatDefense;

	Magical       = _Value.Magical;
	MagicSkill    = _Value.MagicSkill;
	MagicAttack   = _Value.MagicAttack;
	MagicDefense  = _Value.MagicDefense;

	Social        = _Value.Social;
	Decorum       = _Value.Decorum;
	Art           = _Value.Art;
	Conversation  = _Value.Conversation;

	HouseWork     = _Value.HouseWork;
	Cooking       = _Value.Cooking;
	Cleaning      = _Value.Cleaning;
	Temperament   = _Value.Temperament;

	return *this;
}

void Olive::Status::SetStatus(const Status& _Para)
{
	Constitution = _Para.Constitution;
	Strength = _Para.Strength;
	Intelligence = _Para.Intelligence;
	Refinement = _Para.Refinement;
	Charisma = _Para.Charisma;
	Morality = _Para.Morality;
	Faith = _Para.Faith;
	Sin = _Para.Sin;
	Sensitivity = _Para.Sensitivity;
	Stress = _Para.Stress;
	Fighter = _Para.Fighter;
	CombatSkill = _Para.CombatSkill;
	CombatAttack = _Para.CombatAttack;
	CombatDefense = _Para.CombatDefense;
	Magical = _Para.Magical;
	MagicSkill = _Para.MagicSkill;
	MagicAttack = _Para.MagicAttack;
	MagicDefense = _Para.MagicDefense;
	Social = _Para.Social;
	Decorum = _Para.Decorum;
	Art = _Para.Art;
	Conversation = _Para.Conversation;
	HouseWork = _Para.HouseWork;
	Cooking = _Para.Cooking;
	Cleaning = _Para.Cleaning;
	Temperament = _Para.Temperament;
}

void Olive::Status::UpdateMoreThanMin()
{
	if (Constitution < 0)
	{
		Constitution = 0;
	}
	
	if (Strength < 0)
	{
		Strength = 0;
	}

	if (Intelligence < 0)
	{
		Intelligence = 0;
	}

	if (Refinement < 0)
	{
		Refinement = 0;
	}

	if (Charisma < 0)
	{
		Charisma = 0;
	}

	if (Morality < 0)
	{
		Morality = 0;
	}

	if (Faith < 0)
	{
		Faith = 0;
	}

	if (Sin < 0)
	{
		Sin = 0;
	}

	if (Sensitivity < 0)
	{
		Sensitivity = 0;
	}

	if (Stress < 0)
	{
		Stress = 0;
	}

	if (CombatSkill < 0)
	{
		CombatSkill = 0;
	}

	if (CombatAttack < 0)
	{
		CombatAttack = 0;
	}

	if (CombatDefense < 0)
	{
		CombatDefense = 0;
	}

	if (MagicSkill < 0)
	{
		MagicSkill = 0;
	}

	if (MagicAttack < 0)
	{
		MagicAttack = 0;
	}

	if (MagicDefense < 0)
	{
		MagicDefense = 0;
	}

	if (Decorum < 0)
	{
		Decorum = 0;
	}

	if (Art < 0)
	{
		Art = 0;
	}

	if (Conversation < 0)
	{
		Conversation = 0;
	}

	if (Cooking < 0)
	{
		Cooking = 0;
	}

	if (Cleaning < 0)
	{
		Cleaning = 0;
	}

	if (Temperament < 0)
	{
		Temperament = 0;
	}
}

void Olive::Status::UpdateLessThanMax()
{
	if (Constitution > 999)
	{
		Constitution = 999;
	}

	if (Strength > 999)
	{
		Strength = 999;
	}

	if (Intelligence > 999)
	{
		Intelligence = 999;
	}

	if (Refinement > 999)
	{
		Refinement = 999;
	}

	if (Charisma > 999)
	{
		Charisma = 999;
	}

	if (Morality > 999)
	{
		Morality = 999;
	}

	if (Faith > 999)
	{
		Faith = 999;
	}

	if (Sin > 999)
	{
		Sin = 999;
	}

	if (Sensitivity > 999)
	{
		Sensitivity = 999;
	}

	if (Stress > 999)
	{
		Stress = 999;
	}

	if (CombatSkill > 100)
	{
		CombatSkill = 100;
	}

	if (CombatAttack > 100)
	{
		CombatAttack = 100;
	}

	if (CombatDefense > 100)
	{
		CombatDefense = 100;
	}

	if (MagicSkill > 100)
	{
		MagicSkill = 100;
	}

	if (MagicAttack > 100)
	{
		MagicAttack = 100;
	}

	if (MagicDefense > 100)
	{
		MagicDefense = 100;
	}

	if (Decorum > 100)
	{
		Decorum = 100;
	}

	if (Art > 100)
	{
		Art = 100;
	}

	if (Conversation > 100)
	{
		Conversation = 100;
	}

	if (Cooking > 100)
	{
		Cooking = 100;
	}

	if (Cleaning > 100)
	{
		Cleaning = 100;
	}

	if (Temperament > 100)
	{
		Temperament = 100;
	}
}
