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

	// �� ���̿� ������ ���� �ð��� ����

	float TimeCheckEnd();


protected:


private:
	LARGE_INTEGER Prev = LARGE_INTEGER();
	LARGE_INTEGER Current = LARGE_INTEGER();
	LARGE_INTEGER Second = LARGE_INTEGER();


};

