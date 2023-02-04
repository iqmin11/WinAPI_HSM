#pragma once
class PM2Num
{
public:
	// construtor destructor
	PM2Num();
	~PM2Num();

	// delete Function
	PM2Num(const PM2Num& _Other) = delete;
	PM2Num(PM2Num&& _Other) noexcept = delete;
	PM2Num& operator=(const PM2Num& _Other) = delete;
	PM2Num& operator=(PM2Num&& _Other) noexcept = delete;

protected:


private:

};

