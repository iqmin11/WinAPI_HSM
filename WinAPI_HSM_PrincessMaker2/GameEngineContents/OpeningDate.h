#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/NumberRenderObject.h>
#include "Date.h"

class GameEngineRender;
class OpeningDate : public GameEngineActor
{
public:
	// construtor destructor
	OpeningDate();
	~OpeningDate();

	// delete Function
	OpeningDate(const OpeningDate& _Other) = delete;
	OpeningDate(OpeningDate&& _Other) noexcept = delete;
	OpeningDate& operator=(const OpeningDate& _Other) = delete;
	OpeningDate& operator=(OpeningDate&& _Other) noexcept = delete;

	void UpdateOliveBirthDay();

protected:
	void Start() override;

private:
	GameEngineRender* OpeningDateRender = nullptr;
	NumberRenderObject MonthNum = NumberRenderObject();
	NumberRenderObject DayNum = NumberRenderObject();
	Date OliveBirthDay = Date();
};

