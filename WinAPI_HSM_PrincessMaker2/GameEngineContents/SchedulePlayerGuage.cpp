#include "SchedulePlayerGuage.h"
#include <GameEngineCore/GameEngineLevel.h>
#include "Olive.h"

SchedulePlayerGuage::SchedulePlayerGuage()
{

}

SchedulePlayerGuage::~SchedulePlayerGuage()
{

}

void SchedulePlayerGuage::On()
{
	GameEngineObject::On();
	switch (CountStatus)
	{
	case 0:
		Off();
		break;
	case 1:
		AcGauge11->On();
		AcGauge12->Off();
		AcGauge13->Off();
		AcGauge21->Off();
		AcGauge22->Off();
		AcGauge23->Off();
		break;
	case 2:
		AcGauge11->Off();
		AcGauge12->Off();
		AcGauge13->Off();
		AcGauge21->On();
		AcGauge22->Off();
		AcGauge23->Off();
		break;
	case 3:
		AcGauge11->Off();
		AcGauge12->On();
		AcGauge13->Off();
		AcGauge21->On();
		AcGauge22->Off();
		AcGauge23->Off();
		break;
	case 4:
		AcGauge11->Off();
		AcGauge12->Off();
		AcGauge13->Off();
		AcGauge21->On();
		AcGauge22->On();
		AcGauge23->Off();
		break;
	case 5:
		AcGauge11->Off();
		AcGauge12->Off();
		AcGauge13->On();
		AcGauge21->On();
		AcGauge22->On();
		AcGauge23->Off();
		break;
	case 6:
		AcGauge11->Off();
		AcGauge12->Off();
		AcGauge13->Off();
		AcGauge21->On();
		AcGauge22->On();
		AcGauge23->On();
		break;
	default:
		break;
	}
}

void SchedulePlayerGuage::Off()
{
	GameEngineObject::Off();
	AcGauge11->Off();
	AcGauge12->Off();
	AcGauge13->Off();
	AcGauge21->Off();
	AcGauge22->Off();
	AcGauge23->Off();
}

void SchedulePlayerGuage::Start()
{
	SetAcGauge();
	Off();
}

void SchedulePlayerGuage::Update(float _DeltaTime)
{
	if (Status1 != nullptr)
	{
		Render1->UpdateValue(*Status1);
		Render11->UpdateValue(*Status1);
	}
	
	if (Status2 != nullptr)
	{
		Render12->UpdateValue(*Status2);
	}

	if (Status3 != nullptr)
	{		  
		Render3->UpdateValue(*Status3);
		Render33->UpdateValue(*Status3);
	}

	if (Status4 != nullptr)
	{
		Render34->UpdateValue(*Status4);
	}

	if (Status5 != nullptr)
	{
		Render5->UpdateValue(*Status5);
		Render55->UpdateValue(*Status5);
	}
	
	if (Status6 != nullptr)
	{
		Render56->UpdateValue(*Status6);
	}
	
}

