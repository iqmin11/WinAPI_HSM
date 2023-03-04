#include "ScheduleDialog.h"
#include <GameEnginePlatform/GameEngineInput.h>

ScheduleDialog::ScheduleDialog()
{

}

ScheduleDialog::~ScheduleDialog()
{

}

void ScheduleDialog::UpdateScheduleDialog(const ScheduleLabel& _Mug, const std::string_view& _Dialog)
{
	On();
	SetMugPic(ScheduleMugshot.find(_Mug)->second);
	SetUpdateText(_Dialog);
}

void ScheduleDialog::UpdateScheduleDialog(ScheduleLabel _Char, ScheduleSituation _Situ)
{
	On();
	SetMugPic(ScheduleMugshot.find(_Char)->second);
	switch (_Char)
	{
	case ScheduleLabel::Null:
		break;
	case ScheduleLabel::자연과학:
		switch (_Situ)
		{
		case ScheduleSituation::ScheduleStart:
			SetUpdateText("연금술사 버크레오\n 「세상의 모든 일은 수학과 물\n리로 설명할 수 있지. 신비주의\n는 인간의 무지가 만들어낸 산\n물. 기적이나 마법도 과학적 현\n상에 지나지 않아.」");
			break;
		case ScheduleSituation::ScheduleEnd:
			SetUpdateText("「오늘로 수업을 마치겠다. 모\n두 과학의 마음을 잊지 말고, \n정진해주길.」");
			break;
		default:
			break;
		}
		break;
	case ScheduleLabel::신학:
		switch (_Situ)
		{
		case ScheduleSituation::ScheduleStart:
			SetUpdateText("시스터 리이\n 「여러분, 저는 교회의 여신도\n인 리이입니다.」");
			break;
		case ScheduleSituation::ScheduleEnd:
			SetUpdateText("「이번 수업은 오늘로 끝입니다\n. 다음에도 와주기를 기대하겠\n어요」");
			break;
		default:
			break;
		}
		break;
	case ScheduleLabel::군사학:
		switch (_Situ)
		{
		case ScheduleSituation::ScheduleStart:
			SetUpdateText("크루거 장군\n 「제군. 내가 바로 왕국의 상장\n군, 『백승장군』 이라 불리우는 \n엘윈 요하네스 오이겐크루거다\n.」");
			break;
		case ScheduleSituation::ScheduleEnd:
			SetUpdateText("「이것으로 강의를 마치겠다」");
			break;
		default:
			break;
		}
		break;
	case ScheduleLabel::검술:
		switch (_Situ)
		{
		case ScheduleSituation::ScheduleStart:
			SetUpdateText("검사 레프톨\n 「여어, 내가 이 도장의 사범.\n성은 올, 이름은 레프트다. 레\n프톨이라 불러줘. 내 지도는 조\n금 거칠지만 실전형이라 도움이\n될거다.」");
			break;
		case ScheduleSituation::ScheduleEnd:
			SetUpdateText("「일단 이걸로 끝이다. 평소에\n도 수련을 게을리 하지 말도록」");
			break;
		default:
			break;
		}
		break;
	case ScheduleLabel::격투술:
		switch (_Situ)
		{
		case ScheduleSituation::ScheduleStart:
			SetUpdateText("격투가 칼 폭스\n 「싸움은 검이 전부가 아니다.\n무기에 의존하지 않는 격투술의 \n극의는 공격을 한계까지 피하는\n체술의 습득에 있지.」");
			break;
		case ScheduleSituation::ScheduleEnd:
			SetUpdateText("「이것으로 일단 격투술 수업을\n끝내겠다. 모두 정진을 게을리\n하지 말도록.」");
			break;
		default:
			break;
		}
		break;
	case ScheduleLabel::마법:
		switch (_Situ)
		{
		case ScheduleSituation::ScheduleStart:
			SetUpdateText("마법사 패트남\n 「안녕하세요. 제가 마법교실의\n 선생입니다. 여러분과 함께 실\n용마법을 배우도록 하죠」");
			break;
		case ScheduleSituation::ScheduleEnd:
			SetUpdateText("「그럼 이번 마법 교실은 이것으\n로 마치겠습니다」");
			break;
		default:
			break;
		}
		break;
	case ScheduleLabel::시문학:
		switch (_Situ)
		{
		case ScheduleSituation::ScheduleStart:
			SetUpdateText("시인 컴스톡\n 「시는 사람의 마음을 풍요롭게\n해줍니다. 옛 사람들의 시는 우\n리들에게 남겨진 보물, 창작은\n미래에 남기는 유산. 자, 함께\n공부합시다. 문학의 왕도를」");
			break;
		case ScheduleSituation::ScheduleEnd:
			SetUpdateText("「수업은 오늘로 끝입니다. 여\n러분, 시를 사랑하는 마음을 잊\n지 마세요」");
			break;
		default:
			break;
		}
		break;
	case ScheduleLabel::예법:
		switch (_Situ)
		{
		case ScheduleSituation::ScheduleStart:
			SetUpdateText("노사 바트사스\n 「잘 왔다. 이 늙은이는 예로부\n터 전해 내려오는 궁중예법과\n예의범절을 가르치는 사람이지」");
			break;
		case ScheduleSituation::ScheduleEnd:
			SetUpdateText("「그럼, 다음에 다시 봅시다…\n…」");
			break;
		default:
			break;
		}
		break;
	case ScheduleLabel::무용:
		switch (_Situ)
		{
		case ScheduleSituation::ScheduleStart:
			SetUpdateText("무용 선생 트베\n 「사교계 데뷔를 목표하는 여성\n에게 있어, 무용 실력은 커다란 \n무기가 됩니다. 열심히 익히세\n요. 자신을 위해서」");
			break;
		case ScheduleSituation::ScheduleEnd:
			SetUpdateText("「이번 레슨은 오늘까지 입니다」");
			break;
		default:
			break;
		}
		break;
	case ScheduleLabel::미술:
		switch (_Situ)
		{
		case ScheduleSituation::ScheduleStart:
			SetUpdateText("왕궁화가 필킨스\n 「내가 왕궁화가인 필킨스다. \n그림을 통해서 예술의 심오함을 \n가르쳐 주도록 하지.」");
			break;
		case ScheduleSituation::ScheduleEnd:
			SetUpdateText("「이것으로 이번 강좌를 마치겠\n다」");
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void ScheduleDialog::Start()
{
	Dialog::Start();
	SetScheduleMugshot();
	//SetSituation();

	SetMugPic(ScheduleMugshot.find(ScheduleLabel::자연과학)->second);
	SetMugLoc(MugShotLR::Left);
	SetPos(ActorPos);
}

void ScheduleDialog::Update(float _DeltaTime)
{
	if (IsFirstUpdate)
	{
		IsFirstUpdate = false;
		return;
	}

	if (GameEngineInput::IsUp("EngineMouseRight"))
	{
		Off();
		IsFirstUpdate = true;
	}
	Dialog::Update(_DeltaTime);
}

void ScheduleDialog::SetScheduleMugshot()
{
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::자연과학, "Mug_Barcleo.bmp"));
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::예법, "Mug_Bartholomew.bmp"));
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::격투술, "Mug_CarlFox.bmp"));
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::시문학, "Mug_Comstock.bmp"));
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::미술, "Mug_Filkins.bmp"));
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::군사학, "Mug_Kruger.bmp"));
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::검술, "Mug_Leftor.bmp"));
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::마법, "Mug_Putnam.bmp"));
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::신학, "Mug_SisterLee.bmp"));
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::무용, "Mug_Tobi.bmp"));
}

