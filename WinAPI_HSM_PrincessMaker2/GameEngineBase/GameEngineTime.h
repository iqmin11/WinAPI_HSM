#pragma once
#include <chrono>
#include <Windows.h>

class GameEngineTime
{
public:
	// construtor destructor
	GameEngineTime();
	~GameEngineTime();

	// delete Function
	GameEngineTime(const GameEngineTime& _Other) = delete;
	GameEngineTime(GameEngineTime&& _Other) noexcept = delete;
	GameEngineTime& operator=(const GameEngineTime& _Other) = delete;
	GameEngineTime& operator=(GameEngineTime&& _Other) noexcept = delete;

	void TimeCheckStart();

	// 이 사이에 벌어진 일의 시간을 재줘

	float TimeCheckEnd();


protected:


private:
	LARGE_INTEGER Prev = LARGE_INTEGER();
	LARGE_INTEGER Current = LARGE_INTEGER();
	LARGE_INTEGER Second = LARGE_INTEGER();


};

