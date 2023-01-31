#pragma once
#include "MenuFrame.h"

enum class MugShotStyle
{
	Non,
	Nomal,
	God,
};

enum class MugShotLR
{
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

	void SetDialog(int _MugShotFrameStyle, int _MugShotLoc, const float4& _Pos); // �����Ұ� ���� �ϴ� �ӽ� ����....
	//���� �ܰ迡�� ��� �۵��� �� ����.
	// 1. �ӱ� ��Ÿ��, �ӱ� ����, �ӱ� ��ġ, ��ȭâ ��ġ �ְ�
	// 2. �ȿ� ��� ��縦 �迭�� �Է�
	// 3. ��� ���� ���ʷ� ��ȭ�� ����ϰ�.
	// 3. ������ ���� ����, �ȿ��ִ� ������ (��ȭ���� �޸�, ��Ÿ ���...) �ʱ�ȭ

	// ���� ��ȭâ ���� ���� ��ȭâ�� ������, �ٽ� �Է��ؾߵǴ½�����....
	void SetDialog(MugShotStyle _MugShotFrameStyle, MugShotLR _MugShotLoc, const float4& _Pos);
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

	void SetRightMugDialog(); // �ӱ׼��� �����ʿ� �ִ� ��ȭâ
	void SetLeftMugDialog(); // �ӱ׼��� ���ʿ� �ִ� ��ȭâ
	void SetMoveMugShotRender(const float4& _Move);
	void SetPosMugShotRender(const float4& _Pos);
	void MugShotRender();
	void InitRenderPos();
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
