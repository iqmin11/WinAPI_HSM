#pragma once
#include <GameEngineCore/GameEngineActor.h>

class GameEngineRender;
class OpeningCredit : public GameEngineActor
{
public:
	// construtor destructor
	OpeningCredit();
	~OpeningCredit();

	// delete Function
	OpeningCredit(const OpeningCredit& _Other) = delete;
	OpeningCredit(OpeningCredit&& _Other) noexcept = delete;
	OpeningCredit& operator=(const OpeningCredit& _Other) = delete;
	OpeningCredit& operator=(OpeningCredit&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;

private:
	float MoveSpeed = 100.0f;
	GameEngineRender* CreditRender = nullptr;
};

