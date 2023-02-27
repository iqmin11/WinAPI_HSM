#include "ScheduleAnimationPlayer.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>
#include "RaisingSimLevel.h"

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
	RaisingSimLevel* Level = dynamic_cast<RaisingSimLevel*>(GetLevel());
	SetPos(ActorPos);
	InitMenuFrameRender(PM2RenderOrder::Menu2, MenuFrameStyleEnum::Nomal);
	SetMenuFrameScale(BoxScale);

	AcDanceClass = Level->AcDanceClass;
	AcFencingClass = Level->AcFencingClass;
	AcFightingClass = Level->AcFightingClass;
	AcMagicClass = Level->AcMagicClass;
	AcPaintingClass = Level->AcPaintingClass;
	AcPoetryClass = Level->AcPoetryClass;
	AcProtocolClass = Level->AcProtocolClass;
	AcScienceClass = Level->AcScienceClass;
	AcStrategyClass = Level->AcStrategyClass;
	AcTheologyClass = Level->AcTheologyClass;

	Off();
}

void ScheduleAnimationPlayer::Update(float _DeltaTime)
{
	
}
