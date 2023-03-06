#pragma once
#include <GameEngineCore/GameEngineLevel.h>


enum class Ending
{
	Null = -1,
	����,
	SM����,
	���氡�Ǻ���,
	���¹�,
	���â��,
	����,
	â��,
	����,
	�۰�,
	ȭ��,
	�����,
	����,
	���,
	�ڻ�,
	���,
	���ֱ�,
	�л�,
	���ǰ�,
	����,
	����,
	��������,
	���,
	��ȸ����,
	�丮��,
	������,
	�̿��,
	������,
	��ɲ�,
	������,
	��������,
	��������,
	�����������,
	���ǹ���,
	�ó�,
	���,
	�屺,
	��������,
	���,
	�������,
	����ݻ�ɲ�,
	����,
	�뺴,
	�������,
	�ձø�����,
	�������,
	������,
	������,
	������,
	������,
	�Ÿ��Ǳ���,
	�պ�,
	�����ı�,
	���ۺ���,
	��ȣ��ó,
	������ó,
	�����ó,
	������ø,
	��ȥ��,
	�źμ���,
};

class Olive;
class FirstScene;
class SecondScene;
class ThirdScene;
class FourthScene;
class EndingPortrait;
class EndingLevel : public GameEngineLevel
{
public:
	// construtor destructor
	EndingLevel();
	~EndingLevel();

	// delete Function
	EndingLevel(const EndingLevel& _Other) = delete;
	EndingLevel(EndingLevel&& _Other) noexcept = delete;
	EndingLevel& operator=(const EndingLevel& _Other) = delete;
	EndingLevel& operator=(EndingLevel&& _Other) noexcept = delete;

	void Loading() override;
	void Update(float _DeltaTime) override;
	void LevelChangeEnd(GameEngineLevel* _NextLevel) override;

	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;

	Ending* GetOliveEnding()
	{
		return &OliveEnding;
	}

	Olive* GetAcOlive()
	{
		return AcOlive;
	}

protected:


private:
	float Time = 0;
	Olive* AcOlive = nullptr;

	Ending OliveEnding = Ending::Null;

	FirstScene* AcFirstScene = nullptr;
	SecondScene* AcSecondScene = nullptr;
	ThirdScene* AcThirdScene = nullptr;
	FourthScene* AcFourthScene = nullptr;

	EndingPortrait* AcEndingPortrait = nullptr;
	

	void ImageLoad();
	void SoundLoad();

	int EstimateGrade(float _Estimate);
	float EstimateMaxMinusMin();
	float EstimateMax();
	float EstimateMin();
};

