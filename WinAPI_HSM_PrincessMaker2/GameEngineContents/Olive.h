#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "Date.h"
#include "ContentsEnums.h"

class GameEngineRender;
class Olive : public GameEngineActor
{
private:
	class Status
	{
	public:
		float Constitution = -1;
		float ConstitutionMax = 999;
		float Strength = -1;
		float StrengthMax = 999;
		float Intelligence = -1;
		float IntelligenceMax = 999;
		float Refinement = -1;
		float RefinementMax = 999;
		float Charisma = -1;
		float CharismaMax = 999;
		float Morality = -1;
		float MoralityMax = 999;
		float Faith = -1;
		float FaithMax = 999;
		float Sin = -1;
		float SinMax = 999;
		float Sensitivity = -1;
		float SensitivityMax = 999;
		float Stress = -1;
		float StressMax = 999;

		float Fighter = -1;
		float CombatSkill = -1;
		float CombatAttack = -1;
		float CombatDefense = -1;

		float Magical = -1;
		float MagicSkill = -1;
		float MagicAttack = -1;
		float MagicDefense = -1;

		float Social = -1;
		float Decorum = -1;
		float Art = -1;
		float Conversation = -1;

		float HouseWork = -1;
		float Cooking = -1;
		float Cleaning = -1;
		float Temperament = -1;
	};

	class PhysicalCondition
	{
	public:
		float Height = -1;
		float Weight = -1;
		float Bust = -1;
		float Waist = -1;
		float Hip = -1;
	};

public:
	static Olive* OlivePlayer;

	// construtor destructor
	Olive();
	~Olive();

	// delete Function
	Olive(const Olive& _Other) = delete;
	Olive(Olive&& _Other) noexcept = delete;
	Olive& operator=(const Olive& _Other) = delete;
	Olive& operator=(Olive&& _Other) noexcept = delete;

	Date GetOliveBirthDay() const
	{
		return OliveBirthDay;
	}

	int GetFatherAge() const
	{
		return FatherAge;
	}

	std::string GetOliveFirstName() const
	{
		return OliveFirstName;
	}

	std::string GetOliveLastName() const
	{
		return OliveLastName;
	}

	int GetOliveAge() const
	{
		return OliveAge;
	}

	Zodiac GetOliveZodiac() const
	{
		return OliveZodiac;
	}

	PatronGod GetPatronGod() const
	{
		return OlivePatronGod;
	}

	bool GetPatronGodSex() const
	{
		return PatronGodSex;
	}

	int GetGold() const
	{
		return Gold;
	}

	BloodType GetBloodType() const
	{
		return OliveBloodType;
	}

	void SetOliveFirstName(const std::string_view& _FirstName)
	{
		OliveFirstName = _FirstName;
	}

	void SetOliveLastName(const std::string_view& _LastName)
	{
		OliveLastName = _LastName;
	}

	void SetOliveBirthDay(const Date& _BirthDay)
	{
		OliveBirthDay = _BirthDay;
	}

	void SetFatherAge(const int _Age)
	{
		FatherAge = _Age;
	}

	void SetFatherBirthDay(const Date& _BirthDay)
	{
		FatherBirthDay = _BirthDay;
	}

	void SetBloodType(BloodType _BloodType)
	{
		OliveBloodType = _BloodType;
	}

	/// ////////////////////////////////////////////////////////
	Status GetStatue() const
	{
		return OliveStatus;
	}

	void SetFirstStatus();
	void SetStatus(const Status& _Status);

