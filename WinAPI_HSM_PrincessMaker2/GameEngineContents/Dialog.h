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

	void SetDialog(int _MugShotFrameStyle, int _MugShotLoc, const float4& _Pos); // 수정할게 많음 일단 임시 생성....
	//레벨 단계에서 어떻게 작동할 지 생각.
	// 1. 머그 스타일, 머그 사진, 머그 위치, 대화창 위치 넣고
	// 2. 안에 출력 대사를 배열로 입력
	// 3. 출력 시작 차례로 대화를 출력하고.
	// 3. 끝나면 랜더 끄기, 안에있는 설정들 (대화내용 메모리, 기타 등등...) 초기화

	// 다음 대화창 사용시 같은 대화창을 쓰지만, 다시 입력해야되는식으로....
	void SetDialog(MugShotStyle _MugShotFrameStyle, MugShotLR _MugShotLoc, const float4& _Pos);
	void SetMoveDialogRender(const float4& _Move);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;
	

private:
	int MugShotFrameStyle = -1; //머그샷 없는 대화창, 일반 머그샷, God 머그샷
	int MugShotLoc = -1; // 왼쪽 또는 오른쪽
	GameEngineRender* MugShotFrame = nullptr;
	GameEngineRender* MugShot = nullptr;

	void SetRightMugDialog(); // 머그샷이 오른쪽에 있는 대화창
	void SetLeftMugDialog(); // 머그샷이 왼쪽에 있는 대화창
	void SetMoveMugShotRender(const float4& _Move);
	void SetPosMugShotRender(const float4& _Pos);
	void MugShotRender();
	void InitRenderPos();
};

// 대화창에게 필요한거
// 대화창의 설정
// 1. 크기는 320 * 160
// 2. 머그샷은 왼쪽 또는 오른쪽에 있을 수 있음
// 3. 머그샷은 두가지버전의 크기가 있음
// 위치(액터), 크기(메뉴프레임), 스타일(메뉴프레임), 머그샷위치(대화창), 머그샷(대화창), 텍스트아웃, 대화창관리해주는 Dialogs 위치는 머그샷까지 합해서 중앙 기중
// 크리에이터엑터로 다이알로그액터는 두개만들수가없으니
// 대화창을 관리하는 벡터를 이 클래스에 만들어야할듯함...
// 
