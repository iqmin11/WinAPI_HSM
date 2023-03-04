#include "StrategyClass.h"

StrategyClass::StrategyClass()
{

}

StrategyClass::~StrategyClass()
{

}

void StrategyClass::Start()
{
	SetImageName("Animation_Object_Strategy.bmp", "Animation_Background_Strategy.bmp");
	SetBackground();
	SetObjScale({ 50, 100 });
	SetOliveObj(0, 1, 2, 4, 5, 6, { 125, 12 });
	SetObj1(PM2RenderOrder::Menu2_Obj_2, 7, 8, { -35, 12 });
	SetObj2(PM2RenderOrder::Menu2_Obj_2, 9, 10, { 45, 12 });
	SetObj3(PM2RenderOrder::Menu2_Obj_2, 11, 12, { -125, -11 });
	GetStatusVarianceMin().SetStatus({.Intelligence = 1, .Sensitivity = -1, .Stress = 0,.CombatSkill = 0 });
	GetStatusVarianceMax().SetStatus({ .Intelligence = 2, .Sensitivity = 0, .Stress = 1,.CombatSkill = 1 });
	SetPayGold(-50);
	ClassesAndJobs::Start();
}
