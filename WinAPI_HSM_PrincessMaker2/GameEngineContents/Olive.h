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
		int Constitution = -1;
		int Strength = -1;
		int Intelligence = -1;
		int Refinement = -1;
		int Charisma = -1;
		int Morality = -1;
		int Faith = -1;
		int Sin = -1;
		int Sensitivity = -1;
		int Stress = -1;

		int Fighter = -1;
		int CombatSkill = -1;
		int CombatAttack = -1;
		int CombatDefense = -1;

		int Magical = -1;
		int MagicSkill = -1;
		int MagicAttack = -1;
		int MagicDefense = -1;

		int Social = -1;
		int Decorum = -1;
		int Art = -1;
		int Conversation = -1;

		int HouseWork = -1;
		int Cooking = -1;
		int Cleaning = -1;
		int Temperament = -1;
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

	void SetFirstStatus();
	void SetStatus(Status _Status);

	void SetConstitution(int _Value)
	{
		OliveStatus.Constitution = _Value;
	}
	void SetStrength(int _Value)
	{
		OliveStatus.Strength = _Value;
	}
	void SetIntelligence(int _Value)
	{
		OliveStatus.Intelligence = _Value;
	}
	void SetRefinement(int _Value)
	{
		OliveStatus.Refinement = _Value;
	}
	void SetCharisma(int _Value)
	{
		OliveStatus.Charisma = _Value;
	}
	void SetMorality(int _Value)
	{
		OliveStatus.Morality = _Value;
	}
	void SetFaith(int _Value)
	{
		OliveStatus.Faith = _Value;
	}
	void SetSin(int _Value)
	{
		OliveStatus.Sin = _Value;
	}
	void SetSensitivity(int _Value)
	{
		OliveStatus.Sensitivity = _Value;
	}
	void SetStress(int _Value)
	{
		OliveStatus.Stress = _Value;
	}
	void SetCombatSkill(int _Value)
	{
		OliveStatus.CombatSkill = _Value;
	}
	void SetCombatAttack(int _Value)
	{
		OliveStatus.CombatAttack = _Value;
	}
	void SetCombatDefense(int _Value)
	{
		OliveStatus.CombatDefense = _Value;
	}
	void UpdateFighter()
	{
		OliveStatus.Fighter = OliveStatus.CombatSkill + OliveStatus.CombatAttack + OliveStatus.CombatDefense;
	}
	void SetMagicSkill(int _Value)
	{
		OliveStatus.MagicSkill = _Value;
	}
	void SetMagicAttack(int _Value)
	{
		OliveStatus.MagicAttack = _Value;
	}
	void SetMagicDefense(int _Value)
	{
		OliveStatus.MagicDefense = _Value;
	}
	void UpdateMagical()
	{
		OliveStatus.Magical = OliveStatus.MagicSkill + OliveStatus.MagicAttack + OliveStatus.MagicDefense;
	}
	void SetDecorum(int _Value)
	{
		OliveStatus.Decorum = _Value;
	}
	void SetArt(int _Value)
	{
		OliveStatus.Art = _Value;
	}
	void SetConversation(int _Value)
	{
		OliveStatus.Conversation = _Value;
	}
	void UpdateSocial()
	{
		OliveStatus.Social = OliveStatus.Decorum + OliveStatus.Art + OliveStatus.Conversation;
	}
	void SetCooking(int _Value)
	{
		OliveStatus.Cooking = _Value;
	}
	void SetCleaning(int _Value)
	{
		OliveStatus.Cleaning = _Value;
	}
	void SetTemperament(int _Value)
	{
		OliveStatus.Temperament = _Value;
	}
	void UpdateHouseWork()
	{
		OliveStatus.HouseWork = OliveStatus.Cooking + OliveStatus.Cleaning + OliveStatus.Temperament;
	}

	void UpdateZodiac();

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

	int Gold = 500;

	Date FatherBirthDay = Date();
	int FatherAge = -1;

};

