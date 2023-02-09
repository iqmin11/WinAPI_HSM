#pragma once
#include <GameEngineCore/GameEngineActor.h>
class GameEngineCollision;
class MousePoint : public GameEngineActor
{
public:
	static MousePoint* MainMouse;

	// construtor destructor
	MousePoint();
	~MousePoint();

	// delete Function
	MousePoint(const MousePoint& _Other) = delete;
	MousePoint(MousePoint&& _Other) noexcept = delete;
	MousePoint& operator=(const MousePoint& _Other) = delete;
	MousePoint& operator=(MousePoint&& _Other) noexcept = delete;

	
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;

private:
	GameEngineCollision* MousePointCollision = nullptr;
	GameEngineRender* MousePointRender = nullptr;

};