	void SetConstitution(float _Value)
	{
		OliveStatus.Constitution = _Value;
	}
	void SetStrength(float _Value)
	{
		OliveStatus.Strength = _Value;
	}
	void SetIntelligence(float _Value)
	{
		OliveStatus.Intelligence = _Value;
	}
	void SetRefinement(float _Value)
	{
		OliveStatus.Refinement = _Value;
	}
	void SetCharisma(float _Value)
	{
		OliveStatus.Charisma = _Value;
	}
	void SetMorality(float _Value)
	{
		OliveStatus.Morality = _Value;
	}
	void SetFaith(float _Value)
	{
		OliveStatus.Faith = _Value;
	}
	void SetSin(float _Value)
	{
		OliveStatus.Sin = _Value;
	}
	void SetSensitivity(float _Value)
	{
		OliveStatus.Sensitivity = _Value;
	}
	void SetStress(float _Value)
	{
		OliveStatus.Stress = _Value;
	}
	void SetCombatSkill(float _Value)
	{
		OliveStatus.CombatSkill = _Value;
	}
	void SetCombatAttack(float _Value)
	{
		OliveStatus.CombatAttack = _Value;
	}
	void SetCombatDefense(float _Value)
	{
		OliveStatus.CombatDefense = _Value;
	}
	void UpdateFighter()
	{
		OliveStatus.Fighter = OliveStatus.CombatSkill + OliveStatus.CombatAttack + OliveStatus.CombatDefense;
	}
	void SetMagicSkill(float _Value)
	{
		OliveStatus.MagicSkill = _Value;
	}
	void SetMagicAttack(float _Value)
	{
		OliveStatus.MagicAttack = _Value;
	}
	void SetMagicDefense(float _Value)
	{
		OliveStatus.MagicDefense = _Value;
	}
	void UpdateMagical()
	{
		OliveStatus.Magical = OliveStatus.MagicSkill + OliveStatus.MagicAttack + OliveStatus.MagicDefense;
	}
	void SetDecorum(float _Value)
	{
		OliveStatus.Decorum = _Value;
	}
	void SetArt(float _Value)
	{
		OliveStatus.Art = _Value;
	}
	void SetConversation(float _Value)
	{
		OliveStatus.Conversation = _Value;
	}
	void UpdateSocial()
	{
		OliveStatus.Social = OliveStatus.Decorum + OliveStatus.Art + OliveStatus.Conversation;
	}
	void SetCooking(float _Value)
	{
		OliveStatus.Cooking = _Value;
	}
	void SetCleaning(float _Value)
	{
		OliveStatus.Cleaning = _Value;
	}
	void SetTemperament(float _Value)
	{
		OliveStatus.Temperament = _Value;
	}
	void UpdateHouseWork()
	{
		OliveStatus.HouseWork = OliveStatus.Cooking + OliveStatus.Cleaning + OliveStatus.Temperament;
	}

	void UpdateZodiac();

	void SetFirstPhysicalCondition();

	void SetHeight(float _Value)
	{
		OlivePhysical.Height = _Value;
	}

	void SetWeight(float _Value)
	{
		OlivePhysical.Weight = _Value;
	}

	void SetBust(float _Value)
	{
		OlivePhysical.Bust = _Value;
	}

	void SetWaist(float _Value)
	{
		OlivePhysical.Waist = _Value;
	}

	void SetHip(float _Value)
	{
		OlivePhysical.Hip = _Value;
	}

	float GetHeight() const
	{
		return OlivePhysical.Height;
	}

	float GetWeight() const
	{
		return OlivePhysical.Weight;
	}

	float GetBust() const
	{
		return OlivePhysical.Bust;
	}

	float GetWaist() const
	{
		return OlivePhysical.Waist;
	}

	float GetHip() const
	{
		return OlivePhysical.Hip;
	}

protected:
	void Start() override;
	void Update(float _Deltatime) override;
	void Render(float _Time) override;

private:
	GameEngineRender* HeadRender = nullptr;
	GameEngineRender* BodyRender = nullptr;

	std::string OliveFirstName = std::string();
	std::string OliveLastName = std::string();
	
	int OliveAge = 10;
	
	Date OliveBirthDay = Date();
	
	BloodType OliveBloodType = BloodType::Null;
	
	Zodiac OliveZodiac = Zodiac::Null;
	
	PatronGod OlivePatronGod = PatronGod::Null;
	bool PatronGodSex = false; // false Male, true Female

	Status OliveStatus = Status();
	PhysicalCondition OlivePhysical = PhysicalCondition();

	int Gold = 500;

	Date FatherBirthDay = Date();
	int FatherAge = -1;

};

