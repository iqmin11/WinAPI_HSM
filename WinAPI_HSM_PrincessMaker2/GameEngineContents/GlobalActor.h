#pragma once
#include <GameEngineCore/GameEngineActor.h>
class GlobalActor : public GameEngineActor
{
public:
	// construtor destructor
	GlobalActor();
	~GlobalActor();

	// delete Function
	GlobalActor(const GlobalActor& _Other) = delete;
	GlobalActor(GlobalActor&& _Other) noexcept = delete;
	GlobalActor& operator=(const GlobalActor& _Other) = delete;
	GlobalActor& operator=(GlobalActor&& _Other) noexcept = delete;

protected:


private:

};

