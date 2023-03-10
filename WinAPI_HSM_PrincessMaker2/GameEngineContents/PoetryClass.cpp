#include "PoetryClass.h"

PoetryClass::PoetryClass()
{

}

PoetryClass::~PoetryClass()
{

}

void PoetryClass::Start()
{
	SetImageName("Animation_Object_Poetry.bmp", "Animation_Background_Poetry.bmp");
	SetBackground();
	SetObjScale({ 50, 100 });
	SetOliveObj(0, 3, 4, 7, 8, 9, { 135, 12 });
	SetObj1(PM2RenderOrder::Menu2_Obj_2, 10, 11, { -5, 12 });
	SetObj2(PM2RenderOrder::Menu2_Obj_2, 12, 13, { 65, 12 });
	SetObj3(PM2RenderOrder::Menu2_Obj_2, 14, 15, { -115, -1 });
	GetStatusVarianceMin().SetStatus({.Intelligence = 0, .Refinement = 0, .Sensitivity = 1, .Stress = 0,.Art = 0 });
	GetStatusVarianceMax().SetStatus({ .Intelligence = 1, .Refinement = 1, .Sensitivity = 1,.Stress = 1, .Art = 2 });
	SetPayGold(-40);
	ClassesAndJobs::Start();
}