//void ScheduleDialog::SetScript()
//{
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::자연과학, ScheduleSituation::ScheduleStart), "연금술사 버크레오\n 「세상의 모든 일은 수학과 물\n리로 설명할 수 있지. 신비주의\n는 인간의 무지가 만들어낸 산\n물. 기적이나 마법도 과학적 현\n상에 지나지 않아.」"));
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::예법,     ScheduleSituation::ScheduleStart), "노사 바트사스\n 「잘 왔다. 이 늙은이는 예로부\n터 전해 내려오는 궁중예법과\n예의범절을 가르치는 사람이지」"));
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::격투술,   ScheduleSituation::ScheduleStart), "격투가 칼 폭스\n 「싸움은 검이 전부가 아니다.\n무기에 의존하지 않는 격투술의 \n극의는 공격을 한계까지 피하는\n체술의 습득에 있지.」"));
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::시문학,   ScheduleSituation::ScheduleStart), "시인 컴스톡\n 「시는 사람의 마음을 풍요롭게\n해줍니다. 옛 사람들의 시는 우\n리들에게 남겨진 보물, 창작은\n미래에 남기는 유산. 자, 함께\n공부합시다. 문학의 왕도를」"));
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::미술,     ScheduleSituation::ScheduleStart), "왕궁화가 필킨스\n 「내가 왕궁화가인 필킨스다. \n그림을 통해서 예술의 심오함을 \n가르쳐 주도록 하지.」"));
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::군사학,   ScheduleSituation::ScheduleStart), "크루거 장군\n 「제군. 내가 바로 왕국의 상장\n군, 『백승장군』 이라 불리우는 \n엘윈 요하네스 오이겐크루거다\n.」"));
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::검술,   ScheduleSituation::ScheduleStart), "검사 레프톨\n 「여어, 내가 이 도장의 사범.\n성은 올, 이름은 레프트다. 레\n프톨이라 불러줘. 내 지도는 조\n금 거칠지만 실전형이라 도움이\n될거다.」"));
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::마법,     ScheduleSituation::ScheduleStart), "마법사 패트남\n 「안녕하세요. 제가 마법교실의 선생입니다. 여러분과 함께 실용마법을 배우도록 하죠」"));
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::신학,     ScheduleSituation::ScheduleStart), "시스터 리이\n 「여러분, 저는 교회의 여신도\n인 리이입니다.」"));
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::무용,     ScheduleSituation::ScheduleStart), "무용 선생 트베\n 「사교계 데뷔를 목표하는 여성\n에게 있어, 무용 실력은 커다란 \n무기가 됩니다. 열심히 익히세\n요. 자신을 위해서」"));
//	
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::자연과학, ScheduleSituation::ScheduleEnd), "자연과학 끝"));
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::예법,     ScheduleSituation::ScheduleEnd), "예법 끝"));
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::격투술,   ScheduleSituation::ScheduleEnd), "격투술 끝"));
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::시문학,   ScheduleSituation::ScheduleEnd), "시문학 끝"));
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::미술,     ScheduleSituation::ScheduleEnd), "미술 끝"));
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::군사학,   ScheduleSituation::ScheduleEnd), "군사학 끝"));
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::검술,   ScheduleSituation::ScheduleEnd), "검술 끝"));
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::마법,     ScheduleSituation::ScheduleEnd), "마법 끝"));
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::신학,     ScheduleSituation::ScheduleEnd), "신학 끝"));
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::무용,     ScheduleSituation::ScheduleEnd), "무용 끝"));
//}