#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include "Date.h"

class Olive;
class Background;
class Flower;
class Paint;
class RaisingSimLevel : public GameEngineLevel
{
public:
	// construtor destructor
	RaisingSimLevel();
	~RaisingSimLevel();

	// delete Function
	RaisingSimLevel(const RaisingSimLevel& _Other) = delete;
	RaisingSimLevel(RaisingSimLevel&& _Other) noexcept = delete;
	RaisingSimLevel& operator=(const RaisingSimLevel& _Other) = delete;
	RaisingSimLevel& operator=(RaisingSimLevel&& _Other) noexcept = delete;

	void Loading() override;
	void Update(float _DeltaTime) override;
	void LevelChangeEnd(GameEngineLevel* _NextLevel) override {};
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;

	void SetToday(Date _Today)
	{
		Today = _Today;
	}

	Date& GetToday()
	{
		return Today;
	}

protected:


private:
	Olive* AcOlive = nullptr;
	Date Today = Date();

	Background* AcBackground = nullptr;
	Flower* AcFlower = nullptr; 
	Paint* AcPaint= nullptr; 

	void SoundLoad();
	void ImageLoad();
};

