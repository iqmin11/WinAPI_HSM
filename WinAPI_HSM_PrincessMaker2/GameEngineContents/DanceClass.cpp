#include "DanceClass.h"

DanceClass::DanceClass()
{

}

DanceClass::~DanceClass()
{

}

void DanceClass::Start()
{
	SetImageName("Animation_Object_Dance.bmp", "Animation_Background_Dance.bmp");
	SetBackground();
	SetObjScale({ 50, 100 });
	SetOliveObj(0, 3, 4, 5, 6, 7, { 145, 14 });
	SetObj1(PM2RenderOrder::Menu2_Obj_2, 8, 11, { 55, 14 });
	SetObj2(PM2RenderOrder::Menu2_Obj_2, 12, 15, { -55, 14 });
	SetObj3(PM2RenderOrder::Menu2_Obj_2, 16, 17, { -155, 14 });
	GetStatusVarianceMin().SetStatus({.Constitution = 1, .Charisma = 0, .Stress = 0, .Art = 0 });
	GetStatusVarianceMax().SetStatus({ .Constitution = 1, .Charisma = 1, .Stress = 1, .Art = 1 });
	SetPayGold(-50);
	ClassesAndJobs::Start();
}
