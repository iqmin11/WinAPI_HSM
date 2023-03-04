#include "PaintingClass.h"

PaintingClass::PaintingClass()
{

}

PaintingClass::~PaintingClass()
{

}

void PaintingClass::Start()
{
	SetImageName("Animation_Object_Painting.bmp", "Animation_Background_Painting.bmp");
	SetBackground();
	SetObjScale({ 50, 100 });
	SetOliveObj(0, 3, 4, 4, 5, 6, { -165, 12 });
	SetObj1(PM2RenderOrder::Menu2_Obj_2, 7, 9, { -85, 12 });
	SetObj2(PM2RenderOrder::Menu2_Obj_2, 10, 11, { -15, 12 });
	SetObj3(PM2RenderOrder::Menu2_Obj_2, 12, 17, { 115, 12 });
	GetStatusVarianceMin().SetStatus({  .Sensitivity = 0,.Stress = 0, .Art = 1 });
	GetStatusVarianceMax().SetStatus({ .Sensitivity = 1,.Stress = 1, .Art = 1});

	SetPayGold(-40);
	ClassesAndJobs::Start();
}
