#include "FencingClass.h"

FencingClass::FencingClass()
{

}

FencingClass::~FencingClass()
{

}

void FencingClass::Start()
{
	SetImageName("Animation_Object_Fencing.bmp", "Animation_Background_Fencing.bmp");
	SetBackground();
	SetObjScale({ 50, 100 });
	SetOliveObj(0, 3, 4, 5, 6, 7, { 165, 12 });
	SetObj1(PM2RenderOrder::Menu2_Obj_2, 8, 11, { 105, 12 });
	SetObj2(PM2RenderOrder::Menu2_Obj_2, 12, 15, { -85, 12 });
	SetObj3(PM2RenderOrder::Menu2_Obj_2, 16, 20, { -155, 12 });
	SetObj4(PM2RenderOrder::Menu2_Obj_2, 21, 24, { 5, -20 });
	GetStatusVarianceMin().SetStatus({.CombatSkill = 0, .CombatAttack = 1});
	GetStatusVarianceMax().SetStatus({ .CombatSkill = 1, .CombatAttack = 1 });
	ClassesAndJobs::Start();
}
