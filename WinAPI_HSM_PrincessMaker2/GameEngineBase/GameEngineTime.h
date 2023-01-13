#pragma once
#include <chrono>
#include <Windows.h>

class GameEngineTime
{
public:
	static GameEngineTime GlobalTime;

	// construtor destructor
	GameEngineTime();
	~GameEngineTime();

	// delete Function
	GameEngineTime(const GameEngineTime& _Other) = delete;
	GameEngineTime(GameEngineTime&& _Other) noexcept = delete;
	GameEngineTime& operator=(const GameEngineTime& _Other) = delete;
	GameEngineTime& operator=(GameEngineTime&& _Other) noexcept = delete;

	void Reset();

	float TimeCheck();

	// 이 사이에 벌어진 일의 시간을 재줘



protected:


private:
	__int64 Tick = 0;
	LARGE_INTEGER Prev = LARGE_INTEGER(); // 측정 시작시간
	LARGE_INTEGER Current = LARGE_INTEGER(); // 측정 끝시간
	LARGE_INTEGER Second = LARGE_INTEGER(); // 1초는 정수 몇이야
	double DoubleDeltaTime = 0.0;
	float floatDeltaTime = 0.0;
};

