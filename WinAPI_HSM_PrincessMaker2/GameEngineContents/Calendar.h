#pragma once
#include <GameEngineCore/GameEngineActor.h>
class Calendar : public GameEngineActor
{
public:
	// construtor destructor
	Calendar();
	~Calendar();

	// delete Function
	Calendar(const Calendar& _Other) = delete;
	Calendar(Calendar&& _Other) noexcept = delete;
	Calendar& operator=(const Calendar& _Other) = delete;
	Calendar& operator=(Calendar&& _Other) noexcept = delete;

	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime) override;

protected:


private:

};

