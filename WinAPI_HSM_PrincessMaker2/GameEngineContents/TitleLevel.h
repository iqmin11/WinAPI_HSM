#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineResources.h>

class TitleMenu;
class MenuFrame;
class MousePoint;
class TitleLevel : public GameEngineLevel
{
public:
	// construtor destructor
	TitleLevel();
	~TitleLevel();

	// delete Function
	TitleLevel(const TitleLevel& _Other) = delete;
	TitleLevel(TitleLevel&& _Other) noexcept = delete;
	TitleLevel& operator=(const TitleLevel& _Other) = delete;
	TitleLevel& operator=(TitleLevel&& _Other) noexcept = delete;

	void Loading() override;
	void Update(float _DeltaTime) override;
	void LevelChangeEnd(GameEngineLevel* _NextLevel) override {};
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override {};

protected:


private:
	TitleMenu* TitleSelectionMenu = nullptr;
	GameEngineSoundPlayer BGMPlayer;
	void SoundLoad();
	void ImageLoad();
};

