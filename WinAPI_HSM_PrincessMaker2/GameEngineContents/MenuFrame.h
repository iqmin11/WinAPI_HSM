#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <vector>
#include <GameEngineBase/GameEngineDebug.h>

//class MenuTile
//{
//	friend MenuFrame;
//
//
//private:
//	//float4 SelectTile(int _numpad);
//
//};


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

	void CreateMenuFrame(const float4& _pos, const float4& _TileBasedSize, const int _style = 2); //위치, 크기, 스타일
	void SetMenuFrameSize(const float4& _TileBasedSize)
	{
		if (_TileBasedSize.x < 2 || _TileBasedSize.y < 2)
		{
			MsgAssert("메뉴프레임의 최소 크기는 2*2입니다")
		}
		MenuFramePixelSize = _TileBasedSize *16;
		MenuFrameSize = _TileBasedSize;
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

	void Start();
	void Update(float _Deltatime);
	void Render(float _Time);

protected:


private:
	float4 MenuFrameSize = {}; // 타일기준 사이즈 16*16픽셀
	float4 MenuFramePixelSize = {}; // 픽셀기준 사이즈
	int MenuFrameStyle = -1;
//	std::vector<MenuTile> Frame;
	


};

