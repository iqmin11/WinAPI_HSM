#pragma once
#include <map>
#include <list>
#include <vector>
#include "MenuFrame.h"
#include "GaugeRenderObject.h"
#include "ContentsEnums.h"


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

	GaugeRenderObject* InsertStatus(const std::string_view& _StatusName, float _Max, GaugeFrameStyle _Style);
	//void SetStatusFrameRender(int _Order);
	//void SetStatusFrameRender(PM2RenderOrder _Order);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	//void Render(float _DeltaTime) override;

private:
	int StatusCount = 0;
	std::vector<GaugeRenderObject*> Gauges = std::vector<GaugeRenderObject*>(); 
};

