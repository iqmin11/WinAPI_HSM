#pragma once
#include <GameEngineBase/GameEngineMath.h>
#include <Windows.h>

// ���� : ȭ�鿡 ����, ��ġ�� ũ�Ⱑ �ִ� ���͵��� ���
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
	
	float4 GetPos() // ��ġ�� ����
	{
		return Pos;
	}

	void SetPos(const float4& _MovePos) // ��ġ�� ����
	{
		Pos = _MovePos;
	}

	void SetMove(const float4& _MovePos) // ������ġ�� ���� ��ŭ �̵�
	{
		Pos += _MovePos;
	}


protected:
	// �������� ���� ���� �ֱ� ������ ���������Լ��� ������ ����.
	
	// �����ϱ����� ���� �غ��ؾ��Ұ��� ������ ���⼭ �ض�.
	virtual void Start() {}

	// Ű�Է��� �ްų� �ΰ������� ������ ����ϰų� �ϴ� �͵��� ���⼭ ó��
	virtual void Update() {}
	
	// ������ ���� �Լ��� �ѹ� �������ϰ� 
	virtual void LateUpdate() {}

	// ȭ�鿡 �׷����� ��ɵ��� ���⼭ ó��
	virtual void Render() {}

private:
	int Order; // �����ϴ� �ε��� (map�� Key)��
	float4 Pos = { 0.0f, 0.0f };

	void SetOrder(int _Order)
	{
		Order = _Order;
	}

};

