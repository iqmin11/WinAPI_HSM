#pragma once
#include <GameEngineCore/GameEngineActor.h>

class Animation : public GameEngineActor
{
public:
	// construtor destructor
	Animation();
	~Animation();

	// delete Function
	Animation(const Animation& _Other) = delete;
	Animation(Animation&& _Other) noexcept = delete;
	Animation& operator=(const Animation& _Other) = delete;
	Animation& operator=(Animation&& _Other) noexcept = delete;


	void Start() override;
	void Update(float _Deltatime) override;
	void Render(float _Time) override;

protected:


private:

};

