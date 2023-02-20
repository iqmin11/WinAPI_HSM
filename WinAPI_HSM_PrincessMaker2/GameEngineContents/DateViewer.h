#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/NumberRenderObject.h>
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

private:
	Date Today = Date(); 
	GameEngineRender* DateViewerFrameRender = nullptr;
	NumberRenderObject Year = NumberRenderObject();
	GameEngineRender* Month = {}; 
	NumberRenderObject Day = NumberRenderObject();
	GameEngineRender* WeekDay = {}; 
	
};

