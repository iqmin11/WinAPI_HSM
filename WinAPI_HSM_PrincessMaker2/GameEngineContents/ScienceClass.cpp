#include "ScienceClass.h"


ScienceClass::ScienceClass()
{

}

ScienceClass::~ScienceClass()
{

}

void ScienceClass::Start()
{
	SetImageName("Animation_Object_Science.bmp", "Animation_Background_Science.bmp");
	SetBackground();
	SetObjScale({ 50, 100 });
	SetOliveObj(0, 1, 2, 4, 5, 6, { 125, 12 });
	SetObj1(PM2RenderOrder::Menu2_Obj_2, 7, 8, { -35, 12 });
	SetObj2(PM2RenderOrder::Menu2_Obj_2, 9, 10, { 45, 12 });
	SetObj3(PM2RenderOrder::Menu2_Obj_2, 11, 12, { -165, 12 });
	GetStatusVarianceMin().SetStatus({.Intelligence = 1, .Faith = 0, .Stress = 0,.MagicDefense = 0 });
	GetStatusVarianceMax().SetStatus({ .Intelligence = 4, .Faith = 0,.Stress = 1, .MagicDefense = 0 });
	SetPayGold(-30);
	ClassesAndJobs::Start();
}