void SchedulePlayerGuage::SetAcGauge()
{
	AcGauge11 = GetLevel()->CreateActor<StatusWindow>(PM2ActorOrder::Menu1);
	AcGauge11->InitMenuFrameRender(PM2RenderOrder::Menu1);
	Render1 = AcGauge11->InsertStatus(" ", 999, GaugeFrameStyle::Nomal);
	AcGauge11->SetPos({ 160,495 });

	AcGauge12 = GetLevel()->CreateActor<StatusWindow>(PM2ActorOrder::Menu1);
	AcGauge12->InitMenuFrameRender(PM2RenderOrder::Menu1);
	Render3 = AcGauge12->InsertStatus(" ", 999, GaugeFrameStyle::Nomal);
	AcGauge12->SetPos({ 400,495 });
	
	AcGauge13 = GetLevel()->CreateActor<StatusWindow>(PM2ActorOrder::Menu1);
	AcGauge13->InitMenuFrameRender(PM2RenderOrder::Menu1);
	Render5 = AcGauge13->InsertStatus(" ", 999, GaugeFrameStyle::Nomal);
	AcGauge13->SetPos({ 640,495 });
	
	AcGauge21 = GetLevel()->CreateActor<StatusWindow>(PM2ActorOrder::Menu1);
	AcGauge21->InitMenuFrameRender(PM2RenderOrder::Menu1);
	Render11 = AcGauge21->InsertStatus(" ", 999, GaugeFrameStyle::Nomal);
	Render12 = AcGauge21->InsertStatus(" ", 999, GaugeFrameStyle::Nomal);
	AcGauge21->SetPos({ 160,505 });
	
	AcGauge22 = GetLevel()->CreateActor<StatusWindow>(PM2ActorOrder::Menu1);
	AcGauge22->InitMenuFrameRender(PM2RenderOrder::Menu1);
	Render33 = AcGauge22->InsertStatus(" ", 999, GaugeFrameStyle::Nomal);
	Render34 = AcGauge22->InsertStatus(" ", 999, GaugeFrameStyle::Nomal);
	AcGauge22->SetPos({ 400,505 });
	
	AcGauge23 = GetLevel()->CreateActor<StatusWindow>(PM2ActorOrder::Menu1);
	AcGauge23->InitMenuFrameRender(PM2RenderOrder::Menu1);
	Render55 = AcGauge23->InsertStatus(" ", 999, GaugeFrameStyle::Nomal);
	Render56 = AcGauge23->InsertStatus(" ", 999, GaugeFrameStyle::Nomal);
	AcGauge23->SetPos({ 640,505 });
}

void SchedulePlayerGuage::SetActorCount(int _Count)
{
	CountStatus = _Count;

	switch (CountStatus)
	{
	case 0:
		Off();
		break;
	case 1:
		AcGauge11->On();
		AcGauge12->Off();
		AcGauge13->Off();
		AcGauge21->Off();
		AcGauge22->Off();
		AcGauge23->Off();
		break;
	case 2:
		AcGauge11->Off();
		AcGauge12->Off();
		AcGauge13->Off();
		AcGauge21->On();
		AcGauge22->Off();
		AcGauge23->Off();
		break;
	case 3:
		AcGauge11->Off();
		AcGauge12->On();
		AcGauge13->Off();
		AcGauge21->On();
		AcGauge22->Off();
		AcGauge23->Off();
		break;
	case 4:
		AcGauge11->Off();
		AcGauge12->Off();
		AcGauge13->Off();
		AcGauge21->On();
		AcGauge22->On();
		AcGauge23->Off();
		break;
	case 5:
		AcGauge11->Off();
		AcGauge12->Off();
		AcGauge13->On();
		AcGauge21->On();
		AcGauge22->On();
		AcGauge23->Off();
		break;
	case 6:
		AcGauge11->Off();
		AcGauge12->Off();
		AcGauge13->Off();
		AcGauge21->On();
		AcGauge22->On();
		AcGauge23->On();
		break;
	default:
		break;
	}
}

