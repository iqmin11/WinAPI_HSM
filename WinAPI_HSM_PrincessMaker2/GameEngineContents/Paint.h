#pragma once
#pragma once
#include <GameEngineCore/GameEngineActor.h>

class GameEngineRender;
class Paint : public GameEngineActor
{
public:
	// construtor destructor
	Paint();
	~Paint();

	// delete Function
	Paint(const Paint& _Other) = delete;
	Paint(Paint&& _Other) noexcept = delete;
	Paint& operator=(const Paint& _Other) = delete;
	Paint& operator=(Paint&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;

private:
	GameEngineRender* PaintRender = nullptr;

};

