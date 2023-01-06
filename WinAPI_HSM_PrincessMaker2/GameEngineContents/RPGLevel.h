#pragma once
#include <GameEngineCore/GameEngineLevel.h>

class RPGLevel : public GameEngineLevel
{
public:
	// construtor destructor
	RPGLevel();
	~RPGLevel();

	// delete Function
	RPGLevel(const RPGLevel& _Other) = delete;
	RPGLevel(RPGLevel&& _Other) noexcept = delete;
	RPGLevel& operator=(const RPGLevel& _Other) = delete;
	RPGLevel& operator=(RPGLevel&& _Other) noexcept = delete;

	void Loading() override;
	void Update() override;
protected:


private:

};

