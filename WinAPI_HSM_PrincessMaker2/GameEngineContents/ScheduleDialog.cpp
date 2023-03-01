#include "ScheduleDialog.h"

ScheduleDialog::ScheduleDialog()
{

}

ScheduleDialog::~ScheduleDialog()
{

}

void ScheduleDialog::UpdateCubeDialog(const ScheduleLabel& _Mug, const std::string_view& _Dialog)
{
	On();
	SetMugPic(ScheduleMugshot.find(_Mug)->second);
	SetUpdateText(_Dialog);
}

void ScheduleDialog::Start()
{
	Dialog::Start();
	SetScheduleMugshot();

	SetMugPic(ScheduleMugshot.find(ScheduleLabel::�ڿ�����)->second);
	SetMugLoc(MugShotLR::Left);
	SetPos(ActorPos);
}

void ScheduleDialog::SetScheduleMugshot()
{
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::�ڿ�����, "Mug_Barcleo.bmp"));
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::����, "Mug_Bartholomew.bmp"));
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::������, "Mug_CarlFox.bmp"));
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::�ù���, "Mug_Comstock.bmp"));
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::�̼�, "Mug_Filkins.bmp"));
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::������, "Mug_Kruger.bmp"));
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::������, "Mug_Leftor.bmp"));
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::����, "Mug_Putnam.bmp"));
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::����, "Mug_SisterLee.bmp"));
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::����, "Mug_Tobi.bmp"));
}
