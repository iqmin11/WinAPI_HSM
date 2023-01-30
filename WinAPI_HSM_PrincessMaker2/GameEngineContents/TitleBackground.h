#pragma once
#include <GameEngineCore/GameEngineActor.h>

class TitleBackground : public GameEngineActor
{
public:
	// construtor destructor
	TitleBackground();
	~TitleBackground();

	// delete Function
	TitleBackground(const TitleBackground& _Other) = delete;
	TitleBackground(TitleBackground&& _Other) noexcept = delete;
	TitleBackground& operator=(const TitleBackground& _Other) = delete;
	TitleBackground& operator=(TitleBackground&& _Other) noexcept = delete;

	void Start() override;

protected:


private:
	GameEngineRender* Render = nullptr;

};

