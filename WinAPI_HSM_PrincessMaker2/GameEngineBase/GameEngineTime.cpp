#include "GameEngineTime.h"

GameEngineTime::GameEngineTime()
{
	QueryPerformanceFrequency(&Second); // �� ��ǻ�ʹ� 1�ʸ� ����n�̶�� ���ڷ� ǥ���Ҳ���
	QueryPerformanceCounter(&Prev); // �������� �ð� üũ
}

GameEngineTime::~GameEngineTime()
{

}

void GameEngineTime::Reset()
{
	QueryPerformanceCounter(&Prev); // ���� ���۽ð� ����� ����
}

float GameEngineTime::TimeCheck()
{
	QueryPerformanceCounter(&Current);
	
	Tick = Current.QuadPart - Prev.QuadPart;

	DoubleDeltaTime = (static_cast<double>(Current.QuadPart) - static_cast<double>(Prev.QuadPart)) / static_cast<double>(Second.QuadPart); // �ɸ��ð��� �ʷ� ��Ÿ���°�

	Prev.QuadPart = Current.QuadPart; // Ÿ��üũ�� ������ �ٽ� Ÿ���� üũ�� �غ�(�ð� �ʱ�ȭ)

	floatDeltaTime = static_cast<float>(DoubleDeltaTime); // �ܼ� ����ȯ(�÷�Ʈ�� ���� ���� ������ �̰����� ����ȯ)

	return floatDeltaTime;
}

