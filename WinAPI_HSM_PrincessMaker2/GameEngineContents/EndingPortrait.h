#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "ContentsEnums.h"
#include "EndingLevel.h"

class GameEngineRender;
class EndingDialog;
class Olive;
class EndingPortrait : public GameEngineActor
{
public:
	// construtor destructor
	EndingPortrait();
	~EndingPortrait();

	// delete Function
	EndingPortrait(const EndingPortrait& _Other) = delete;
	EndingPortrait(EndingPortrait&& _Other) noexcept = delete;
	EndingPortrait& operator=(const EndingPortrait& _Other) = delete;
	EndingPortrait& operator=(EndingPortrait&& _Other) noexcept = delete;

	void On() override;
	void Off() override;

protected:
	void Start() override;
	void Update(float _DeltaTime);

private:
	float4 ActorPos = { 400, 300 };
	GameEngineRender* Background = nullptr;
	Ending* OliveEnding = nullptr;

	GameEngineRender* Potrait = nullptr;

	EndingDialog* AcEndingDialog = nullptr;

	Olive* AcOlive = nullptr;
};

