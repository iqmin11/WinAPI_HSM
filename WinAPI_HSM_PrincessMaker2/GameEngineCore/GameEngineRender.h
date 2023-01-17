#pragma once
#include <GameEnginePlatform/GameEngineImage.h>
#include <GameEngineCore/GameEngineObject.h>

class GameEngineActor;
class GameEngineLevel;
class GameEngineRender : public GameEngineObject
{
	friend GameEngineActor;
	friend GameEngineLevel;

public:
	// construtor destructor
	GameEngineRender();
	~GameEngineRender();

	// delete Function
	GameEngineRender(const GameEngineRender& _Other) = delete;
	GameEngineRender(GameEngineRender&& _Other) noexcept = delete;
	GameEngineRender& operator=(const GameEngineRender& _Other) = delete;
	GameEngineRender& operator=(GameEngineRender&& _Other) noexcept = delete;

	void SetImage(const std::string_view& _ImageName);

	inline void SetPosition(float4 _Position)
	{
		Position = _Position;
	}

	inline void SetScale(float4 _Scale)
	{
		Scale = _Scale;
	}
	
	void SetFrame(int _Frame);

	inline int GetOrder() const
	{
		return Order;
	}

	inline GameEngineImage* GetImage() const
	{
		return Image;
	}

	inline int GetFrame() const
	{
		return Frame;
	}


private:
	GameEngineActor* Owner = nullptr; // �� �̹����� �����ִ� �������� ������ �ּҰ�

	int Order = 0; // �̹��� ���� ������ �����ִ� ���
	float4 Position = float4::Zero; // �̹����� ����� ��ġ -> ������ ��ġ�� �������� ������
	float4 Scale= float4::Zero; // �̹��� ũ��
	GameEngineImage* Image = nullptr; // ���� �̹���

	int Frame = 0; // �Ƹ� �ִϸ��̼� ���� ���

	void SetOrder(int _Order); // 
	void Render(float _DeltaTime);
};
