#include "ClassesAndJobs.h"
#include <GameEngineCore/GameEngineRender.h>

ClassesAndJobs::ClassesAndJobs()
{

}

ClassesAndJobs::~ClassesAndJobs()
{

}

void ClassesAndJobs::Start()
{
	if (nullptr != OliveObject)
	{
		OliveObject->ChangeAnimation(SuccessState);
	}

	if (nullptr != Object1)
	{
		Object1->ChangeAnimation("Obj1");
	}
	
	if (nullptr != Object2)
	{
		Object2->ChangeAnimation("Obj2");
	}

	if (nullptr != Object3)
	{
		Object3->ChangeAnimation("Obj3");
	}

	if (nullptr != Object4)
	{
		Object4->ChangeAnimation("Obj4");
	}

	if (nullptr != Object5)
	{
		Object5->ChangeAnimation("Obj5");
	}

	SetPos(ActorPos);
	Off();
}

void ClassesAndJobs::SetImageName(const std::string_view& _Obj, const std::string_view& _Back1, const std::string_view& _Back2)
{
	Object_Name = _Obj;
	BackgroundLayer1_Name = _Back1;
	BackgroundLayer2_Name = _Back2;
}

void ClassesAndJobs::SetBackground()
{
	BackgroundLayer1 = CreateRender(BackgroundLayer1_Name, PM2RenderOrder::Menu2_Background_1);
	BackgroundLayer1->SetScaleToImage();
	if (0 != BackgroundLayer2_Name.size())
	{
		BackgroundLayer2 = CreateRender(BackgroundLayer2_Name, PM2RenderOrder::Menu2_Background_1);
		BackgroundLayer2->SetScaleToImage();
	}
}

void ClassesAndJobs::SetOliveObj(int _SuccessStart, int _SuccessEnd, int _FailStart, int _FailEnd, int _DontStart, int _DontEnd, const float4& _Pos)
{
	OliveSuccessFrameStart = _SuccessStart;
	OliveSuccessFrameEnd = _SuccessEnd;
	OliveFailFrameStart = _FailStart;
	OliveFailFrameEnd = _FailEnd;
	OliveDontFrameStart = _DontStart;
	OliveDontFrameEnd = _DontEnd;
	OliveObjectPos = _Pos;

	OliveObject = CreateRender(PM2RenderOrder::Menu2_Obj_2);
	OliveObject->SetScale(ObjScale);
	OliveObject->SetPosition(OliveObjectPos);
	OliveObject->CreateAnimation({ .AnimationName = SuccessState, .ImageName = Object_Name, .Start = OliveSuccessFrameStart , .End = OliveSuccessFrameEnd ,.InterTime = 0.2f });
	OliveObject->CreateAnimation({ .AnimationName = FailState, .ImageName = Object_Name, .Start = OliveFailFrameStart , .End = OliveFailFrameEnd ,.InterTime = 0.2f });
	OliveObject->CreateAnimation({ .AnimationName = DontState, .ImageName = Object_Name, .Start = OliveDontFrameStart , .End = OliveDontFrameEnd ,.InterTime = 0.2f });
}

void ClassesAndJobs::SetObj1(PM2RenderOrder _Order, int _Start, int _End, const float4& _Pos)
{
	Object1FrameStart = _Start;
	Object1FrameEnd = _End;
	Object1Pos = _Pos;
	Object1 = CreateRender(_Order);
	Object1->SetScale(ObjScale);
	Object1->SetPosition(Object1Pos);
	Object1->CreateAnimation({ .AnimationName = "Obj1", .ImageName = Object_Name, .Start = Object1FrameStart , .End = Object1FrameEnd ,.InterTime = 0.2f });
}

void ClassesAndJobs::SetObj2(PM2RenderOrder _Order, int _Start, int _End, const float4& _Pos)
{
	Object2FrameStart = _Start;
	Object2FrameEnd = _End;
	Object2Pos = _Pos;
	Object2 = CreateRender(_Order);
	Object2->SetScale(ObjScale);
	Object2->SetPosition(Object2Pos);
	Object2->CreateAnimation({ .AnimationName = "Obj2", .ImageName = Object_Name, .Start = Object2FrameStart , .End = Object2FrameEnd ,.InterTime = 0.2f });
}

void ClassesAndJobs::SetObj3(PM2RenderOrder _Order, int _Start, int _End, const float4& _Pos)
{
	Object3FrameStart = _Start;
	Object3FrameEnd = _End;
	Object3Pos = _Pos;
	Object3 = CreateRender(_Order);
	Object3->SetScale(ObjScale);
	Object3->SetPosition(Object3Pos);
	Object3->CreateAnimation({ .AnimationName = "Obj3", .ImageName = Object_Name, .Start = Object3FrameStart , .End = Object3FrameEnd ,.InterTime = 0.2f });
}

void ClassesAndJobs::SetObj4(PM2RenderOrder _Order, int _Start, int _End, const float4& _Pos)
{
	Object4FrameStart = _Start;
	Object4FrameEnd = _End;
	Object4Pos = _Pos;
	Object4 = CreateRender(_Order);
	Object4->SetScale(ObjScale);
	Object4->SetPosition(Object4Pos);
	Object4->CreateAnimation({ .AnimationName = "Obj4", .ImageName = Object_Name, .Start = Object4FrameStart , .End = Object4FrameEnd ,.InterTime = 0.2f });
}

void ClassesAndJobs::SetObj5(PM2RenderOrder _Order, int _Start, int _End, const float4& _Pos)
{
	Object5FrameStart = _Start;
	Object5FrameEnd = _End;
	Object5Pos = _Pos;
	Object5 = CreateRender(_Order);
	Object5->SetScale(ObjScale);
	Object5->SetPosition(Object5Pos);
	Object5->CreateAnimation({ .AnimationName = "Obj5", .ImageName = Object_Name, .Start = Object5FrameStart , .End = Object5FrameEnd ,.InterTime = 0.2f });
}
