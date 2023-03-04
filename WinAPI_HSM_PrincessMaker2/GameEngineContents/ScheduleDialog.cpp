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
	case ScheduleLabel::�ڿ�����:
		switch (_Situ)
		{
		case ScheduleSituation::ScheduleStart:
			SetUpdateText("���ݼ��� ��ũ����\n �������� ��� ���� ���а� ��\n���� ������ �� ����. �ź�����\n�� �ΰ��� ������ ���� ��\n��. �����̳� ������ ������ ��\n�� ������ �ʾ�.��");
			break;
		case ScheduleSituation::ScheduleEnd:
			SetUpdateText("�����÷� ������ ��ġ�ڴ�. ��\n�� ������ ������ ���� ����, \n�������ֱ�.��");
			break;
		default:
			break;
		}
		break;
	case ScheduleLabel::����:
		switch (_Situ)
		{
		case ScheduleSituation::ScheduleStart:
			SetUpdateText("�ý��� ����\n ��������, ���� ��ȸ�� ���ŵ�\n�� �����Դϴ�.��");
			break;
		case ScheduleSituation::ScheduleEnd:
			SetUpdateText("���̹� ������ ���÷� ���Դϴ�\n. �������� ���ֱ⸦ ����ϰ�\n��䡹");
			break;
		default:
			break;
		}
		break;
	case ScheduleLabel::������:
		switch (_Situ)
		{
		case ScheduleSituation::ScheduleStart:
			SetUpdateText("ũ��� �屺\n ������. ���� �ٷ� �ձ��� ����\n��, ������屺�� �̶� �Ҹ���� \n���� ���ϳ׽� ���̰�ũ��Ŵ�\n.��");
			break;
		case ScheduleSituation::ScheduleEnd:
			SetUpdateText("���̰����� ���Ǹ� ��ġ�ڴ١�");
			break;
		default:
			break;
		}
		break;
	case ScheduleLabel::�˼�:
		switch (_Situ)
		{
		case ScheduleSituation::ScheduleStart:
			SetUpdateText("�˻� ������\n ������, ���� �� ������ ���.\n���� ��, �̸��� ����Ʈ��. ��\n�����̶� �ҷ���. �� ������ ��\n�� ��ĥ���� �������̶� ������\n�ɰŴ�.��");
			break;
		case ScheduleSituation::ScheduleEnd:
			SetUpdateText("���ϴ� �̰ɷ� ���̴�. ��ҿ�\n�� ������ ������ ���� �����ϡ�");
			break;
		default:
			break;
		}
		break;
	case ScheduleLabel::������:
		switch (_Situ)
		{
		case ScheduleSituation::ScheduleStart:
			SetUpdateText("������ Į ����\n ���ο��� ���� ���ΰ� �ƴϴ�.\n���⿡ �������� �ʴ� �������� \n���Ǵ� ������ �Ѱ���� ���ϴ�\nü���� ���濡 ����.��");
			break;
		case ScheduleSituation::ScheduleEnd:
			SetUpdateText("���̰����� �ϴ� ������ ������\n�����ڴ�. ��� ������ ������\n���� ������.��");
			break;
		default:
			break;
		}
		break;
	case ScheduleLabel::����:
		switch (_Situ)
		{
		case ScheduleSituation::ScheduleStart:
			SetUpdateText("������ ��Ʈ��\n ���ȳ��ϼ���. ���� ����������\n �����Դϴ�. �����а� �Բ� ��\n�븶���� ��쵵�� ���ҡ�");
			break;
		case ScheduleSituation::ScheduleEnd:
			SetUpdateText("���׷� �̹� ���� ������ �̰���\n�� ��ġ�ڽ��ϴ١�");
			break;
		default:
			break;
		}
		break;
	case ScheduleLabel::�ù���:
		switch (_Situ)
		{
		case ScheduleSituation::ScheduleStart:
			SetUpdateText("���� �Ľ���\n ���ô� ����� ������ ǳ��Ӱ�\n���ݴϴ�. �� ������� �ô� ��\n���鿡�� ������ ����, â����\n�̷��� ����� ����. ��, �Բ�\n�����սô�. ������ �յ�����");
			break;
		case ScheduleSituation::ScheduleEnd:
			SetUpdateText("�������� ���÷� ���Դϴ�. ��\n����, �ø� ����ϴ� ������ ��\n�� �����䡹");
			break;
		default:
			break;
		}
		break;
	case ScheduleLabel::����:
		switch (_Situ)
		{
		case ScheduleSituation::ScheduleStart:
			SetUpdateText("��� ��Ʈ�罺\n ���� �Դ�. �� �����̴� ���κ�\n�� ���� �������� ���߿�����\n���ǹ����� ����ġ�� ���������");
			break;
		case ScheduleSituation::ScheduleEnd:
			SetUpdateText("���׷�, ������ �ٽ� ���ô١�\n����");
			break;
		default:
			break;
		}
		break;
	case ScheduleLabel::����:
		switch (_Situ)
		{
		case ScheduleSituation::ScheduleStart:
			SetUpdateText("���� ���� Ʈ��\n ���米�� ���߸� ��ǥ�ϴ� ����\n���� �־�, ���� �Ƿ��� Ŀ�ٶ� \n���Ⱑ �˴ϴ�. ������ ������\n��. �ڽ��� ���ؼ���");
			break;
		case ScheduleSituation::ScheduleEnd:
			SetUpdateText("���̹� ������ ���ñ��� �Դϴ١�");
			break;
		default:
			break;
		}
		break;
	case ScheduleLabel::�̼�:
		switch (_Situ)
		{
		case ScheduleSituation::ScheduleStart:
			SetUpdateText("�ձ�ȭ�� ��Ų��\n ������ �ձ�ȭ���� ��Ų����. \n�׸��� ���ؼ� ������ �ɿ����� \n������ �ֵ��� ����.��");
			break;
		case ScheduleSituation::ScheduleEnd:
			SetUpdateText("���̰����� �̹� ���¸� ��ġ��\n�١�");
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

	SetMugPic(ScheduleMugshot.find(ScheduleLabel::�ڿ�����)->second);
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
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::�ڿ�����, "Mug_Barcleo.bmp"));
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::����, "Mug_Bartholomew.bmp"));
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::������, "Mug_CarlFox.bmp"));
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::�ù���, "Mug_Comstock.bmp"));
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::�̼�, "Mug_Filkins.bmp"));
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::������, "Mug_Kruger.bmp"));
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::�˼�, "Mug_Leftor.bmp"));
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::����, "Mug_Putnam.bmp"));
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::����, "Mug_SisterLee.bmp"));
	ScheduleMugshot.insert(std::make_pair(ScheduleLabel::����, "Mug_Tobi.bmp"));
}

