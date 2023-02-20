#pragma once
#include <vector>
#include <string>

#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/NumberRenderObject.h>

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

	void SetName(const std::string_view& _Name)
	{
		OliveName = _Name;
	}

	void SetAge(int _age)
	{
		Age = _age;
	}
	
	//void SetStar(Zodiac _star)
	//{
	//	Star = _star;
	//}
	
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
	
	std::string OliveName = "\0";
	int Age = 0; // 이건 올리브
	//Zodiac Star = Zodiac::Null; // 이건 올리브
	int Gold = 0; // 이건 올리브
	float Height = 0.0f; // 이건 올리브
	float Weight = 0.0f; // 이건 올리브
	float Bust = 0.0f; // 이건 올리브
	float Waist = 0.0f; // 이건 올리브
	float Hip = 0.0f; // 이건 올리브

	GameEngineRender* BasicInfoFrame = nullptr;

	NumberRenderObject AgeRender = NumberRenderObject();
	NumberRenderObject GoldRender = NumberRenderObject();
	NumberRenderObject HeightRender = NumberRenderObject();
	NumberRenderObject WeightRender = NumberRenderObject();
	NumberRenderObject BustRender = NumberRenderObject();
	NumberRenderObject WaistRender = NumberRenderObject();
	NumberRenderObject HipRender = NumberRenderObject();

	GameEngineRender* StarRender = nullptr;
};

