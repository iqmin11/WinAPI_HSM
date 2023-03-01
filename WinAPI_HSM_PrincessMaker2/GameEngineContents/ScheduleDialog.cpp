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

	SetMugPic(ScheduleMugshot.find(ScheduleLabel::자연과학)->second);
	SetMugLoc(MugShotLR::Left);
	SetPos(ActorPos);
}

void ScheduleDialog::SetScheduleMugshot()
{
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::자연과학, "Mug_Barcleo.bmp"));
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::예법, "Mug_Bartholomew.bmp"));
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::격투술, "Mug_CarlFox.bmp"));
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::시문학, "Mug_Comstock.bmp"));
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::미술, "Mug_Filkins.bmp"));
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::군사학, "Mug_Kruger.bmp"));
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::격투술, "Mug_Leftor.bmp"));
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::마법, "Mug_Putnam.bmp"));
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::신학, "Mug_SisterLee.bmp"));
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::무용, "Mug_Tobi.bmp"));
}
