#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "Date.h"
#include "ContentsEnums.h"

class GameEngineRender;
class Olive : public GameEngineActor
{
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

	std::string GetOliveLastName()
	{
		return OliveLastName;
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



protected:
	void Start() override;
	void Update(float _Deltatime) override;
	void Render(float _Time) override;

private:
	GameEngineRender* HeadRender = nullptr;
	GameEngineRender* BodyRender = nullptr;

	std::string OliveFirstName = std::string();
	std::string OliveLastName = std::string();
	Date OliveBirthDay = Date();
	BloodType OliveBloodType = BloodType::Null;
	
	int FatherAge = -1;
	Date FatherBirthDay = Date();

};

