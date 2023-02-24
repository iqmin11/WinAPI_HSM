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
	SetObj1(7, 8, { -35, 12 });
	SetObj2(9, 10, { 45, 12 });
	SetObj3(11, 12, { -165, 12 });
	Classes::Start();
}

