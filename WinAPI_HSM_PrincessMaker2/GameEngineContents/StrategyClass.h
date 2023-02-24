#pragma once
class StrategyClass
{
public:
	// construtor destructor
	StrategyClass();
	~StrategyClass();

	// delete Function
	StrategyClass(const StrategyClass& _Other) = delete;
	StrategyClass(StrategyClass&& _Other) noexcept = delete;
	StrategyClass& operator=(const StrategyClass& _Other) = delete;
	StrategyClass& operator=(StrategyClass&& _Other) noexcept = delete;

protected:


private:

};

