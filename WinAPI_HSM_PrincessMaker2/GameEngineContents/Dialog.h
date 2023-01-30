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

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;

private:
	int MugShotFrameStyle = -1; //머그샷 없는 대화창, 일반 머그샷, God 머그샷
	int MugShotLoc = -1; // 왼쪽 또는 오른쪽
	GameEngineRender* MugShotFrame = nullptr;
	GameEngineRender* MugShot = nullptr;
};

// 대화창에게 필요한거
// 위치(액터), 크기(메뉴프레임), 스타일(메뉴프레임), 머그샷위치(대화창), 머그샷(대화창), 텍스트아웃, 대화창관리해주는 Dialogs 위치는 머그샷까지 합해서 중앙 기중
// 크리에이터엑터로 다이알로그액터는 두개만들수가없으니
// 대화창을 관리하는 벡터를 이 클래스에 만들어야할듯함...
// 
