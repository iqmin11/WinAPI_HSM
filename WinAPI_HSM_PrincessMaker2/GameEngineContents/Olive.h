#pragma once
#include <GameEngineCore/GameEngineActor.h>
class Olive : public GameEngineActor
{
public:
	// construtor destructor
	Olive();
	~Olive();

	// delete Function
	Olive(const Olive& _Other) = delete;
	Olive(Olive&& _Other) noexcept = delete;
	Olive& operator=(const Olive& _Other) = delete;
	Olive& operator=(Olive&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Deltatime) override;
	void Render(float _Deltatime) override;

private:

};

