#pragma once
#include <GameEngineCore/Button.h>
class GlobalButton : public Button
{
public:
	// construtor destructor
	GlobalButton();
	~GlobalButton();

	// delete Function
	GlobalButton(const GlobalButton& _Other) = delete;
	GlobalButton(GlobalButton&& _Other) noexcept = delete;
	GlobalButton& operator=(const GlobalButton& _Other) = delete;
	GlobalButton& operator=(GlobalButton&& _Other) noexcept = delete;

protected:
	void Render(float _DeltaTime) override;

private:

};

