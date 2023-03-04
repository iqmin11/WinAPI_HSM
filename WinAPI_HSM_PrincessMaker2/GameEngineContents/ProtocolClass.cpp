#include "ProtocolClass.h"

ProtocolClass::ProtocolClass()
{

}

ProtocolClass::~ProtocolClass()
{

}

void ProtocolClass::Start()
{
	SetImageName("Animation_Object_Protocol.bmp", "Animation_Background_Protocol.bmp");
	SetBackground();
	SetObjScale({ 50, 100 });
	SetOliveObj(0, 1, 2, 4, 5, 6, { 165, 12 });
	SetObj1(PM2RenderOrder::Menu2_Obj_2, 7, 8, { 95, 12 });
	SetObj2(PM2RenderOrder::Menu2_Obj_2, 9, 10, { -165, 12 });
	SetObj3(PM2RenderOrder::Menu2_Obj_2, 11, 12, { -85, 12 });
	SetObj4(PM2RenderOrder::Menu2_Obj_2, 13, 17, { 5, -3 });
	GetStatusVarianceMin().SetStatus({.Refinement = 1, .Stress = 0,.Decorum = 1 });
	GetStatusVarianceMax().SetStatus({ .Refinement = 1,.Stress = 1, .Decorum = 1 });
	SetPayGold(-40);
	ClassesAndJobs::Start();
}
