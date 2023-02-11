#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/Button.h>
#include <GameEngineCore/NumberRenderObject.h>
#include "Date.h"


class PlayerCalendar : public GameEngineActor
{
public:
	// construtor destructor
	PlayerCalendar();
	~PlayerCalendar();

	// delete Function
	PlayerCalendar(const PlayerCalendar& _Other) = delete;
	PlayerCalendar(PlayerCalendar&& _Other) noexcept = delete;
	PlayerCalendar& operator=(const PlayerCalendar& _Other) = delete;
	PlayerCalendar& operator=(PlayerCalendar&& _Other) noexcept = delete;


	void SetDateNumButton();
	void SetYearRender();
	void SetWeekdayRender();
	void SetMonthRender();
	//void SetHoverButtonDateObject();



	void SetOliveBirth(int _YYYY, int _MM, int _DD); // �ӽ�
	void SetCalendarYear(int _YYYY);// �ӽ�

	void On() override;
	void Off() override;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime) override;


private:
	Date OliveBirth = Date();
	Date PlayerBirth = Date();
	int CalendarYear = 2023;

	Button* DateButton[4][3][6][7] = {}; //�޷� ��, ��, ��¥ ��, ��
	Date EachButtonDate[4][3][6][7] = {}; //�޷� ��, ��, ��¥ ��, ��
	GameEngineRender* WeekRender[4][3] = {}; //�޷� ��, ��, ��¥ ��, ��
	GameEngineRender* YearRender[4][3][4] = {}; // �޷� ��, ��, �⵵ �ױ���
	GameEngineRender* MonthRender[4][3] = {}; // �޷� ��, �� 
	GameEngineRender* BackgroundRender = nullptr;
	
	NumberRenderObject HoverButtonDateRender_Year = NumberRenderObject();
	float4 Pos_HoverButtonDateRender_Year = {-335, -221};
	NumberRenderObject HoverButtonDateRender_Month = NumberRenderObject();
	float4 Pos_HoverButtonDateRender_Month = {-305, -221};
	NumberRenderObject HoverButtonDateRender_Day = NumberRenderObject();
	float4 Pos_HoverButtonDateRender_Day = {-275, -221};

	float4 WichButtonNotRelease();
	//bool IsAnyButtonHover();
	//bool IsAnyButtonPress();

	void SetEachButtonDate();

	std::vector<GameEngineCollision*> CollisionsMounsAndButton = std::vector<GameEngineCollision*>();
};

