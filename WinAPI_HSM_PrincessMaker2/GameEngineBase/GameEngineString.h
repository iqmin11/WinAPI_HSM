#pragma once
#include <string>
#include <string_view>
// ���� :
class GameEngineString
{
public:

	static std::string ToUpper(const std::string_view& _Str);
	
	static std::string ToString(int _Value);


protected:

private:
	// constrcuter destructer
	GameEngineString();
	~GameEngineString();

	// delete Function
	GameEngineString(const GameEngineString& _Other) = delete;
	GameEngineString(GameEngineString&& _Other) noexcept = delete;
	GameEngineString& operator=(const GameEngineString& _Other) = delete;
	GameEngineString& operator=(GameEngineString&& _Other) noexcept = delete;
};

