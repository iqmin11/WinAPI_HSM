#include "MagicClass.h"

MagicClass::MagicClass()
{

}

MagicClass::~MagicClass()
{

}

void MagicClass::Start()
{
	SetImageName("Animation_Object_Magic.bmp", "Animation_Background_Magic.bmp");
	SetBackground();
	SetObjScale({ 50, 100 });
	SetOliveObj(0, 11, 0, 3, 12, 13, { 125, 12 });
	SetObj1(PM2RenderOrder::Menu2_Obj_2, 14, 17, { -85, 14 });
	SetObj2(PM2RenderOrder::Menu2_Obj_2, 18, 19, { -25, 14 });
	SetObj3(PM2RenderOrder::Menu2_Obj_1, 20, 21, { 115, -30 });
	SetObj4(PM2RenderOrder::Menu2_Obj_1, 22, 23, { -87, -30 });
	SetObj5(PM2RenderOrder::Menu2_Obj_1, 24, 27, { -165, -37 });
	GetStatusVarianceMin().SetStatus({.Stress = 0, .MagicSkill = 1, .MagicAttack = 0});
	GetStatusVarianceMax().SetStatus({.Stress = 1,.MagicSkill = 1, .MagicAttack = 2 });
	SetPayGold(-60);
	ClassesAndJobs::Start();
}
