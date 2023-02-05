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
	Date Today = Date(); //나중에는 Today를 여기서 알게하지말고 Level단계에서 가져와서 쓰도록 바꾸자 여기서 멤버변수는 없애자
	GameEngineRender* DateViewerFrameRender = nullptr;
	GameEngineRender* Year[4] = {};
	GameEngineRender* Month = {};
	std::vector<GameEngineRender*> Day = std::vector<GameEngineRender*>();
	GameEngineRender* WeekDay = {};
};

