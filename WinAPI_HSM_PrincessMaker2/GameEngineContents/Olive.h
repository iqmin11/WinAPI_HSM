#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "Date.h"
#include "ContentsEnums.h"

class GameEngineRender;
class Olive : public GameEngineActor
{
public:
	class Status
	{
	public:
		Status& operator +=(const Status& _Value);
		bool operator ==(const Status& _Value);
		bool operator !=(const Status& _Value);

		void SetStatus(const Status& _Para);
		void UpdateMoreThanMin();
		void UpdateLessThanMax();

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

	Status OliveStatus = Status();

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

	int& GetGold()
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

	
	void UpdateFighter()
	{
		OliveStatus.Fighter = OliveStatus.CombatSkill + OliveStatus.CombatAttack + OliveStatus.CombatDefense;
	}
	
	void UpdateMagical()
	{
		OliveStatus.Magical = OliveStatus.MagicSkill + OliveStatus.MagicAttack + OliveStatus.MagicDefense;
	}
	
	void UpdateSocial()
	{
		OliveStatus.Social = OliveStatus.Decorum + OliveStatus.Art + OliveStatus.Conversation;
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
	
	Zodiac OliveZodiac = Zodiac::Ȳ���ڸ�;
	
	PatronGod OlivePatronGod = PatronGod::ȭ����_������;
	bool PatronGodSex = false; // false Male, true Female

	PhysicalCondition OlivePhysical = PhysicalCondition();
	Diet OliveDiet = Diet::��������_�ʴ´�;

	int Gold = 500;

	bool DiseaseState = 0;
	bool DelinquentState = 0;

	float Popularity = 0;

	Date FatherBirthDay = Date();
	int FatherAge = 10;

};

