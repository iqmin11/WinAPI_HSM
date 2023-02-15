#pragma once
#include <GameEngineCore/Button.h>

// Ό³Έν :
class NameButton : public Button
{
public:
	// constrcuter destructer
	NameButton();
	~NameButton();

	// delete Function
	NameButton(const NameButton& _Other) = delete;
	NameButton(NameButton&& _Other) noexcept = delete;
	NameButton& operator=(const NameButton& _Other) = delete;
	NameButton& operator=(NameButton&& _Other) noexcept = delete;

	char Chracter;

protected:


private:

};

