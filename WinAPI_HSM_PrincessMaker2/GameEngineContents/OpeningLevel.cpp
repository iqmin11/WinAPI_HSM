#include "OpeningLevel.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineBase/GameEngineFile.h>

#include "MousePoint.h"
#include "Olive.h"
#include "Caption.h"
#include "UpperDialog.h"
#include "BottomDialog.h"
#include "Cutscene.h"
#include "OpeningCredit.h"
#include "OpeningDate.h"
#include "Logo.h"
#include "ContentsEnums.h"

OpeningLevel::OpeningLevel()
{

}

OpeningLevel::~OpeningLevel()
{

}

void OpeningLevel::Loading()
{
	SoundLoad();
	ImageLoad();
	
	CreateActor<MousePoint>(PM2ActorOrder::MousePoint);
	AcCaption = CreateActor<Caption>();
	AcUpperDialog = CreateActor<UpperDialog>();
	AcBottomDialog = CreateActor<BottomDialog>();
	AcCutScene = CreateActor<Cutscene>();
	AcOpeningCredit = CreateActor<OpeningCredit>();
	AcOpeningDate = CreateActor<OpeningDate>();
	AcLogo = CreateActor<Logo>();

	if (!GameEngineInput::IsKey("2"))
	{
		GameEngineInput::CreateKey("2", '2');
	}
}

