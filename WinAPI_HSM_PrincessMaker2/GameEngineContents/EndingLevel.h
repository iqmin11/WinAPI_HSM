#pragma once
#include <GameEngineCore/GameEngineLevel.h>

class EndingLevel : public GameEngineLevel
{
public:
	// construtor destructor
	EndingLevel();
	~EndingLevel();

	// delete Function
	EndingLevel(const EndingLevel& _Other) = delete;
	EndingLevel(EndingLevel&& _Other) noexcept = delete;
	EndingLevel& operator=(const EndingLevel& _Other) = delete;
	EndingLevel& operator=(EndingLevel&& _Other) noexcept = delete;

protected:


private:

};

