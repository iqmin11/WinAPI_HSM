#include "ScheduleAnimationPlayer.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ScienceClass.h"

ScheduleAnimationPlayer::ScheduleAnimationPlayer()
{

}

ScheduleAnimationPlayer::~ScheduleAnimationPlayer()
{

}

void ScheduleAnimationPlayer::Start()
{
	GameEngineLevel* Level = GetLevel();
	SetPos(ActorPos);
	InitMenuFrameRender(PM2RenderOrder::Menu2, MenuFrameStyleEnum::Nomal);
	SetMenuFrameScale(BoxScale);
	
	AcScienceClass = Level->CreateActor<ScienceClass>(PM2ActorOrder::Menu2);
	AcScienceClass->SetPos(GetPos());
}

void ScheduleAnimationPlayer::Update(float _DeltaTime)
{
	
}