void SchedulePlayerGuage::SetGaugeRender(int _Count, const std::string_view& _Name1, const float* _OliveStatusPtr1, const std::string_view& _Name2, const float* _OliveStatusPtr2, const std::string_view& _Name3, const float* _OliveStatusPtr3, const std::string_view& _Name4, const float* _OliveStatusPtr4, const std::string_view& _Name5, const float* _OliveStatusPtr5, const std::string_view& _Name6, const float* _OliveStatusPtr6)
{
	SetActorCount(_Count);
	if (1 == _Count)
	{
		if (_OliveStatusPtr1 == nullptr)
		{
			MsgAssert("그럴수없습니다")
		}
		Render1->SetNameRender(_Name1);
		Render1->SetMax(FindMax(_OliveStatusPtr1));
		Status1 = _OliveStatusPtr1;
	}
	else if (2 == _Count)
	{
		if (_OliveStatusPtr2 == nullptr)
		{
			MsgAssert("그럴수없습니다")
		}
		Render11->SetNameRender(_Name1);
		Render11->SetMax(FindMax(_OliveStatusPtr1));
		Status1 = _OliveStatusPtr2;
		Render12->SetNameRender(_Name2);
		Render12->SetMax(FindMax(_OliveStatusPtr2));
		Status2 = _OliveStatusPtr2;
	}
	else if (3 == _Count)
	{
		if (_OliveStatusPtr3 == nullptr)
		{
			MsgAssert("그럴수없습니다")
		}
		Render11->SetNameRender(_Name1);
		Render11->SetMax(FindMax(_OliveStatusPtr1));
		Status1 = _OliveStatusPtr1;
		Render12->SetNameRender(_Name2);
		Render12->SetMax(FindMax(_OliveStatusPtr2));
		Status2 = _OliveStatusPtr2;
		Render3->SetNameRender(_Name3);
		Render3->SetMax(FindMax(_OliveStatusPtr3));
		Status3 = _OliveStatusPtr3;
	}
	else if (4 == _Count)
	{
		if (_OliveStatusPtr4 == nullptr)
		{
			MsgAssert("그럴수없습니다")
		}
		Render11->SetNameRender(_Name1);
		Render11->SetMax(FindMax(_OliveStatusPtr1));
		Status1 = _OliveStatusPtr1;
		Render12->SetNameRender(_Name2);
		Render12->SetMax(FindMax(_OliveStatusPtr2));
		Status2 = _OliveStatusPtr2;
		Render33->SetNameRender(_Name3);
		Render33->SetMax(FindMax(_OliveStatusPtr3));
		Status3 = _OliveStatusPtr3;
		Render34->SetNameRender(_Name4);
		Render34->SetMax(FindMax(_OliveStatusPtr4));
		Status4 = _OliveStatusPtr4;
	}
	else if (5 == _Count)
	{
		if (_OliveStatusPtr5 == nullptr)
		{
			MsgAssert("그럴수없습니다")
		}
		Render11->SetNameRender(_Name1);
		Render11->SetMax(FindMax(_OliveStatusPtr1));
		Status1 = _OliveStatusPtr1;
		Render12->SetNameRender(_Name2);
		Render12->SetMax(FindMax(_OliveStatusPtr2));
		Status2 = _OliveStatusPtr2;
		Render33->SetNameRender(_Name3);
		Render33->SetMax(FindMax(_OliveStatusPtr3));
		Status3 = _OliveStatusPtr3;
		Render34->SetNameRender(_Name4);
		Render34->SetMax(FindMax(_OliveStatusPtr4));
		Status4 = _OliveStatusPtr4;
		Render5->SetNameRender(_Name5);
		Render5->SetMax(FindMax(_OliveStatusPtr5));
		Status5 = _OliveStatusPtr5;
	}
	else if (6 == _Count)
	{
		if (_OliveStatusPtr6 == nullptr)
		{
			MsgAssert("그럴수없습니다")
		}
		Render11->SetNameRender(_Name1);
		Render11->SetMax(FindMax(_OliveStatusPtr1));
		Status1 = _OliveStatusPtr1;
		Render12->SetNameRender(_Name2);
		Render12->SetMax(FindMax(_OliveStatusPtr2));
		Status2 = _OliveStatusPtr2;
		Render33->SetNameRender(_Name3);
		Render33->SetMax(FindMax(_OliveStatusPtr3));
		Status3 = _OliveStatusPtr3;
		Render34->SetNameRender(_Name4);
		Render34->SetMax(FindMax(_OliveStatusPtr4));
		Status4 = _OliveStatusPtr4;
		Render55->SetNameRender(_Name5);
		Render55->SetMax(FindMax(_OliveStatusPtr5));
		Status5 = _OliveStatusPtr5;
		Render56->SetNameRender(_Name6);
		Render56->SetMax(FindMax(_OliveStatusPtr6));
		Status6 = _OliveStatusPtr6;
	}
}

