#pragma once
#include "MenuFrame.h"

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

	void MugShotRender();
	void LeftMugDialogRender();
	void RightMugDialogRender();
	void SetMoveMugShotRender(const float4& _Move);
	void SetMoveDialogRender(const float4& _Move);


protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;
	

private:
	int MugShotFrameStyle = -1; //�ӱ׼� ���� ��ȭâ, �Ϲ� �ӱ׼�, God �ӱ׼�
	int MugShotLoc = -1; // ���� �Ǵ� ������
	GameEngineRender* MugShotFrame = nullptr;
	GameEngineRender* MugShot = nullptr;

};

// ��ȭâ���� �ʿ��Ѱ�
// ��ȭâ�� ����
// 1. ũ��� 320 * 160
// 2. �ӱ׼��� ���� �Ǵ� �����ʿ� ���� �� ����
// 3. �ӱ׼��� �ΰ��������� ũ�Ⱑ ����
// ��ġ(����), ũ��(�޴�������), ��Ÿ��(�޴�������), �ӱ׼���ġ(��ȭâ), �ӱ׼�(��ȭâ), �ؽ�Ʈ�ƿ�, ��ȭâ�������ִ� Dialogs ��ġ�� �ӱ׼����� ���ؼ� �߾� ����
// ũ�������Ϳ��ͷ� ���̾˷α׾��ʹ� �ΰ��������������
// ��ȭâ�� �����ϴ� ���͸� �� Ŭ������ �������ҵ���...
// 
