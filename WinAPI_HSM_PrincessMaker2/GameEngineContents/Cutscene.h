#pragma once
#include <vector>
#include <GameEngineCore/GameEngineActor.h>

enum class BackgroundColor
{
	Black,
	White
};

class GameEngineRender;
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
	
	void OnCutScene(int _index);
	void OffCutScene();

	void SelectBackgroundColor(BackgroundColor _Color);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _time) override;

private:
	std::vector<GameEngineRender*> CutScenes = std::vector<GameEngineRender*>();
	std::vector<GameEngineRender*> Background = std::vector<GameEngineRender*>();
};



