#include "FightingClass.h"

FightingClass::FightingClass()
{

}

FightingClass::~FightingClass()
{

}

void FightingClass::Start()
{
	SetImageName("Animation_Object_Fighting.bmp", "Animation_Background_Fighting.bmp");
	SetBackground();
	SetObjScale({ 50, 100 });
	SetOliveObj(0, 2, 3, 4, 5, 6, { 135, 14 });
	SetObj1(PM2RenderOrder::Menu2_Obj_2, 7, 9, { -5, 14 });
	SetObj2(PM2RenderOrder::Menu2_Obj_2, 10, 12, { 65, 14 });
	SetObj3(PM2RenderOrder::Menu2_Obj_2, 13, 13, { -135, 14 });
	SetObj4(PM2RenderOrder::Menu2_Obj_2, 14, 18, { -175, 14 });
	GetStatusVarianceMin().SetStatus({ .Stress = 0,.CombatSkill = 1, .CombatDefense = 0});
	GetStatusVarianceMax().SetStatus({ .Stress = 1,.CombatSkill = 1, .CombatDefense = 0 });
	SetPayGold(-30);
	ClassesAndJobs::Start();
}
