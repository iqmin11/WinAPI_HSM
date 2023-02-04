#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "Date.h"

class GameEngineRender;
class DateViewer : public GameEngineActor
{
public:
	// construtor destructor
	DateViewer();
	~DateViewer();

	// delete Function
	DateViewer(const DateViewer& _Other) = delete;
	DateViewer(DateViewer&& _Other) noexcept = delete;
	DateViewer& operator=(const DateViewer& _Other) = delete;
	DateViewer& operator=(DateViewer&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;

private:
	Date Today = Date();
	GameEngineRender* DateViewerFrameRender = nullptr;
	GameEngineRender* Year[4] = {};
	GameEngineRender* Month = {};
	std::vector<GameEngineRender*> Day = std::vector<GameEngineRender*>();
	GameEngineRender* WeekDay = {};
};

