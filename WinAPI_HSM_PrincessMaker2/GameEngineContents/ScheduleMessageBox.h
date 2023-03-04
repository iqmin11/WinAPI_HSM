#pragma once
#include "MenuFrame.h"
#include "Olive.h"

class GameEngineRender;
class ScheduleMessageBox : public MenuFrame
{
public:
	// construtor destructor
	ScheduleMessageBox();
	~ScheduleMessageBox();

	// delete Function
	ScheduleMessageBox(const ScheduleMessageBox& _Other) = delete;
	ScheduleMessageBox(ScheduleMessageBox&& _Other) noexcept = delete;
	ScheduleMessageBox& operator=(const ScheduleMessageBox& _Other) = delete;
	ScheduleMessageBox& operator=(ScheduleMessageBox&& _Other) noexcept = delete;

	void SetScheduleString(ScheduleLabel _ScheduleLabel);

	void SetDayCount(int _DayCount)
	{
		DayCount = _DayCount;
	}

	void SetStartStatus(const Olive::Status& _StartStatus)
	{
		StartStatus = _StartStatus;
	}

	void SetEndStatus(const Olive::Status& _EndStatus)
	{
		EndStatus = _EndStatus;
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	float4 Scale = {310, 180};
	float4 ActorPos = { 619,380 };

	GameEngineRender* TextRender = nullptr;

	int TextHeight = 18;
	std::string TextType = "±¼¸²";
	COLORREF TextColor = RGB(255, 255, 255);
	float4 TextBoxScale = { 290,160 };
	float4 TextRenderPos = { -145,-80 };

	Olive::Status StartStatus = Olive::Status();
	Olive::Status EndStatus = Olive::Status();
	std::string Schedule = " ";
	int DayCount = 0;

	void UpdateTextRender();
	void UpdateScheduleEndText();
};

