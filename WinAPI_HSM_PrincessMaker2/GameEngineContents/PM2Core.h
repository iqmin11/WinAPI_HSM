#pragma once
#include <GameEngineCore/GameEngineCore.h>


class PM2Core : public GameEngineCore // ���ӿ��� �ھ ���
{
public:

	// delete Function
	PM2Core(const PM2Core& _Other) = delete;
	PM2Core(PM2Core&& _Other) noexcept = delete;
	PM2Core& operator=(const PM2Core& _Other) = delete;
	PM2Core& operator=(PM2Core&& _Other) noexcept = delete;

	static PM2Core& GetInst() // �״ϱ� ��� �긦 ���� ������ �ϴ°� �ƴ϶�(���� �߸� �����Ѱ�)
		//���� �ϳ��ۿ� ����.. �̹� ������ ����� Core�� �긦���� Get�ϴ°� ��. �̰� �̱���
	{
		return Core;  // ��� cpp���Ͽ� ������ Core
	}

protected:
	void Start() override; // �θ𿡼� ���������Լ��� ����Ǿ��ֱ� ������ ������ �ڽ��ʿ��� �����ؾߵ�
	void Update() override;
	void End() override;

private:
	// construtor destructor
	PM2Core(); //private �̰ɷ� ���ƹ����� �ھ �� ȣ���� ���� ����
	~PM2Core();

	static PM2Core Core; // ����ƽ���� PM2core �ڷ����� ���� �� ����

};

