#include "ScheduleAnimationPlayer.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>
#include "DanceClass.h"
#include "FencingClass.h"
#include "FightingClass.h"
#include "MagicClass.h"
#include "PaintingClass.h"
#include "PoetryClass.h"
#include "ProtocolClass.h"
#include "ScienceClass.h"
#include "StrategyClass.h"
#include "TheologyClass.h"

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

	AcDanceClass = Level->CreateActor<DanceClass>(PM2ActorOrder::Menu2);
	AcDanceClass->SetPos(GetPos());
	AcDanceClass->Off();

	AcFencingClass = Level->CreateActor<FencingClass>(PM2ActorOrder::Menu2);
	AcFencingClass->SetPos(GetPos());
	AcFencingClass->Off();

	AcFightingClass = Level->CreateActor<FightingClass>(PM2ActorOrder::Menu2);
	AcFightingClass->SetPos(GetPos());
	AcFightingClass->Off();

	AcMagicClass = Level->CreateActor<MagicClass>(PM2ActorOrder::Menu2);
	AcMagicClass->SetPos(GetPos());
	AcMagicClass->Off();

	AcPaintingClass = Level->CreateActor<PaintingClass>(PM2ActorOrder::Menu2);
	AcPaintingClass->SetPos(GetPos());
	AcPaintingClass->Off();

	AcPoetryClass = Level->CreateActor<PoetryClass>(PM2ActorOrder::Menu2);
	AcPoetryClass->SetPos(GetPos());
	AcPoetryClass->Off();

	AcProtocolClass = Level->CreateActor<ProtocolClass>(PM2ActorOrder::Menu2);
	AcProtocolClass->SetPos(GetPos());
	AcProtocolClass->Off();

	AcScienceClass = Level->CreateActor<ScienceClass>(PM2ActorOrder::Menu2);
	AcScienceClass->SetPos(GetPos());
	AcScienceClass->Off();
	
	AcStrategyClass = Level->CreateActor<StrategyClass>(PM2ActorOrder::Menu2);
	AcStrategyClass->SetPos(GetPos());
	AcStrategyClass->Off();

	AcTheologyClass = Level->CreateActor<TheologyClass>(PM2ActorOrder::Menu2);
	AcTheologyClass->SetPos(GetPos());
	AcTheologyClass->Off();
}

void ScheduleAnimationPlayer::Update(float _DeltaTime)
{
	
}
