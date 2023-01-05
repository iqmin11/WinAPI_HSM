#pragma once
#include <GameEngineCore/GameEngineLevel.h>
class TitleLevel : public GameEngineLevel
{
public:
	// construtor destructor
	TitleLevel();
	~TitleLevel();

	// delete Function
	TitleLevel(const TitleLevel& _Other) = delete;
	TitleLevel(TitleLevel&& _Other) noexcept = delete;
	TitleLevel& operator=(const TitleLevel& _Other) = delete;
	TitleLevel& operator=(TitleLevel&& _Other) noexcept = delete;

protected:


private:

};

