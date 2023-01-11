#pragma once
#include <GameEngineBase/GameEngineMath.h>
#include <Windows.h>

// 설명 : 화면에 존재, 위치와 크기가 있는 모든것들의 기능
class GameEngineLevel;
class GameEngineActor
{
	friend GameEngineLevel;
public:
	// constrcuter destructer
	GameEngineActor();
	~GameEngineActor();

	// delete Function
	GameEngineActor(const GameEngineActor& _Other) = delete;
	GameEngineActor(GameEngineActor&& _Other) noexcept = delete;
	GameEngineActor& operator=(const GameEngineActor& _Other) = delete;
	GameEngineActor& operator=(GameEngineActor&& _Other) noexcept = delete;
	
	float4 GetPos() // 위치값 리턴
	{
		return Pos;
	}

	void SetPos(const float4& _MovePos) // 위치값 수정
	{
		Pos = _MovePos;
	}

	void SetMove(const float4& _MovePos) // 현재위치로 부터 얼만큼 이동
	{
		Pos += _MovePos;
	}


protected:
	// 구현하지 않을 수도 있기 때문에 순수가상함수로 만들지 않음.
	
	// 시작하기전에 뭔가 준비해야할것이 있으면 여기서 해라.
	virtual void Start() {}

	// 키입력을 받거나 인공지능을 점수를 계산하거나 하는 것들을 여기서 처리
	virtual void Update() {}
	
	// 순서를 제어 함수를 한번 더실행하고 
	virtual void LateUpdate() {}

	// 화면에 그려지는 기능들을 여기서 처리
	virtual void Render() {}

private:
	int Order; // 대응하는 인덱스 (map의 Key)값
	float4 Pos = { 0.0f, 0.0f };

	void SetOrder(int _Order)
	{
		Order = _Order;
	}

};

