#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineBase/GameEngineDebug.h>
#include "ContentsEnums.h"

class MenuFrame : public GameEngineActor
{
public:
	// construtor destructor
	MenuFrame();
	~MenuFrame();

	// delete Function
	MenuFrame(const MenuFrame& _Other) = delete;
	MenuFrame(MenuFrame&& _Other) noexcept = delete;
	MenuFrame& operator=(const MenuFrame& _Other) = delete;
	MenuFrame& operator=(MenuFrame&& _Other) noexcept = delete;

	void InitMenuFrameRender(int _Order, const int _style = 2);
	void InitMenuFrameRender(PM2RenderOrder _Order, const int _style = 2);
	void SetMenuFrameScale(const float4& _Scale);
	

	GameEngineRender** GetFrameRender() 
	{
		return FrameRender;
	}

	float4 GetMenuFrameScale()
	{
		return MenuFrameScale;
	}

	void FrameRenderOn();
	
	void FrameRenderOff();
	
	//void InitMenuFrame(const int _Order);
	//void MenuFrameRender(PM2RenderOrder _Order);

protected:
	void SetMoveFrameRender(const float4& _Pos);
	void SetPosFrameRender(const float4& _Pos);

	void Start();
	void Update(float _Deltatime);
	void Render(float _Time);

private:
	float4 MenuFrameScale = {}; // 픽셀기준 사이즈
	int MenuFrameStyle = -1;
	GameEngineRender* FrameRender[9] = {};
};
