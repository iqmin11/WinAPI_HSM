#pragma once
#include <GameEngineCore/GameEngineLevel.h>

class OpeningLevel : public GameEngineLevel
{
public:
	// construtor destructor
	OpeningLevel();
	~OpeningLevel();

	// delete Function
	OpeningLevel(const OpeningLevel& _Other) = delete;
	OpeningLevel(OpeningLevel&& _Other) noexcept = delete;
	OpeningLevel& operator=(const OpeningLevel& _Other) = delete;
	OpeningLevel& operator=(OpeningLevel&& _Other) noexcept = delete;

protected:


private:

};

