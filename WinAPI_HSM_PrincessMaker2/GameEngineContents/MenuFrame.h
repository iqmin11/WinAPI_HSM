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

	void SetMenuFrame(const float4& _pos, const float4& _TileBasedSize, const int _style = 2); //위치, 크기, 스타일
	void SetMenuFrameSize(const float4& _Size)
	{
		if (_Size.x < 34 || _Size.y < 34)
		{
			MsgAssert("메뉴프레임의 최소 크기는 34*34입니다")
		}
		MenuFrameSize = _Size;
	}

	void SetMenuFrameStyle(const int _style)
	{
		if (0 > _style || 2 < _style )
		{
			MsgAssert("프레임 스타일 인덱스 범위는 0~2 입니다. 해당하지 않는 값을 입력하였습니다")
		}
		MenuFrameStyle = _style;
	}

	void MenuFrameRender(const int _Order);
	void MenuFrameRender(PM2RenderOrder _Order);
	

	void Start();
	void Update(float _Deltatime);
	void Render(float _Time);

	GameEngineRender** GetFrameRender()
	{
		return FrameRender;
	}

	float4 GetMenuFrameSize()
	{
		return MenuFrameSize;
	}

protected:
	void SetMoveFrameRender(const float4& _Pos);
	void SetPosFrameRender(const float4& _Pos);


private:
	float4 MenuFrameSize = {}; // 픽셀기준 사이즈
	int MenuFrameStyle = -1;
	GameEngineRender* FrameRender[9] = {};
};
