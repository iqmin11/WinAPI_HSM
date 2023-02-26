#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include "Date.h"
#include "ContentsEnums.h"

class Olive;
class Background;
class Flower;
class Paint;

class UIManager;

class CubeDialog;
class Button;

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
		Today.SetDate(_Today.GetYear(), _Today.GetMonth(), _Today.GetDay());
	}

	Date& GetToday()
	{
		return Today;
	}

	static CubeDialog* GetAcCubeDialog()
	{
		return AcCubeDialog;
	}

protected:


private:
	Olive* AcOlive = nullptr;
	Date Today = {1000,10,10};

	static CubeDialog* AcCubeDialog;
	Background* AcBackground = nullptr;
	Flower* AcFlower = nullptr; 
	Paint* AcPaint= nullptr; 
	UIManager* AcMenuManager = nullptr;

	void SoundLoad();
	void ImageLoad();
};