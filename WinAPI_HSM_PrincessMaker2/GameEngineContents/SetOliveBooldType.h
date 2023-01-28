#pragma once
#include <GameEngineCore/GameEngineActor.h>
class SetOliveBooldType : public GameEngineActor
{
public:
	// construtor destructor
	SetOliveBooldType();
	~SetOliveBooldType();

	// delete Function
	SetOliveBooldType(const SetOliveBooldType& _Other) = delete;
	SetOliveBooldType(SetOliveBooldType&& _Other) noexcept = delete;
	SetOliveBooldType& operator=(const SetOliveBooldType& _Other) = delete;
	SetOliveBooldType& operator=(SetOliveBooldType&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime) override;

private:
	GameEngineRender* BackgroundRender = nullptr;

};

