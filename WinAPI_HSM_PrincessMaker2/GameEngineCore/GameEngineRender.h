#pragma once
#include <GameEnginePlatform/GameEngineImage.h>

class GameEngineActor;
class GameEngineLevel;
class GameEngineRender
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

	inline int GetOrder() const
	{
		return Order;
	}


private:
	GameEngineActor* Owner = nullptr; // 이 이미지를 갖고있는 소유권자 액터의 주소값

	int Order = 0; // 이미지 랜더 순서를 정해주는 요소
	float4 Position = float4::Zero; // 이미지의 상대적 위치 -> 액터의 위치를 기준으로 정해짐
	float4 Scale= float4::Zero; // 이미지 크기
	GameEngineImage* Image = nullptr; // 랜더 이미지

	int Frame = 0; // 아마 애니메이션 관련 요소

	void SetOrder(int _Order); // 
	void Render(float _DeltaTime);
};

