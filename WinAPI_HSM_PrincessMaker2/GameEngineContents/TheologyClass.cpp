#include "TheologyClass.h"

TheologyClass::TheologyClass()
{

}

TheologyClass::~TheologyClass()
{

}

void TheologyClass::Start()
{
	SetImageName("Animation_Object_Theology.bmp", "Animation_Background_Theology.bmp");
	SetBackground();
	SetObjScale({ 50, 100 });
	SetOliveObj(0, 1, 2, 3, 4, 5, { 85, 12 });
	SetObj1(PM2RenderOrder::Menu2_Obj_2, 6, 7, { 175, 12 });
	SetObj2(PM2RenderOrder::Menu2_Obj_2, 8, 9, { -95, 12 });
	SetObj3(PM2RenderOrder::Menu2_Obj_2, 10, 11, { -175, 12 });
	SetObj4(PM2RenderOrder::Menu2_Obj_2, 12, 15, { -25, 12 });
	GetStatusVarianceMin().SetStatus({.Intelligence = 1, .Faith = 1, .MagicDefense = 0});
	GetStatusVarianceMax().SetStatus({ .Intelligence = 1, .Faith = 2, .MagicDefense = 1 });
	ClassesAndJobs::Start();
}
