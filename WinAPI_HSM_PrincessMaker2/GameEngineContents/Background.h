#pragma once
#include <GameEngineCore/GameEngineActor.h>

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
	void Update() override;
	void Render() override;

protected:


private:

};

