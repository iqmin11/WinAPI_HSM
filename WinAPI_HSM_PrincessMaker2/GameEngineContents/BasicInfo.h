#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <vector>

enum class Zodiac //이것도 나중에 올리브에 옮기기
{
	Null = -1,
	Capricorn,   // 염소자리
	Aquarius,	 // 물병자리
	Pisces,		 // 물고기자리
	Aries,		 // 양자리
	Taurus,		 // 황소자리
	Gemini,		 // 쌍둥이자리
	Cancer,		 // 게자리
	Leo,		 // 사자자리
	Virgo,		 // 처녀자리
	Libra,		 // 천칭자리
	Scorpio,	 // 전갈자리
	Sagittarius	 // 사수자리
};


class GameEngineRender;
class BasicInfo : public GameEngineActor
{
public:
	// construtor destructor
	BasicInfo();
	~BasicInfo();

	// delete Function
	BasicInfo(const BasicInfo& _Other) = delete;
	BasicInfo(BasicInfo&& _Other) noexcept = delete;
	BasicInfo& operator=(const BasicInfo& _Other) = delete;
	BasicInfo& operator=(BasicInfo&& _Other) noexcept = delete;

	void SetAge(int _age)
	{
		Age = _age;
	}
	
	void SetStar(Zodiac _star)
	{
		Star = _star;
	}
	
	void SetGold(int _gold)
	{
		Gold = _gold;
	}

	void SetHeight(float _Height)
	{
		Height = _Height;
	}

	void SetWeight(float _Weight)
	{
		Weight = _Weight;
	}

	void SetBust(float _Bust)
	{
		Bust = _Bust;
	}

	void SetWaist(float _Waist)
	{
		Waist = _Waist;
	}

	void SetHip(float _Hip)
	{
		Hip = _Hip;
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;

private:
	
	int Age = 0; // 이건 올리브
	Zodiac Star = Zodiac::Null; // 이건 올리브
	int Gold = 0; // 이건 레벨에 옮겨서 받아쓰기만하기 누가가질지 고민해볼필요가 있네요 이건
	float Height = 0.0f; // 이건 올리브
	float Weight = 0.0f; // 이건 올리브
	float Bust = 0.0f; // 이건 올리브
	float Waist = 0.0f; // 이건 올리브
	float Hip = 0.0f; // 이건 올리브

	GameEngineRender* BasicInfoFrame = nullptr;
	GameEngineRender* AgeRender[2] = {};
	GameEngineRender* StarRender = nullptr;
	std::vector<GameEngineRender*> GoldRender = std::vector<GameEngineRender*>();
};

