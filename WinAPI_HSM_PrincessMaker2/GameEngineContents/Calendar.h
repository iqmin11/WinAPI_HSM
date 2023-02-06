#pragma once
#include <vector>
#include <GameEngineCore/GameEngineActor.h>
#include "Date.h" //나중에 실제는 레벨에서 주소값으로 받아와서 사용할 것
#include "ContentsEnums.h"

class GameEngineRender;
class Calendar : public GameEngineActor
{
public:
	// construtor destructor
	Calendar();
	~Calendar();

	// delete Function
	Calendar(const Calendar& _Other) = delete;
	Calendar(Calendar&& _Other) noexcept = delete;
	Calendar& operator=(const Calendar& _Other) = delete;
	Calendar& operator=(Calendar&& _Other) noexcept = delete;

	//void SetCalendarData(int _YYYY, int _MM);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;

private:
	Date Today = Date();
	std::vector<std::vector<Date>> CalendarData = std::vector<std::vector<Date>>();
	GameEngineRender* CalendarFrameRender = nullptr;
	std::vector<std::vector<GameEngineRender*>> CalendarNumRender = std::vector<std::vector<GameEngineRender*>>();
};