//void ScheduleDialog::SetScript()
//{
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::�ڿ�����, ScheduleSituation::ScheduleStart), "���ݼ��� ��ũ����\n �������� ��� ���� ���а� ��\n���� ������ �� ����. �ź�����\n�� �ΰ��� ������ ���� ��\n��. �����̳� ������ ������ ��\n�� ������ �ʾ�.��"));
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::����,     ScheduleSituation::ScheduleStart), "��� ��Ʈ�罺\n ���� �Դ�. �� �����̴� ���κ�\n�� ���� �������� ���߿�����\n���ǹ����� ����ġ�� ���������"));
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::������,   ScheduleSituation::ScheduleStart), "������ Į ����\n ���ο��� ���� ���ΰ� �ƴϴ�.\n���⿡ �������� �ʴ� �������� \n���Ǵ� ������ �Ѱ���� ���ϴ�\nü���� ���濡 ����.��"));
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::�ù���,   ScheduleSituation::ScheduleStart), "���� �Ľ���\n ���ô� ����� ������ ǳ��Ӱ�\n���ݴϴ�. �� ������� �ô� ��\n���鿡�� ������ ����, â����\n�̷��� ����� ����. ��, �Բ�\n�����սô�. ������ �յ�����"));
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::�̼�,     ScheduleSituation::ScheduleStart), "�ձ�ȭ�� ��Ų��\n ������ �ձ�ȭ���� ��Ų����. \n�׸��� ���ؼ� ������ �ɿ����� \n������ �ֵ��� ����.��"));
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::������,   ScheduleSituation::ScheduleStart), "ũ��� �屺\n ������. ���� �ٷ� �ձ��� ����\n��, ������屺�� �̶� �Ҹ���� \n���� ���ϳ׽� ���̰�ũ��Ŵ�\n.��"));
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::�˼�,   ScheduleSituation::ScheduleStart), "�˻� ������\n ������, ���� �� ������ ���.\n���� ��, �̸��� ����Ʈ��. ��\n�����̶� �ҷ���. �� ������ ��\n�� ��ĥ���� �������̶� ������\n�ɰŴ�.��"));
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::����,     ScheduleSituation::ScheduleStart), "������ ��Ʈ��\n ���ȳ��ϼ���. ���� ���������� �����Դϴ�. �����а� �Բ� �ǿ븶���� ��쵵�� ���ҡ�"));
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::����,     ScheduleSituation::ScheduleStart), "�ý��� ����\n ��������, ���� ��ȸ�� ���ŵ�\n�� �����Դϴ�.��"));
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::����,     ScheduleSituation::ScheduleStart), "���� ���� Ʈ��\n ���米�� ���߸� ��ǥ�ϴ� ����\n���� �־�, ���� �Ƿ��� Ŀ�ٶ� \n���Ⱑ �˴ϴ�. ������ ������\n��. �ڽ��� ���ؼ���"));
//	
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::�ڿ�����, ScheduleSituation::ScheduleEnd), "�ڿ����� ��"));
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::����,     ScheduleSituation::ScheduleEnd), "���� ��"));
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::������,   ScheduleSituation::ScheduleEnd), "������ ��"));
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::�ù���,   ScheduleSituation::ScheduleEnd), "�ù��� ��"));
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::�̼�,     ScheduleSituation::ScheduleEnd), "�̼� ��"));
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::������,   ScheduleSituation::ScheduleEnd), "������ ��"));
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::�˼�,   ScheduleSituation::ScheduleEnd), "�˼� ��"));
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::����,     ScheduleSituation::ScheduleEnd), "���� ��"));
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::����,     ScheduleSituation::ScheduleEnd), "���� ��"));
//	Script.insert(std::make_pair(ScheduleScript(ScheduleLabel::����,     ScheduleSituation::ScheduleEnd), "���� ��"));
//}