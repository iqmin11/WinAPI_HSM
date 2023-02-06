#pragma once
#include "MenuFrame.h"
#include <GameEngineBase/GameEngineString.h>

enum class MugShotLR
{
	Non,
	Left,
	Right,
};

class Dialog : public MenuFrame
{
public:
	// construtor destructor
	Dialog();
	~Dialog();

	// delete Function
	Dialog(const Dialog& _Other) = delete;
	Dialog(Dialog&& _Other) noexcept = delete;
	Dialog& operator=(const Dialog& _Other) = delete;
	Dialog& operator=(Dialog&& _Other) noexcept = delete;

	void SetMugPic(const std::string_view& _ImageFileName);
	void SetMugLoc(int _MugLoc);
	void SetMugLoc(MugShotLR _MugLoc);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;
	

private:
	bool IsMugShot = false; //�ӱ׼� ���� ��ȭâ, �ִ´�ȭâ
	int MugShotLoc = -1; // ���� �Ǵ� ������
	GameEngineRender* MugShotFrame = nullptr;
	GameEngineRender* MugShot = nullptr;

	void SetRightMugDialog(); // �ӱ׼��� �����ʿ� �ִ� ��ȭâ
	void SetLeftMugDialog(); // �ӱ׼��� ���ʿ� �ִ� ��ȭâ
	void SetMoveMugShotRender(const float4& _Move);
	void SetPosMugShotRender(const float4& _Pos);
	void InitRenderPos();
};