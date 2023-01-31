#pragma once
#include <GameEngineCore/GameEngineActor.h>

class GameEngineRender;
class Flower : public GameEngineActor
{
public:
	// construtor destructor
	Flower();
	~Flower();

	// delete Function
	Flower(const Flower& _Other) = delete;
	Flower(Flower&& _Other) noexcept = delete;
	Flower& operator=(const Flower& _Other) = delete;
	Flower& operator=(Flower&& _Other) noexcept = delete;

	void ChangeFlower();

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;

private:
	GameEngineRender* FlowerRender = nullptr;
	GameEngineRender* SpringFlower = nullptr;
	GameEngineRender* SummerFlower = nullptr;
	GameEngineRender* FallFlower = nullptr;
	GameEngineRender* WinterFlower = nullptr;
	GameEngineRender* DiseaseFlower = nullptr;

};

