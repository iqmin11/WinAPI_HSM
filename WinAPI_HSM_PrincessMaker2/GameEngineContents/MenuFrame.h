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

	void CreateMenuFrame(const float4& _pos, const float4& _tilesize, const int _style = 2); //��ġ, ũ��, ��Ÿ��
	void SetMenuFrameSize(const float4& _tilesize)
	{
		if (_tilesize.x < 3 || _tilesize.y < 3)
		{
			MsgAssert("�޴��������� �ּ� ũ��� 3*3�Դϴ�")
		}
		MenuFramePixelSize = _tilesize*16;
		MenuFrameSize = _tilesize;
	}

	void SetMenuFrameStyle(const int _style)
	{
		if (0 < _style || 2 < _style )
		{
			MsgAssert("������ ��Ÿ�� �ε��� ������ 0~2 �Դϴ�. �ش����� �ʴ� ���� �Է��Ͽ����ϴ�")
		}
		MenuFrameStyle = _style;
	}

	void MenuFrameRender();

	void Start();
	void Update(float _Deltatime);
	void Render(float _Deltatime);

protected:


private:
	float4 MenuFrameSize = {}; // Ÿ�ϱ��� ������ 16*16�ȼ�
	float4 MenuFramePixelSize = {}; // �ȼ����� ������
	int MenuFrameStyle = -1;
//	std::vector<MenuTile> Frame;
	


};

