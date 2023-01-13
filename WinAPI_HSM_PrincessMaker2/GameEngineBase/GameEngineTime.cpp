#include "GameEngineTime.h"

GameEngineTime::GameEngineTime()
{
	QueryPerformanceFrequency(&Second); // 이 컴퓨터는 1초를 정수n이라는 숫자로 표현할꺼야
	QueryPerformanceCounter(&Prev); // 이제부터 시간 체크
}

GameEngineTime::~GameEngineTime()
{

}

void GameEngineTime::Reset()
{
	QueryPerformanceCounter(&Prev); // 측정 시작시간 현재로 변경
}

float GameEngineTime::TimeCheck()
{
	QueryPerformanceCounter(&Current);
	
	Tick = Current.QuadPart - Prev.QuadPart;

	DoubleDeltaTime = (static_cast<double>(Current.QuadPart) - static_cast<double>(Prev.QuadPart)) / static_cast<double>(Second.QuadPart); // 걸린시간을 초로 나타내는것

	Prev.QuadPart = Current.QuadPart; // 타임체크가 끝나면 다시 타임을 체크할 준비(시간 초기화)

	floatDeltaTime = static_cast<float>(DoubleDeltaTime); // 단순 형변환(플로트를 많이 쓰기 때문에 이것으로 형변환)

	return floatDeltaTime;
}

