#pragma once
#include <Windows.h>
#include <assert.h>

// Ό³Έν :
class GameEngineDebug
{
public:
	static void LeakCheck();

	// delete Function
	GameEngineDebug(const GameEngineDebug& _Other) = delete;
	GameEngineDebug(GameEngineDebug&& _Other) noexcept = delete;
	GameEngineDebug& operator=(const GameEngineDebug& _Other) = delete;
	GameEngineDebug& operator=(GameEngineDebug&& _Other) noexcept = delete;

protected:

private:
	// constrcuter destructer
	GameEngineDebug();
	~GameEngineDebug();

};

// #define MsgBoxAssert(MsgText) MessageBoxA(nullptr, MsgText, "Error", MB_OK);	assert(false);