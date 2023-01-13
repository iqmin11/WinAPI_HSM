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

	// �� ���̿� ������ ���� �ð��� ����



protected:


private:
	__int64 Tick = 0;
	LARGE_INTEGER Prev = LARGE_INTEGER(); // ���� ���۽ð�
	LARGE_INTEGER Current = LARGE_INTEGER(); // ���� ���ð�
	LARGE_INTEGER Second = LARGE_INTEGER(); // 1�ʴ� ���� ���̾�
	double DoubleDeltaTime = 0.0;
	float floatDeltaTime = 0.0;
};

