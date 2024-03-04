#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineBase/GameEngineDebug.h>
#include "ContentsEnums.h"
enum class MenuFrameStyleEnum
{
	Null = -1,
	Gold,
	Silver,
	Nomal
};

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

	void InitMenuFrameRender(int _Order, MenuFrameStyleEnum _style = MenuFrameStyleEnum::Nomal);
	void InitMenuFrameRender(PM2RenderOrder _Order, MenuFrameStyleEnum _style = MenuFrameStyleEnum::Nomal);
	void SetMenuFrameScale(const float4& _Scale);
	

	GameEngineRender** GetFrameRender() 
	{
		return FrameRender;
	}

	float4 GetMenuFrameScale()
	{
		return MenuFrameScale;
	}

	int GetFrameRenderOrder() const
	{
		return FrameRenderOrder;
	}

	void FrameRenderOn();
	
	void FrameRenderOff();
	
protected:
	void SetMoveFrameRender(const float4& _Pos);
	void SetPosFrameRender(const float4& _Pos);

	void Start();
	void Update(float _Deltatime);
	void Render(float _Time);

private:
	float4 MenuFrameScale = {};
	MenuFrameStyleEnum MenuFrameStyle = MenuFrameStyleEnum::Null;
	GameEngineRender* FrameRender[9] = {};
	int FrameRenderOrder = 0;
};
