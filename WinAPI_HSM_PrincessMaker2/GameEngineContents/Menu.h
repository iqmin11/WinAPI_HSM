#pragma once
#include <GameEngineCore/GameEngineActor.h>
class Menu : public GameEngineActor
{
public:
	std::list<Menu*> LowMenu = std::list<Menu*>();

	// construtor destructor
	Menu();
	~Menu();

	// delete Function
	Menu(const Menu& _Other) = delete;
	Menu(Menu&& _Other) noexcept = delete;
	Menu& operator=(const Menu& _Other) = delete;
	Menu& operator=(Menu&& _Other) noexcept = delete;

protected:


private:
};

