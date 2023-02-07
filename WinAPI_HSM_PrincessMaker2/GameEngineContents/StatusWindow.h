#pragma once
#include <vector>
#include "MenuFrame.h"

class GameEngineRender;
class StatusWindow : public MenuFrame
{
public:
	// construtor destructor
	StatusWindow();
	~StatusWindow();

	// delete Function
	StatusWindow(const StatusWindow& _Other) = delete;
	StatusWindow(StatusWindow&& _Other) noexcept = delete;
	StatusWindow& operator=(const StatusWindow& _Other) = delete;
	StatusWindow& operator=(StatusWindow&& _Other) noexcept = delete;

	void SetStatusCount(int _Count);
	void SetStatusFrameRender(int _Order);
	void SetStatusFrameRender(PM2RenderOrder _Order);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	//void Render(float _DeltaTime) override;

private:
	int StatusCount = 0;
	std::vector<GameEngineRender*> StatusGaugeFrameRender_Layer1 = {};
	std::vector<GameEngineRender*> StatusGaugeFrameRender_Layer2 = {};
	std::vector<std::vector<GameEngineRender*>> StatusGaugeRender = {}; // 이거지금 빨간부분이랑 빈칸부분이랑 같이관리하는데, 그렇게하지말고 따로따로나누는게 나을것같아
};

