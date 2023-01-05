#pragma once
#include <GameEngineCore/GameEngineCore.h>


class PM2Core : public GameEngineCore // 게임엔진 코어를 상속
{
public:

	// delete Function
	PM2Core(const PM2Core& _Other) = delete;
	PM2Core(PM2Core&& _Other) noexcept = delete;
	PM2Core& operator=(const PM2Core& _Other) = delete;
	PM2Core& operator=(PM2Core&& _Other) noexcept = delete;

	static PM2Core& GetInst() // 그니까 사실 얘를 통해 구현을 하는게 아니라(내가 잘못 이해한것)
		//오직 하나밖에 없는.. 이미 전역에 선언된 Core를 얘를통해 Get하는것 뿐. 이게 싱글톤
	{
		return Core;  // 얘는 cpp파일에 구현된 Core
	}

protected:
	void Start() override; // 부모에서 순수가상함수로 선언되어있기 때문에 무조건 자식쪽에서 구현해야됨
	void Update() override;
	void End() override;

private:
	// construtor destructor
	PM2Core(); //private 이걸로 막아버리니 코어를 또 호출할 수는 없음
	~PM2Core();

	static PM2Core Core; // 스태틱으로 PM2core 자료형을 받을 수 있음

};

