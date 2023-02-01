#pragma once
#include <vector>
#include <GameEngineCore/GameEngineActor.h>

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
	
	void ChangeRenderScene(int _index);
	

	void OnRenderScene();
	
	void OffRenderScene();

	void OnBlackBackground();
	
	void OffBlackBackground();
	

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _time) override;

private:
	std::vector<GameEngineRender*> CutScenes = std::vector<GameEngineRender*>();
	GameEngineRender* BlackBackground = nullptr;
	GameEngineRender* RenderScene = nullptr;
	int PrevRenderIndex = -1;
};

// 컷신들은 렌더, 위치와 움직임이 있도록 만들기
// 컷신 1~7 

