#pragma once
#include <GameEngineCore/GameEngineActor.h>
class GameEnigneRender;
class Logo : public GameEngineActor
{
public:
	// construtor destructor
	Logo();
	~Logo();

	// delete Function
	Logo(const Logo& _Other) = delete;
	Logo(Logo&& _Other) noexcept = delete;
	Logo& operator=(const Logo& _Other) = delete;
	Logo& operator=(Logo&& _Other) noexcept = delete;

protected:
	void Start() override;


private:
	GameEngineRender* PM2Logo = nullptr;
};

