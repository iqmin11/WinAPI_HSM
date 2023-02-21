#include "SocialAndHouseworkStatusWindow.h"
#include "Olive.h"

SocialAndHouseworkStatusWindow::SocialAndHouseworkStatusWindow()
{

}

SocialAndHouseworkStatusWindow::~SocialAndHouseworkStatusWindow()
{

}

void SocialAndHouseworkStatusWindow::Start()
{
	InitMenuFrameRender(PM2RenderOrder::Menu1);
	DecorumRender = InsertStatus("예의범절", Max, Style);
	ArtRender = InsertStatus("예술", Max, Style);
	ConversationRender = InsertStatus("화술", Max, Style);

	CookingRender = InsertStatus("요리", Max, Style);
	CleaningRender = InsertStatus("청소세탁", Max, Style);
	TemperamentRender = InsertStatus("성품", Max, Style);

	SetPos(ActorPos);
	Off();
}

void SocialAndHouseworkStatusWindow::Update(float _DeltaTime)
{
	if (Decorum != Olive::OlivePlayer->GetStatue().Decorum)
	{
		Decorum = Olive::OlivePlayer->GetStatue().Decorum;
		DecorumRender->UpdateValue(Decorum);
	}
	if (Art != Olive::OlivePlayer->GetStatue().Art)
	{
		Art = Olive::OlivePlayer->GetStatue().Art;
		ArtRender->UpdateValue(Art);
	}
	if (Conversation != Olive::OlivePlayer->GetStatue().Conversation)
	{
		Conversation = Olive::OlivePlayer->GetStatue().Conversation;
		ConversationRender->UpdateValue(Conversation);
	}
	if (Cooking != Olive::OlivePlayer->GetStatue().Cooking)
	{
		Cooking = Olive::OlivePlayer->GetStatue().Cooking;
		CookingRender->UpdateValue(Cooking);
	}
	if (Cleaning != Olive::OlivePlayer->GetStatue().Cleaning)
	{
		Cleaning = Olive::OlivePlayer->GetStatue().Cleaning;
		CleaningRender->UpdateValue(Cleaning);
	}
	if (Temperament != Olive::OlivePlayer->GetStatue().Temperament)
	{
		Temperament = Olive::OlivePlayer->GetStatue().Temperament;
		TemperamentRender->UpdateValue(Temperament);
	}
}
