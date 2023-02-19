#include "OpeningDate.h"
#include "ContentsEnums.h"
#include "Olive.h"

OpeningDate::OpeningDate()
{

}

OpeningDate::~OpeningDate()
{

}

void OpeningDate::UpdateOliveBirthDay()
{
	OliveBirthDay = Olive::OlivePlayer->GetOliveBirthDay();
	MonthNum.SetValue(OliveBirthDay.GetMonth());
	DayNum.SetValue(OliveBirthDay.GetDay());
	MonthNum.SetMove({ 120, 0 });
	DayNum.SetMove({ 250, 0 });
}

void OpeningDate::Start()
{
	SetPos({ 400,300 });
	
	OpeningDateRender = CreateRender("OpeningDate.bmp", PM2RenderOrder::Menu0);
	OpeningDateRender->SetScaleToImage();

	MonthNum.SetOwner(this);
	MonthNum.SetImage("OpeningDayNum.bmp", {40,63}, static_cast<int>(PM2RenderOrder::Menu0_Display),RGB(255, 0, 255));
	MonthNum.SetAlign(Align::Right);
	MonthNum.SetValue(11);
	MonthNum.SetMove({120, 0});

	DayNum.SetOwner(this);
	DayNum.SetImage("OpeningDayNum.bmp", { 40,63 }, static_cast<int>(PM2RenderOrder::Menu0_Display), RGB(255, 0, 255));
	DayNum.SetAlign(Align::Right);
	DayNum.SetValue(11);
	DayNum.SetMove({ 250, 0 });
	
	Off();
}