float SchedulePlayerGuage::FindMax(const float* _OliveStatusPtr)
{
	if (&(Olive::OlivePlayer->OliveStatus.Constitution) == _OliveStatusPtr)
	{
		return Olive::OlivePlayer->OliveStatus.MaxConstitution;
	}
	else if (&(Olive::OlivePlayer->OliveStatus.Strength) == _OliveStatusPtr)
	{
		return Olive::OlivePlayer->OliveStatus.MaxStrength;
	}
	else if (&(Olive::OlivePlayer->OliveStatus.Intelligence) == _OliveStatusPtr)
	{
		return Olive::OlivePlayer->OliveStatus.MaxIntelligence;
	}
	else if (&(Olive::OlivePlayer->OliveStatus.Refinement) == _OliveStatusPtr)
	{
		return Olive::OlivePlayer->OliveStatus.MaxRefinement;
	}
	else if (&(Olive::OlivePlayer->OliveStatus.Charisma) == _OliveStatusPtr)
	{
		return Olive::OlivePlayer->OliveStatus.MaxCharisma;
	}
	else if (&(Olive::OlivePlayer->OliveStatus.Morality) == _OliveStatusPtr)
	{
		return Olive::OlivePlayer->OliveStatus.MaxMorality;
	}
	else if (&(Olive::OlivePlayer->OliveStatus.Faith) == _OliveStatusPtr)
	{
		return Olive::OlivePlayer->OliveStatus.MaxFaith;
	}
	else if (&(Olive::OlivePlayer->OliveStatus.Sin) == _OliveStatusPtr)
	{
		return Olive::OlivePlayer->OliveStatus.MaxSin;
	}
	else if (&(Olive::OlivePlayer->OliveStatus.Sensitivity) == _OliveStatusPtr)
	{
		return Olive::OlivePlayer->OliveStatus.MaxSensitivity;
	}
	else if (&(Olive::OlivePlayer->OliveStatus.Stress) == _OliveStatusPtr)
	{
		return Olive::OlivePlayer->OliveStatus.MaxStress;
	}
	else if (&(Olive::OlivePlayer->OliveStatus.CombatSkill) == _OliveStatusPtr)
	{
		return Olive::OlivePlayer->OliveStatus.MaxCombatSkill;
	}
	else if (&(Olive::OlivePlayer->OliveStatus.CombatAttack) == _OliveStatusPtr)
	{
		return Olive::OlivePlayer->OliveStatus.MaxCombatAttack;
	}
	else if (&(Olive::OlivePlayer->OliveStatus.CombatDefense) == _OliveStatusPtr)
	{
		return Olive::OlivePlayer->OliveStatus.MaxCombatDefense;
	}
	else if (&(Olive::OlivePlayer->OliveStatus.MagicSkill) == _OliveStatusPtr)
	{
		return Olive::OlivePlayer->OliveStatus.MaxMagicSkill;
	}
	else if (&(Olive::OlivePlayer->OliveStatus.MagicAttack) == _OliveStatusPtr)
	{
		return Olive::OlivePlayer->OliveStatus.MaxMagicAttack;
	}
	else if (&(Olive::OlivePlayer->OliveStatus.MagicDefense) == _OliveStatusPtr)
	{
		return Olive::OlivePlayer->OliveStatus.MaxMagicDefense;
	}
	else if (&(Olive::OlivePlayer->OliveStatus.Decorum) == _OliveStatusPtr)
	{
		return Olive::OlivePlayer->OliveStatus.MaxDecorum;
	}
	else if (&(Olive::OlivePlayer->OliveStatus.Art) == _OliveStatusPtr)
	{
		return Olive::OlivePlayer->OliveStatus.MaxArt;
	}
	else if (&(Olive::OlivePlayer->OliveStatus.Conversation) == _OliveStatusPtr)
	{
		return Olive::OlivePlayer->OliveStatus.MaxConversation;
	}
	else if (&(Olive::OlivePlayer->OliveStatus.Cooking) == _OliveStatusPtr)
	{
		return Olive::OlivePlayer->OliveStatus.MaxCooking;
	}
	else if (&(Olive::OlivePlayer->OliveStatus.Cleaning) == _OliveStatusPtr)
	{
		return Olive::OlivePlayer->OliveStatus.MaxCleaning;
	}
	else if (&(Olive::OlivePlayer->OliveStatus.Temperament) == _OliveStatusPtr)
	{
		return Olive::OlivePlayer->OliveStatus.MaxTemperament;
	}

}

