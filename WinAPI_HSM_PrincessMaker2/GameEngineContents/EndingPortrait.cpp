#include "EndingPortrait.h"
#include <GameEngineCore/GameEngineRender.h>
#include "EndingDialog.h"
#include "Olive.h"

EndingPortrait::EndingPortrait()
{

}

EndingPortrait::~EndingPortrait()
{

}

void EndingPortrait::On()
{
	GameEngineObject::On();
	AcEndingDialog->On();
}

void EndingPortrait::Off()
{
	GameEngineObject::Off();
	AcEndingDialog->Off();
}

void EndingPortrait::Start()
{
	SetPos(ActorPos);
	Background = CreateRender("EndingPortrait.bmp", PM2RenderOrder::BackGround);
	Background->SetScaleToImage();
	OliveEnding = dynamic_cast<EndingLevel*>(GetLevel())->GetOliveEnding();
	Potrait = CreateRender(PM2RenderOrder::BackGroundObj);
	AcEndingDialog = GetLevel()->CreateActor<EndingDialog>(PM2ActorOrder::Dialog1);
	Off();
}

void EndingPortrait::Update(float _DeltaTime)
{
	switch (*OliveEnding)
	{
	case Ending::Null:
		break;
	case Ending::����:
		Potrait->SetImage("PrincessOfDarkness.bmp");
		AcEndingDialog->UpdateText("������, " + Olive::OlivePlayer->GetOliveFirstName() + "�� Ȧ���� ����� ���߰�,\n �ι� �ٽ� ���� ���ƿ��� �ʾҴٰ� �Ѵ١���\n�ø����� �ҽ��� ������ �ƹ��� �𸥴�.\n��, ������ �˻簡 ��������� ��������,\n ������ ������ ��� ���Ҵµ�, �� ������ \n���� ������ ����̾��ٰ� �Ѵ١���\n");
		break;
	case Ending::SM����:
		Potrait->SetImage("BondageQueen.bmp");
		AcEndingDialog->UpdateText("�׸��Ͽ� " + Olive::OlivePlayer->GetOliveFirstName() + "�� ��� Ŭ������ � �ϰ� �Ǿ��١�\n ��- �ơ�");
		break;
	case Ending::���氡�Ǻ���:
		Potrait->SetImage("CrimeBoss.bmp");
		AcEndingDialog->UpdateText("�׸��Ͽ� " + Olive::OlivePlayer->GetOliveFirstName() + "�� ������ ������ ������ ���ù����� ���� �԰�, ���氡�� �ҷ��踦 �ε帮�� ������ ������ �Ǿ��١�\n ��- �ơ�");
		break;
	case Ending::���¹�:
		Potrait->SetImage("Bandit.bmp");
		AcEndingDialog->UpdateText("�׸��Ͽ� " + Olive::OlivePlayer->GetOliveFirstName() + "�� �ް���� ���氡�� �����鼭, �ҷ������ ģ���� �Ǿ��١�\n ��- �ơ�");
		break;
	case Ending::���â��:
		Potrait->SetImage("RefineHarlot.bmp");
		AcEndingDialog->UpdateText("ȣ��ɿ� �鷶�� �ް���� �Ÿ��� ���� ��� �� " + Olive::OlivePlayer->GetOliveFirstName() + "��\n �װ���" + Olive::OlivePlayer->GetOliveFirstName() + "�� ����� ���̾��١���");
		break;
	case Ending::����:
		Potrait->SetImage("ConArtist.bmp");
		AcEndingDialog->UpdateText("�׸��Ͽ� " + Olive::OlivePlayer->GetOliveFirstName() + "�� ������ ���� �Ȱ� �Ǿ��١�\n ��- �ơ�");
		break;
	case Ending::â��:
		Potrait->SetImage("Harlot.bmp");
		AcEndingDialog->UpdateText("ȣ��ɿ� �鷶�� �ް���� �Ÿ��� ���� ��� �� " + Olive::OlivePlayer->GetOliveFirstName() + "��\n �װ���" + Olive::OlivePlayer->GetOliveFirstName() + "�� ����� ���̾��١���");
		break;
	case Ending::����:
		Potrait->SetImage("Queen.bmp");
		AcEndingDialog->UpdateText("�׸��Ͽ� " + Olive::OlivePlayer->GetOliveFirstName() + "�� �������κ��� ������ \n��¹޾�, �ձ��� ���ο� ������ �Ǿ���.");
		break;
	case Ending::���:
		Potrait->SetImage("PrimeMinister.bmp");
		AcEndingDialog->UpdateText("�׸��Ͽ� " + Olive::OlivePlayer->GetOliveFirstName() + "�� �ձ��� ����� �Ǳ�\n���� �ձÿ��� ��ġ ���θ� �����ߴ١�");
		break;
	case Ending::�ڻ�:
		Potrait->SetImage("Scholar.bmp");
		AcEndingDialog->UpdateText("�׸��Ͽ� " + Olive::OlivePlayer->GetOliveFirstName() + "�� �ո� ���п����� �й�\n�� �߱��ϴ� ��Ȱ�� �����ߴ١�");
		break;
	case Ending::���:
		Potrait->SetImage("CabinetMinister.bmp");
		AcEndingDialog->UpdateText("�׸��Ͽ� " + Olive::OlivePlayer->GetOliveFirstName() + "�� �ձ��� ����� �Ǿ�, \n���� �� ��ġ ���θ� �����ߴ١�");
		break;
	case Ending::���ֱ�:
		Potrait->SetImage("ArchBishop.bmp");
		AcEndingDialog->UpdateText("�׸��Ͽ� " + Olive::OlivePlayer->GetOliveFirstName() + "�� �ձ��� �ֱ��� �Ǳ� ��\n�Ͽ�, �ձÿ��� ���θ� �����ߴ١�");
		break;
	case Ending::�л�:
		Potrait->SetImage("Researcher.bmp");
		AcEndingDialog->UpdateText("�׸��Ͽ� " + Olive::OlivePlayer->GetOliveFirstName() + "�� �ո� ���п��� �л簡 ��\n��, �й��� ���� �ɾ��١�");
		break;
	case Ending::���ǰ�:
		Potrait->SetImage("Judge.bmp");
		AcEndingDialog->UpdateText("�׸��Ͽ� " + Olive::OlivePlayer->GetOliveFirstName() + "�� �ձ� ������ ���� ���ǰ�\n�� �Ǿ��١�");
		break;
	case Ending::����:
		Potrait->SetImage("Nun.bmp");
		AcEndingDialog->UpdateText("�׸��Ͽ� " + Olive::OlivePlayer->GetOliveFirstName() + "�� ���翡 ��, ������\n�μ��� �λ��� �����ߴ١�");
		break;
	case Ending::�ó�:
		Potrait->SetImage("LadyInWaiting.bmp");
		AcEndingDialog->UpdateText("�׸��Ͽ� " + Olive::OlivePlayer->GetOliveFirstName() + "�� ���� �ó�μ��� �λ�\n�� �����ߴ١�");
	default:
		break;
	}

	Potrait->SetScaleToImage();
}
