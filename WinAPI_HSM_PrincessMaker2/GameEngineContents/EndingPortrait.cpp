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
	case Ending::마왕:
		Potrait->SetImage("PrincessOfDarkness.bmp");
		AcEndingDialog->UpdateText("다음날, " + Olive::OlivePlayer->GetOliveFirstName() + "는 홀연히 모습을 감추고,\n 두번 다시 집에 돌아오지 않았다고 한다……\n올리브의 소식은 아직도 아무도 모른다.\n단, 떠돌이 검사가 용암지대의 동굴에서,\n 마왕의 축제를 잠시 보았는데, 그 마왕은 \n젊은 여자의 모습이었다고 한다……\n");
		break;
	case Ending::SM여왕:
		Potrait->SetImage("BondageQueen.bmp");
		AcEndingDialog->UpdateText("그리하여 " + Olive::OlivePlayer->GetOliveFirstName() + "는 비밀 클럽에서 쇼를 하게 되었다…\n 아- 아…");
		break;
	case Ending::암흑가의보스:
		Potrait->SetImage("CrimeBoss.bmp");
		AcEndingDialog->UpdateText("그리하여 " + Olive::OlivePlayer->GetOliveFirstName() + "는 집에서 가져온 돈으로 무시무시한 옷을 입고, 암흑가의 불략배를 두드리는 나날을 보내게 되었다…\n 아- 아…");
		break;
	case Ending::폭력배:
		Potrait->SetImage("Bandit.bmp");
		AcEndingDialog->UpdateText("그리하여 " + Olive::OlivePlayer->GetOliveFirstName() + "는 뒷골목의 암흑가에 있으면서, 불량배들의 친구가 되었다…\n 아- 아…");
		break;
	case Ending::고급창부:
		Potrait->SetImage("RefineHarlot.bmp");
		AcEndingDialog->UpdateText("호기심에 들렀던 뒷골목의 거리에 발을 딛게 된 " + Olive::OlivePlayer->GetOliveFirstName() + "…\n 그것이" + Olive::OlivePlayer->GetOliveFirstName() + "의 운명의 길이었다……");
		break;
	case Ending::사기꾼:
		Potrait->SetImage("ConArtist.bmp");
		AcEndingDialog->UpdateText("그리하여 " + Olive::OlivePlayer->GetOliveFirstName() + "는 사기꾼의 길을 걷게 되었다…\n 아- 아…");
		break;
	case Ending::창부:
		Potrait->SetImage("Harlot.bmp");
		AcEndingDialog->UpdateText("호기심에 들렀던 뒷골목의 거리에 발을 딛게 된 " + Olive::OlivePlayer->GetOliveFirstName() + "…\n 그것이" + Olive::OlivePlayer->GetOliveFirstName() + "의 운명의 길이었다……");
		break;
	case Ending::여왕:
		Potrait->SetImage("Queen.bmp");
		AcEndingDialog->UpdateText("그리하여 " + Olive::OlivePlayer->GetOliveFirstName() + "는 국왕으로부터 왕위를 \n계승받아, 왕국의 새로운 여왕이 되었다.");
		break;
	case Ending::재상:
		Potrait->SetImage("PrimeMinister.bmp");
		AcEndingDialog->UpdateText("그리하여 " + Olive::OlivePlayer->GetOliveFirstName() + "는 왕국의 재상이 되기\n위해 왕궁에서 정치 공부를 시작했다…");
		break;
	case Ending::박사:
		Potrait->SetImage("Scholar.bmp");
		AcEndingDialog->UpdateText("그리하여 " + Olive::OlivePlayer->GetOliveFirstName() + "는 왕립 대학원에서 학문\n을 추구하는 생활을 시작했다…");
		break;
	case Ending::대신:
		Potrait->SetImage("CabinetMinister.bmp");
		AcEndingDialog->UpdateText("그리하여 " + Olive::OlivePlayer->GetOliveFirstName() + "는 왕국의 대신이 되어, \n성에 들어가 정치 공부를 시작했다…");
		break;
	case Ending::대주교:
		Potrait->SetImage("ArchBishop.bmp");
		AcEndingDialog->UpdateText("그리하여 " + Olive::OlivePlayer->GetOliveFirstName() + "는 왕국의 주교가 되기 위\n하여, 왕궁에서 공부를 시작했다…");
		break;
	case Ending::학사:
		Potrait->SetImage("Researcher.bmp");
		AcEndingDialog->UpdateText("그리하여 " + Olive::OlivePlayer->GetOliveFirstName() + "는 왕립 대학원의 학사가 되\n어, 학문의 길을 걸었다…");
		break;
	case Ending::재판관:
		Potrait->SetImage("Judge.bmp");
		AcEndingDialog->UpdateText("그리하여 " + Olive::OlivePlayer->GetOliveFirstName() + "는 왕국 최초의 여성 재판관\n이 되었다…");
		break;
	case Ending::수녀:
		Potrait->SetImage("Nun.bmp");
		AcEndingDialog->UpdateText("그리하여 " + Olive::OlivePlayer->GetOliveFirstName() + "는 성당에 들어가, 성직자\n로서의 인생을 시작했다…");
		break;
	case Ending::궁녀:
		Potrait->SetImage("LadyInWaiting.bmp");
		AcEndingDialog->UpdateText("그리하여 " + Olive::OlivePlayer->GetOliveFirstName() + "는 성의 궁녀로서의 인생\n을 시작했다…");
	default:
		break;
	}

	Potrait->SetScaleToImage();
}
