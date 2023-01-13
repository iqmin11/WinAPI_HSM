#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineBase/GameEngineMath.h>

class Background : public GameEngineActor
{
public:
	// construtor destructor
	Background();
	~Background();

	// delete Function
	Background(const Background& _Other) = delete;
	Background(Background&& _Other) noexcept = delete;
	Background& operator=(const Background& _Other) = delete;
	Background& operator=(Background&& _Other) noexcept = delete;

	void Start() override;
	void Update(float _Deltatime) override;
	void Render(float _Time) override;

protected:


private:

};

