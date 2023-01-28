#pragma once
#include <GameEngineCore/GameEngineActor.h>

class TitleLogo : public GameEngineActor
{
public:
	// construtor destructor
	TitleLogo();
	~TitleLogo();

	// delete Function
	TitleLogo(const TitleLogo& _Other) = delete;
	TitleLogo(TitleLogo&& _Other) noexcept = delete;
	TitleLogo& operator=(const TitleLogo& _Other) = delete;
	TitleLogo& operator=(TitleLogo&& _Other) noexcept = delete;

protected:


private:

};

