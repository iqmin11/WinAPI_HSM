#pragma once
#include <GameEngineCore/GameEngineLevel.h>

class FirstSetLevel : public GameEngineLevel
{
public:
	// construtor destructor
	FirstSetLevel();
	~FirstSetLevel();

	// delete Function
	FirstSetLevel(const FirstSetLevel& _Other) = delete;
	FirstSetLevel(FirstSetLevel&& _Other) noexcept = delete;
	FirstSetLevel& operator=(const FirstSetLevel& _Other) = delete;
	FirstSetLevel& operator=(FirstSetLevel&& _Other) noexcept = delete;

	void Loading() override;
	void Update(float _DeltaTime) override;
	void LevelChangeEnd(GameEngineLevel* _NextLevel) override {};
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override {};
protected:


private:

};

