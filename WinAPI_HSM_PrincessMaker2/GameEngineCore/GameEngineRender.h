#pragma once
#include <GameEnginePlatform/GameEngineImage.h>
#include "GameEngineObject.h"
#include <map>

class FrameAnimationParameter
{
public:
	std::string_view AnimationName = "";
	std::string_view ImageName = "";
	int Start = 0;
	int End = 0;
	int CurrentIndex = 0;
	float InterTime = 0.1f;
	bool Loop = true;
	std::vector<int> FrameIndex = std::vector<int>();
	std::vector<float> FrameTime = std::vector<float>();
};

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

	inline void SetMove(float4 _Position)
	{
		Position += _Position;
	}

	inline void SetScale(float4 _Scale)
	{
		Scale = _Scale;
	}

	void SetScaleToImage();

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

	GameEngineActor* GetActor();
	
	inline float4 GetScale()
	{
		return Scale;
	}
	
	inline float4 GetPosition()
	{
		return Position;
	}

	void SetTransColor(int _Color)
	{
		TransColor = _Color;
	}

	inline void EffectCameraOff()
	{
		IsEffectCamera = false;
	}

	bool IsAnimationEnd();
	void CreateAnimation(const FrameAnimationParameter& _Paramter);
	void ChangeAnimation(const std::string_view& _AnimationName, bool _ForceChange = false);

private:

	int Order = 0; // 이미지 랜더 순서를 정해주는 요소
	float4 Position = float4::Zero; // 이미지의 상대적 위치 -> 액터의 위치를 기준으로 정해짐
	float4 Scale= float4::Zero; // 이미지 크기
	GameEngineImage* Image = nullptr; // 랜더 이미지
	bool IsEffectCamera = true;

	int Frame = 0; // 아마 애니메이션 관련 요소

	void SetOrder(int _Order); // 
	void Render(float _DeltaTime);

	int TransColor = RGB(255, 0, 255);

	class FrameAnimation
	{
	public:
		GameEngineRender* Parent = nullptr;
		GameEngineImage* Image = nullptr;
		std::vector<int> FrameIndex;
		std::vector<float> FrameTime;
		int CurrentIndex = 0;
		float CurrentTime = 0.0f;
		bool Loop = true;


		bool IsEnd();

		void Render(float _DeltaTime);

		void Reset()
		{
			CurrentIndex = 0;
			CurrentTime = 0.0f;
		}
	};

	std::map<std::string, FrameAnimation> Animation;
	FrameAnimation* CurrentAnimation = nullptr;
};