void OpeningLevel::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown("1"))
	{
		GameEngineCore::GetInst()->DebugSwitch();
	}
	
	float LocalDeltaTime = _DeltaTime;
	
	if (GameEngineInput::IsPress("2"))
	{
		LocalDeltaTime *= 16;
		Time += LocalDeltaTime;
	}
	else
	{
		Time += LocalDeltaTime;
	}

	if (true == GameEngineInput::IsDown("LevelChange"))
	{
		GameEngineCore::GetInst()->ChangeLevel("RaisingSim");
	}
	
	// ������ Ÿ�Ӷ���
	// 0~20 ������ ũ����, ~35 �ƽ�1,  ~75 �ƽ�2, ~115 �ƽ�3, ~119 ����ȭ��, ~122 �ձ��� ��¥,
	// ~143 �ƽ�4, ~148 ����ȭ��, ~ 172 �ƽ�5, ~200 �ƽ�6, ~205 ����ȭ��, ~215 �ƽ�7 
	if (0 <= Time && 20 > Time)//(0 <= Time && 20 > Time)
	{
		AcCutScene->On();
		AcCutScene->SelectBackgroundColor(BackgroundColor::Black);
		AcCutScene->OffCutScene();

		AcOpeningCredit->On();
		AcOpeningCredit->UpdateScroll(LocalDeltaTime);
	}
	else if (20 <= Time && 35 > Time)//(20 <= Time && 35 > Time)
	{
		AcOpeningCredit->Off();
		AcCutScene->SelectBackgroundColor(BackgroundColor::White);
		AcCutScene->OnCutScene(0);
		if (22 <= Time && 26 > Time)
		{
			AcCaption->On();
			AcCaption->SetUpdateText("�װ��� �Ϲ����� �ο��̾��١�");
		}
		else if (26 <= Time && 27 > Time)
		{
			AcCaption->Off();
		}
		else if (27 <= Time && 31 > Time)
		{
			AcCaption->On();
			AcCaption->SetUpdateText("��ȭ�� ��鿩�� ������ �����\n������ ���ձ� �տ� ��ǳ����ó�� ����������.");
		}
		else if (31 <= Time && 32 > Time)
		{
			AcCaption->Off();
		}
		else if (32 <= Time && 35 > Time)
		{
			AcCaption->On();
			AcCaption->SetUpdateText("������ �������� �Ÿ��� �ұ濡 �۽ο���.\n������ �Զ��� �������� ��ģ ��Ȳ�̾���.");
		}
	}
	else if (35 <= Time && 75 > Time)//(35 <= Time && 75 > Time)
	{
		AcCaption->Off();
		AcCutScene->OnCutScene(1);

		if (37 <= Time && 41 > Time)
		{
			AcCaption->On();
			AcCaption->SetUpdateText(std::string("�׶� �� ������ ����� ����˻簡 �־���. ���� �̸��� ") + FatherName + std::string(".") + std::string("\n�״� ������ ���հ��� �ο� ���� ������"));
		}
		else if (41 <= Time && 42 > Time)
		{
			AcCaption->Off();
		}
		else if (42 <= Time && 46 > Time)
		{
			AcCaption->On();
			AcCaption->SetUpdateText("�ʽ´��� �� ��, ������ ������ ������ " + FatherName + std::string(".") + std::string("\n�״� 1��1�� ���� ���� ���տ��� �¸��ߴ�."));
		}
		else if (46 <= Time && 47 > Time)
		{
			AcCaption->Off();
		}
		else if (47 <= Time && 51 > Time)
		{
			AcUpperDialog->On();
			AcUpperDialog->SetMugPic("Mug_Devil.bmp");
			AcUpperDialog->SetMugLoc(MugShotLR::Left);
			AcUpperDialog->SetUpdateText("����졦 ���� �й�١�");
		}
		else if (51 <= Time && 56 > Time)
		{
			AcUpperDialog->SetUpdateText("���׷��� ���ڿ�. �ʴ� ��°��\n�ο�°�?��");
		}
		else if (56 <= Time && 64 > Time)
		{
			AcUpperDialog->SetUpdateText("��Ÿ���� ���ø� ������ �ϴ��� ��.\n �ʿʹ� �ƹ� ��� ���� �����\n �ڵ��� ����� ���̴١�");
		}
		else if (64 <= Time && 65 > Time)
		{
			AcUpperDialog->Off();
		}
		else if (65 <= Time && 69 > Time)
		{
			AcCaption->On();
			AcCaption->SetUpdateText("�� ������ ���� " + FatherName + std::string("�� ����� �������� �ʴ´�."));
		}
		else if (69 <= Time && 70 > Time)
		{
			AcCaption->Off();
		}
		else if (70 <= Time && 74 > Time)
		{
			AcCaption->On();
			AcCaption->SetUpdateText("�� �� ������ ��ó ���� ���� ġ���ϱ� ����\n���븦 �̲��� ������ ���ư��١�");
		}
		else if (74 <= Time && 75 > Time)
		{
			AcCaption->Off();
		}
	}
	else if (75 <= Time && 115 > Time)//(75 <= Time && 115 > Time)
	{
		AcCutScene->OnCutScene(2);
		if (77 <= Time && 83 > Time)
		{
			AcUpperDialog->On();
			AcUpperDialog->SetMugPic("Mug_King.bmp");
			AcUpperDialog->SetMugLoc(MugShotLR::Right);
			AcUpperDialog->SetUpdateText("������, ��翩. �Ǹ��ϰ� �� ���ø� \n�����ּ̼ҡ�");
		}
		else if (83 <= Time && 92 > Time)
		{
			AcUpperDialog->SetUpdateText("���̹� ������ ����� ������ \n�������Ź��̿�. �Ͱ��� �����ٸ� \n�ùε�� �Բ� ������� �Կ䡦��");
		}
		else if (92 <= Time && 102 > Time)
		{
			AcBottomDialog->On();
			AcBottomDialog->SetMugPic("Mug_Queen.bmp");
			AcBottomDialog->SetMugLoc(MugShotLR::Left);
			AcBottomDialog->SetUpdateText("���� ���� �츮�鿡�� ������ \n�Ź��� ���� �յ� �������� ������ \n�ٲپ� �̰��� ���� ������ \n�ǵ��� ���ϰڽ��ϴ١�");
		}
		else if (102 <= Time && 114 > Time)
		{
			AcUpperDialog->SetUpdateText("�������ϴ� �Ͱ��� �λ��� ����\n����. �̰��� �ӹ��� ������ ��\n���� ������ �� ���ڴ���. ���� \n������ ��Ź�ϰڼҡ�");
		}
		else if (114 <= Time && 115 > Time)
		{
			AcUpperDialog->Off();
			AcBottomDialog->Off();
		}
	}
	else if (115 <= Time && 119 > Time)//(115 <= Time && 119> Time)
	{
		AcCutScene->SelectBackgroundColor(BackgroundColor::Black);
		AcCutScene->OffCutScene();
		if (116 <= Time && 119 > Time)
		{
			AcCaption->On();
			AcCaption->SetUpdateText("�̸��Ͽ� ���ÿ� ������ ���� ����� �ް� �� ��� " + FatherName + std::string("."));
		}
	}
	else if (119 <= Time && 122 > Time)//(119 <= Time && 122 > Time)
	{
		AcCaption->Off();
		AcOpeningDate->On();
	}
	else if (122 <= Time && 144 > Time)//(122 <= Time && 143 > Time)
	{
		AcCutScene->OnCutScene(3);
		AcOpeningDate->Off();
		if (125 <= Time && 130 > Time)
		{
			AcCaption->On();
			AcCaption->SetUpdateText("�׷��� ��� �Ƹ��ٿ� ��, " + FatherName + std::string("�� �̸��� �θ��� ���� ������ ����١�"));
		}
		else if (130 <= Time && 134 > Time)
		{
			AcCaption->On();
			AcCaption->SetUpdateText("����翩������");
		}
		else if (134 <= Time && 135 > Time)
		{
			AcCaption->Off();
		}
		else if (135 <= Time && 140 > Time)
		{
			AcCaption->On();
			AcCaption->SetUpdateText("�ϴÿ��� " + FatherName + std::string("�� �̸��� �θ��� ��Ҹ��� �鸰�١�"));
		}
		else if (140 <= Time && 141 > Time)
		{
			AcCaption->Off();
		}
		else if (141 <= Time && 144 > Time)
		{
			AcCaption->On();
			AcCaption->SetUpdateText("�÷��ٺ���, �� �ٱ��� ������ �� ������ ���� õõ�� ������ ����� ��������.");
		}
	}
	else if (144 <= Time && 149 > Time)//(143 <= Time && 148 > Time)
	{
		AcCaption->SetUpdateText("������� �޷��� " + FatherName + std::string(". �װ����� Ŀ�ٶ� ������� �� �־���."));
		AcCutScene->OffCutScene();
	}
	else if (149 <= Time && 172 > Time)//(148 <= Time && 172 > Time)
	{
		AcCutScene->OnCutScene(4);
		if (149 <= Time && 150 > Time)
		{
			AcCaption->Off();
		}
		else if (150 <= Time && 155 > Time)
		{
			AcCaption->SetUpdateText("�׸���, ���ӿ��� � ���ھ��̰���");
		}
		else if (155 <= Time && 156 > Time)
		{
			AcCaption->Off();
		}
		else if (156 <= Time && 161 > Time)
		{
			AcBottomDialog->On();
			AcBottomDialog->SetMugPic("Mug_Uranus_God.bmp");
			AcBottomDialog->SetMugLoc(MugShotLR::Right);
			AcBottomDialog->SetUpdateText("����翩������ �� �ҳ��� ��ȣ\n�� " + std::string("��ȣ�� �̸�") + std::string("...��"));
		}
		else if (161 <= Time && 171 > Time)
		{
			AcBottomDialog->SetUpdateText("���� ���̴� �¾�� ���ÿ� \n�̸������ �������� ���� �ȿ�\n�� �ڶ� ������ �������� ���� \n���� ���ϴ� ������ ��ȥ�� ��\n�� �ڡ���");
		}
		else if (171 <= Time && 172 > Time)
		{
			AcBottomDialog->Off();
		}
	}
	else if (172 <= Time && 200 > Time)//(172 <= Time && 200 > Time)
	{
		AcCutScene->OnCutScene(5);
		if (174 <= Time && 178 > Time)
		{
			AcBottomDialog->On();
			AcBottomDialog->SetUpdateText("���ٷ� ���� ��ſ��� �� ����\n�� �ñ�ڽ��ϴ١�");
		}
		else if (178 <= Time && 185 > Time)
		{
			AcBottomDialog->SetUpdateText("���� ���̰� ��� �͵� �״� ��\n�� ���� ��� �λ��� ������\n �Ǵ� ����, ���� ��� �ϱ� ��\n����");
		}
		else if (185 <= Time && 191 > Time)
		{
			AcBottomDialog->SetUpdateText("����� ���� ��ſ��� �޷��ִ� \n�̴ϴ�. �׷���, ��� ���̡���");
		}
		else if (191 <= Time && 198 > Time)
		{
			AcBottomDialog->SetUpdateText("���׷� ��Ź�帳�ϴ�. \n���� �׻� �ϴÿ��� ��ŵ� ��\n�ฦ ���Ѻ��ڽ��ϴ١�����");
		}
		else if (198 <= Time && 199 > Time)
		{
			AcBottomDialog->Off();
		}
	}
	else if (200 <= Time && 205 > Time)//(200 <= Time && 205 > Time)
	{
		AcCutScene->OffCutScene();
		if (200 <= Time && 205 > Time)
		{
			AcCaption->On();
			AcCaption->SetUpdateText("�׸��� 1���� �����١���");
		}
	}
	else if (205 <= Time && 215 > Time)//(205 <= Time && 215> Time)
	{
		AcCaption->Off();
		AcCutScene->OnCutScene(6);
		if (208 <= Time && 215 > Time)
		{
			AcLogo->On();
		}
	}
	else
	{
		GameEngineCore::GetInst()->ChangeLevel("RaisingSim");
	}
}

void OpeningLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	AcOlive = Olive::OlivePlayer;
	AcOpeningDate->UpdateOliveBirthDay();
	FatherName = AcOlive->GetOliveLastName();
}

void OpeningLevel::SoundLoad()
{
}

void OpeningLevel::ImageLoad()
{
	GameEngineDirectory Dir;

	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");

	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("MugShotFrame_God.BMP"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("MugShotFrame_Nomal.BMP"));
	
	Dir.Move("OpeningLevel");
	
	std::vector<GameEngineFile> AllFile = Dir.GetAllFile();
	for (size_t i = 0; i < AllFile.size() ; i++)
	{
		GameEngineResources::GetInst().ImageLoad(AllFile[i].GetFullPath());
	}
	
	Dir.Move("MugShot");
	AllFile = Dir.GetAllFile();
	for (size_t i = 0; i < AllFile.size(); i++)
	{
		GameEngineResources::GetInst().ImageLoad(AllFile[i].GetFullPath());
	}

	Dir.MoveParentToDirectory("Num");
	Dir.Move("Num");
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("OpeningDayNum.BMP"))->Cut(10, 1);
}
