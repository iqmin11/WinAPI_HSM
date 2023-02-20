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
	
	// 오프닝 타임라인
	// 0~20 오프닝 크레딧, ~35 컷신1,  ~75 컷신2, ~115 컷신3, ~119 검은화면, ~122 왕국력 날짜,
	// ~143 컷신4, ~148 검은화면, ~ 172 컷신5, ~200 컷신6, ~205 검은화면, ~215 컷신7 
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
			AcCaption->SetUpdateText("그것은 일방적인 싸움이었다…");
		}
		else if (26 <= Time && 27 > Time)
		{
			AcCaption->Off();
		}
		else if (27 <= Time && 31 > Time)
		{
			AcCaption->On();
			AcCaption->SetUpdateText("평화에 길들여진 수도의 군대는\n막강한 마왕군 앞에 추풍낙엽처럼 쓰러져갔다.");
		}
		else if (31 <= Time && 32 > Time)
		{
			AcCaption->Off();
		}
		else if (32 <= Time && 35 > Time)
		{
			AcCaption->On();
			AcCaption->SetUpdateText("성벽은 무너지고 거리는 불길에 휩싸였다.\n수도의 함락은 목전까지 닥친 상황이었다.");
		}
	}
	else if (35 <= Time && 75 > Time)//(35 <= Time && 75 > Time)
	{
		AcCaption->Off();
		AcCutScene->OnCutScene(1);

		if (37 <= Time && 41 > Time)
		{
			AcCaption->On();
			AcCaption->SetUpdateText(std::string("그때 그 참상을 목격한 방랑검사가 있었다. 그의 이름은 ") + FatherName + std::string(".") + std::string("\n그는 스스로 마왕과의 싸움에 몸을 던졌다"));
		}
		else if (41 <= Time && 42 > Time)
		{
			AcCaption->Off();
		}
		else if (42 <= Time && 46 > Time)
		{
			AcCaption->On();
			AcCaption->SetUpdateText("초승달이 뜬 밤, 마왕의 진영에 잠입한 " + FatherName + std::string(".") + std::string("\n그는 1대1의 결투 끝에 마왕에게 승리했다."));
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
			AcUpperDialog->SetUpdateText("「우우… 나의 패배다」");
		}
		else if (51 <= Time && 56 > Time)
		{
			AcUpperDialog->SetUpdateText("「그러나 용자여. 너는 어째서\n싸우는가?」");
		}
		else if (56 <= Time && 64 > Time)
		{
			AcUpperDialog->SetUpdateText("「타락한 도시를 벌함은 하늘의 뜻.\n 너와는 아무 상관 없는 어리석은\n 자들이 멸망할 뿐이다」");
		}
		else if (64 <= Time && 65 > Time)
		{
			AcUpperDialog->Off();
		}
		else if (65 <= Time && 69 > Time)
		{
			AcCaption->On();
			AcCaption->SetUpdateText("그 질문에 대한 " + FatherName + std::string("의 대답은 전해지지 않는다."));
		}
		else if (69 <= Time && 70 > Time)
		{
			AcCaption->Off();
		}
		else if (70 <= Time && 74 > Time)
		{
			AcCaption->On();
			AcCaption->SetUpdateText("얼마 후 마왕은 상처 입은 몸을 치료하기 위해\n군대를 이끌고 지저로 돌아갔다…");
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
			AcUpperDialog->SetUpdateText("「오오, 용사여. 훌륭하게 이 도시를 \n구해주셨소」");
		}
		else if (83 <= Time && 92 > Time)
		{
			AcUpperDialog->SetUpdateText("「이번 전쟁은 어리석은 짐에게 \n내려진신벌이오. 귀공이 없었다면 \n시민들과 함께 멸망했을 게요…」");
		}
		else if (92 <= Time && 102 > Time)
		{
			AcBottomDialog->On();
			AcBottomDialog->SetMugPic("Mug_Queen.bmp");
			AcBottomDialog->SetMugLoc(MugShotLR::Left);
			AcBottomDialog->SetUpdateText("「이 일은 우리들에게 내려진 \n신벌… 저도 왕도 이제부터 마음을 \n바꾸어 이곳이 좋은 도읍이 \n되도록 일하겠습니다」");
		}
		else if (102 <= Time && 114 > Time)
		{
			AcUpperDialog->SetUpdateText("「보아하니 귀공도 부상을 당했\n구려. 이곳에 머물며 도읍의 재\n건을 도와줄 순 없겠는지. 짐이 \n간곡히 부탁하겠소」");
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
			AcCaption->SetUpdateText("이리하여 도시에 정착해 왕의 녹봉을 받게 된 용사 " + FatherName + std::string("."));
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
			AcCaption->SetUpdateText("그러던 어느 아름다운 밤, " + FatherName + std::string("의 이름을 부르는 듯한 느낌이 들었다…"));
		}
		else if (130 <= Time && 134 > Time)
		{
			AcCaption->On();
			AcCaption->SetUpdateText("「용사여……」");
		}
		else if (134 <= Time && 135 > Time)
		{
			AcCaption->Off();
		}
		else if (135 <= Time && 140 > Time)
		{
			AcCaption->On();
			AcCaption->SetUpdateText("하늘에서 " + FatherName + std::string("의 이름을 부르는 목소리가 들린다…"));
		}
		else if (140 <= Time && 141 > Time)
		{
			AcCaption->Off();
		}
		else if (141 <= Time && 144 > Time)
		{
			AcCaption->On();
			AcCaption->SetUpdateText("올려다보니, 한 줄기의 유성이 긴 꼬리를 끌며 천천히 눈앞의 언덕에 떨어졌다.");
		}
	}
	else if (144 <= Time && 149 > Time)//(143 <= Time && 148 > Time)
	{
		AcCaption->SetUpdateText("언덕으로 달려간 " + FatherName + std::string(". 그곳에는 커다란 빛덩어리가 떠 있었다."));
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
			AcCaption->SetUpdateText("그리고, 빛속에는 어린 여자아이가…");
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
			AcBottomDialog->SetUpdateText("「용사여…나는 이 소녀의 수호\n자 " + std::string("수호신 이름") + std::string("...」"));
		}
		else if (161 <= Time && 171 > Time)
		{
			AcBottomDialog->SetUpdateText("「그 아이는 태어나서 오늘에 \n이르기까지 성스러운 빛의 안에\n서 자라 현세의 더러움을 일절 \n알지 못하는 순수한 영혼을 지\n닌 자…」");
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
			AcBottomDialog->SetUpdateText("「바로 지금 당신에게 이 아이\n를 맡기겠습니다」");
		}
		else if (178 <= Time && 185 > Time)
		{
			AcBottomDialog->SetUpdateText("「그 아이가 사는 것도 죽는 것\n도 또한 어떠한 인생을 보내게\n 되는 지도, 전부 당신 하기 나\n름」");
		}
		else if (185 <= Time && 191 > Time)
		{
			AcBottomDialog->SetUpdateText("「모든 것이 당신에게 달려있는 \n겁니다. 그래요, 모든 것이…」");
		}
		else if (191 <= Time && 198 > Time)
		{
			AcBottomDialog->SetUpdateText("「그럼 부탁드립니다. \n저는 항상 하늘에서 당신들 부\n녀를 지켜보겠습니다……」");
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
			AcCaption->SetUpdateText("그리고 1년이 지났다……");
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
