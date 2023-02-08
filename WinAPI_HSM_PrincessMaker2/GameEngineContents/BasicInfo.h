#pragma once
#include <vector>
#include <string>

#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/NumberRenderObject.h>

enum class Zodiac //�̰͵� ���߿� �ø��꿡 �ű��
{
	Null = -1,
	Capricorn,   // �����ڸ�
	Aquarius,	 // �����ڸ�
	Pisces,		 // ������ڸ�
	Aries,		 // ���ڸ�
	Taurus,		 // Ȳ���ڸ�
	Gemini,		 // �ֵ����ڸ�
	Cancer,		 // ���ڸ�
	Leo,		 // �����ڸ�
	Virgo,		 // ó���ڸ�
	Libra,		 // õĪ�ڸ�
	Scorpio,	 // �����ڸ�
	Sagittarius	 // ����ڸ�
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

	void SetName(const std::string_view& _Name)
	{
		OliveName = _Name;
	}

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
	
	std::string OliveName = "\0";
	int Age = 0; // �̰� �ø���
	Zodiac Star = Zodiac::Null; // �̰� �ø���
	int Gold = 0; // �̰� �ø���
	float Height = 0.0f; // �̰� �ø���
	float Weight = 0.0f; // �̰� �ø���
	float Bust = 0.0f; // �̰� �ø���
	float Waist = 0.0f; // �̰� �ø���
	float Hip = 0.0f; // �̰� �ø���

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

