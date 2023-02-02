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

	void SetMenuFrame(const float4& _pos, const float4& _TileBasedSize, const int _style = 2); //��ġ, ũ��, ��Ÿ��
	void SetMenuFrameSize(const float4& _Size)
	{
		if (_Size.x < 34 || _Size.y < 34)
		{
			MsgAssert("�޴��������� �ּ� ũ��� 34*34�Դϴ�")
		}
		MenuFrameSize = _Size;
	}

	void SetMenuFrameStyle(const int _style)
	{
		if (0 > _style || 2 < _style )
		{
			MsgAssert("������ ��Ÿ�� �ε��� ������ 0~2 �Դϴ�. �ش����� �ʴ� ���� �Է��Ͽ����ϴ�")
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
	float4 MenuFrameSize = {}; // �ȼ����� ������
	int MenuFrameStyle = -1;
	GameEngineRender* FrameRender[9] = {};
};