void SchedulePlayerGuage::InitGauge()
{
	Render1 = nullptr;
	Render11 = nullptr;
	Render12 = nullptr;
	Render3 = nullptr;
	Render33 = nullptr;
	Render34 = nullptr;
	Render5 = nullptr;
	Render55 = nullptr;
	Render56 = nullptr;
	
	Status1 = nullptr;
	Status2 = nullptr;
	Status3 = nullptr;
	Status4 = nullptr;
	Status5 = nullptr;
	Status6 = nullptr;
}

void SchedulePlayerGuage::SetSchedule(ScheduleLabel _Schedule)
{
	//InitGauge();
	switch (_Schedule)
	{
	case ScheduleLabel::Null:
		break;
	case ScheduleLabel::자연과학:
		SetGaugeRender(4, "지능", &(Olive::OlivePlayer->OliveStatus.Intelligence), "신앙심", &(Olive::OlivePlayer->OliveStatus.Faith), "항마력", &(Olive::OlivePlayer->OliveStatus.MagicDefense), "스트레스", &(Olive::OlivePlayer->OliveStatus.Stress));
		break;
	case ScheduleLabel::신학:
		SetGaugeRender(4, "지능", &(Olive::OlivePlayer->OliveStatus.Intelligence), "신앙심", &(Olive::OlivePlayer->OliveStatus.Faith), "항마력", &(Olive::OlivePlayer->OliveStatus.MagicDefense), "스트레스", &(Olive::OlivePlayer->OliveStatus.Stress));
		break;
	case ScheduleLabel::군사학:
		SetGaugeRender(4, "지능", &(Olive::OlivePlayer->OliveStatus.Intelligence), "감수성", &(Olive::OlivePlayer->OliveStatus.Sensitivity), "전투기술", &(Olive::OlivePlayer->OliveStatus.CombatSkill), "스트레스", &(Olive::OlivePlayer->OliveStatus.Stress));
		break;
	case ScheduleLabel::검술:
		SetGaugeRender(3, "전투기술", &(Olive::OlivePlayer->OliveStatus.CombatSkill), "공격력", &(Olive::OlivePlayer->OliveStatus.CombatAttack), "스트레스", &(Olive::OlivePlayer->OliveStatus.Stress));
		break;
	case ScheduleLabel::격투술:
		SetGaugeRender(3, "전투기술", &(Olive::OlivePlayer->OliveStatus.CombatSkill), "방어력", &(Olive::OlivePlayer->OliveStatus.CombatDefense), "스트레스", &(Olive::OlivePlayer->OliveStatus.Stress));
		break;
	case ScheduleLabel::마법:
		SetGaugeRender(3, "마법기술", &(Olive::OlivePlayer->OliveStatus.MagicSkill), "마력", &(Olive::OlivePlayer->OliveStatus.MagicAttack), "스트레스", &(Olive::OlivePlayer->OliveStatus.Stress));
		break;
	case ScheduleLabel::시문학:
		SetGaugeRender(5, "지능", &(Olive::OlivePlayer->OliveStatus.Intelligence), "기품", &(Olive::OlivePlayer->OliveStatus.Refinement), "감수성", &(Olive::OlivePlayer->OliveStatus.Sensitivity), "예술", &(Olive::OlivePlayer->OliveStatus.Art), "스트레스", &(Olive::OlivePlayer->OliveStatus.Stress));
		break;
	case ScheduleLabel::예법:
		SetGaugeRender(3, "기품", &(Olive::OlivePlayer->OliveStatus.Refinement), "예의범절", &(Olive::OlivePlayer->OliveStatus.Decorum), "스트레스", &(Olive::OlivePlayer->OliveStatus.Stress));
		break;
	case ScheduleLabel::무용:
		SetGaugeRender(4, "체력", &(Olive::OlivePlayer->OliveStatus.Constitution), "색기", &(Olive::OlivePlayer->OliveStatus.Charisma), "예술", &(Olive::OlivePlayer->OliveStatus.Art), "스트레스", &(Olive::OlivePlayer->OliveStatus.Stress));
		break;
	case ScheduleLabel::미술:
		SetGaugeRender(3, "감수성", &(Olive::OlivePlayer->OliveStatus.Sensitivity), "예술", &(Olive::OlivePlayer->OliveStatus.Art), "스트레스", &(Olive::OlivePlayer->OliveStatus.Stress));
		break;
	default:
		break;
	}
}
