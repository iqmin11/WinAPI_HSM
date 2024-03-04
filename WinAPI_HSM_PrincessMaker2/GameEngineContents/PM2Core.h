#pragma once
#include <GameEngineCore/GameEngineCore.h>


class PM2Core : public GameEngineCore
{
public:

	// delete Function
	PM2Core(const PM2Core& _Other) = delete;
	PM2Core(PM2Core&& _Other) noexcept = delete;
	PM2Core& operator=(const PM2Core& _Other) = delete;
	PM2Core& operator=(PM2Core&& _Other) noexcept = delete;

	static PM2Core& GetInst() 
	{
		return Core;
	}

protected:
	void Start() override; 
	void Update() override;
	void End() override;

private:
	// construtor destructor
	PM2Core();
	~PM2Core();

	static PM2Core Core;

};

