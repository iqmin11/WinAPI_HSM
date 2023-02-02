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

	void SetDialog(int _MugShotLoc, const float4& _Pos, const std::string_view& _ImageFileName = "\0"); // �����Ұ� ���� �ϴ� �ӽ� ����....
	//���� �ܰ迡�� ��� �۵��� �� ����.
	// 1. �ӱ� ��Ÿ��, �ӱ� ����, �ӱ� ��ġ, ��ȭâ ��ġ �ְ�
	// 2. �ȿ� ��� ��縦 �迭�� �Է�
	// 3. ��� ���� ���ʷ� ��ȭ�� ����ϰ�.
	// 3. ������ ���� ����, �ȿ��ִ� ������ (��ȭ���� �޸�, ��Ÿ ���...) �ʱ�ȭ

	// ���� ��ȭâ ���� ���� ��ȭâ�� ������, �ٽ� �Է��ؾߵǴ½�����....
	void SetDialog(MugShotLR _MugShotLoc, const float4& _Pos, std::string_view _ImageFileName);
	void SetMugShot(const std::string_view& _ImageFileName);
	//void InputScript;

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
	void MugShotRender();
	void InitRenderPos();
};

// ��ȭâ���� �ʿ��Ѱ�
// ��ȭâ�� ����
// 1. ũ��� 320 * 160
// 2. �ӱ׼��� ���� �Ǵ� �����ʿ� ���� �� ����
// 3. �ӱ׼��� �ΰ��������� ũ�Ⱑ ����
// ��ġ(����), ũ��(�޴�������), ��Ÿ��(�޴�������), �ӱ׼���ġ(��ȭâ), �ӱ׼�(��ȭâ), �ؽ�Ʈ�ƿ�, ��ȭâ�������ִ� Dialogs ��ġ�� �ӱ׼����� ���ؼ� �߾� ����