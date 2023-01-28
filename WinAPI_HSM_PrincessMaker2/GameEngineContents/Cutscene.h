#pragma once
#include <GameEngineCore/GameEngineActor.h>
class Cutscene : public GameEngineActor
{
public:
	// construtor destructor
	Cutscene();
	~Cutscene();

	// delete Function
	Cutscene(const Cutscene& _Other) = delete;
	Cutscene(Cutscene&& _Other) noexcept = delete;
	Cutscene& operator=(const Cutscene& _Other) = delete;
	Cutscene& operator=(Cutscene&& _Other) noexcept = delete;

protected:


private:

};

