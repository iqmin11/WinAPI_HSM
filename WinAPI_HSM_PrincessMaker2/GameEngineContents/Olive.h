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
		float Constitution = 0;
		float Strength = 0;
		float Intelligence = 0;
		float Refinement = 0;
		float Charisma = 0;
		float Morality = 0;
		float Faith = 0;
		float Sin = 0;
		float Sensitivity = 0;
		float Stress = 0;

		float Fighter = 0;
		float CombatSkill = 0;
		float CombatAttack = 0;
		float CombatDefense = 0;

		float Magical = 0;
		float MagicSkill = 0;
		float MagicAttack = 0;
		float MagicDefense = 0;

		float Social = 0;
		float Decorum = 0;
		float Art = 0;
		float Conversation = 0;

		float HouseWork = 0;
		float Cooking = 0;
		float Cleaning = 0;
		float Temperament = 0;
	};

	class PhysicalCondition
	{
	public:
		float Height = 0;
		float Weight = 0;
		float Bust = 0;
		float Waist = 0;
		float Hip = 0;
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

	Diet GetOliveDiet() const
	{
		return OliveDiet;
	}

	void SetOliveDiet(Diet _Diet)
	{
		OliveDiet = _Diet;
	}

	float GetDiseaseIndex()
	{
		float DiseaseIndex = OliveStatus.Stress - OliveStatus.Constitution;
		if (DiseaseIndex < 0)
		{
			DiseaseIndex = 0;
		}
		return DiseaseIndex;
	}

	float GetDelinquency()
	{
		float Higher = 0.0f;
		OliveStatus.Morality > OliveStatus.Faith ? Higher = OliveStatus.Morality : Higher = OliveStatus.Faith;
		float Delinquency = OliveStatus.Stress - Higher;
		if (Delinquency < 0)
		{
			Delinquency = 0;
		}
		return Delinquency;
	}

	bool IsDiseaseState() const
	{
		return DiseaseState;
	}

	bool IsDelinquentState() const
	{
		return DelinquentState;
	}

	float GetPopularity() const
	{
		return Popularity;
	}

protected:
	void Start() override;
	void Update(float _Deltatime) override;
	void Render(float _Time) override;

private:
	GameEngineRender* HeadRender = nullptr;
	GameEngineRender* BodyRender = nullptr;

	std::string OliveFirstName = "DefaultFirst";
	std::string OliveLastName = "DefaultLast";
	
	int OliveAge = 10;
	
	Date OliveBirthDay = {1200, 10, 10};
	
	BloodType OliveBloodType = BloodType::AB;
	
	Zodiac OliveZodiac = Zodiac::황소자리;
	
	PatronGod OlivePatronGod = PatronGod::화성신_마르스;
	bool PatronGodSex = false; // false Male, true Female

	Status OliveStatus = Status();
	PhysicalCondition OlivePhysical = PhysicalCondition();
	Diet OliveDiet = Diet::무리하지_않는다;

	int Gold = 500;

	bool DiseaseState = 0;
	bool DelinquentState = 0;

	float Popularity = 0;

	Date FatherBirthDay = Date();
	int FatherAge = 10;

};

