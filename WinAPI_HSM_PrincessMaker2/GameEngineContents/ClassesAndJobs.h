#pragma once
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineCore/GameEngineActor.h>
#include "ContentsEnums.h"
#include "Olive.h"

class ClassesAndJobs : public GameEngineActor
{
public:
	// construtor destructor
	ClassesAndJobs();
	~ClassesAndJobs();

	// delete Function
	ClassesAndJobs(const ClassesAndJobs& _Other) = delete;
	ClassesAndJobs(ClassesAndJobs&& _Other) noexcept = delete;
	ClassesAndJobs& operator=(const ClassesAndJobs& _Other) = delete;
	ClassesAndJobs& operator=(ClassesAndJobs&& _Other) noexcept = delete;

	Olive::Status& GetStatusVarianceMin()
	{
		return Beginner_StatusVarianceMin;
	}

	Olive::Status& GetStatusVarianceMax()
	{
		return Beginner_StatusVarianceMax;
	}

	Olive::Status& GetStatusVariance();
	

protected:
	void Start() override;

	void SetImageName(const std::string_view& _Obj, const std::string_view& _Back1, const std::string_view& _Back2 = std::string_view());
	void SetBackground();
	void SetObjScale(const float4& _Scale)
	{
		ObjScale = _Scale;
	}
	void SetOliveObj(int _SuccessStart, int _SuccessEnd, int _FailStart, int _FailEnd, int _DontStart, int _DontEnd, const float4& _Pos);
	void SetObj1(PM2RenderOrder _Order, int _Start, int _End, const float4& _Pos);
	void SetObj2(PM2RenderOrder _Order, int _Start, int _End, const float4& _Pos);
	void SetObj3(PM2RenderOrder _Order, int _Start, int _End, const float4& _Pos);
	void SetObj4(PM2RenderOrder _Order, int _Start, int _End, const float4& _Pos);
	void SetObj5(PM2RenderOrder _Order, int _Start, int _End, const float4& _Pos);

private:
	Olive::Status Beginner_StatusVarianceMin = {};
	Olive::Status Beginner_StatusVarianceMax = {};
	Olive::Status Beginner_StatusVariance = {};
	float4 ActorPos = { 240, 380 };

	//애니메이션
	GameEngineRender* BackgroundLayer1 = nullptr;
	GameEngineRender* BackgroundLayer2 = nullptr;

	GameEngineRender* OliveObject = nullptr;
	float4 OliveObjectPos = float4::Zero;
	int OliveSuccessFrameStart = -1;
	int OliveSuccessFrameEnd = -1;
	int OliveFailFrameStart = -1;
	int OliveFailFrameEnd = -1;
	int OliveDontFrameStart = -1;
	int OliveDontFrameEnd = -1;
	std::string SuccessState = "Success";
	std::string FailState = "Fail";
	std::string DontState = "Dont";

	GameEngineRender* Object1 = nullptr;
	float4 Object1Pos = float4::Zero;
	int Object1FrameStart = -1;
	int Object1FrameEnd = -1;
	GameEngineRender* Object2 = nullptr;
	float4 Object2Pos = float4::Zero;
	int Object2FrameStart = -1;
	int Object2FrameEnd = -1;
	GameEngineRender* Object3 = nullptr;
	float4 Object3Pos = float4::Zero;
	int Object3FrameStart = -1;
	int Object3FrameEnd = -1;
	GameEngineRender* Object4 = nullptr;
	float4 Object4Pos = float4::Zero;
	int Object4FrameStart = -1;
	int Object4FrameEnd = -1;
	GameEngineRender* Object5 = nullptr;
	float4 Object5Pos = float4::Zero;
	int Object5FrameStart = -1;
	int Object5FrameEnd = -1;

	float4 ObjScale = float4::Zero;

	std::string BackgroundLayer1_Name = std::string();
	std::string BackgroundLayer2_Name = std::string();
	std::string Object_Name = std::string();
	
};

