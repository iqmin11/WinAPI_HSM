#pragma once
#include "GameEnginePath.h"
#include <string_view>

// �ݸ� Directory�� File�� ������ ���� �����ϰͰ���, �ش� ����, �ش� ���Ͽ� ���� ���Ҹ� �������������� ����
class GameEngineFile;
class GameEngineDirectory
{
public:
	// construtor destructor
	GameEngineDirectory();
	~GameEngineDirectory();

	// delete Function
	GameEngineDirectory(const GameEngineDirectory& _Other) = delete;
	GameEngineDirectory(GameEngineDirectory&& _Other) noexcept = delete;
	GameEngineDirectory& operator=(const GameEngineDirectory& _Other) = delete;
	GameEngineDirectory& operator=(GameEngineDirectory&& _Other) noexcept = delete;

	bool IsFile(const std::string_view& _FileName);
	bool MoveParent(); 
	void MoveParentToDirectory(const std::string_view& _String);
	bool Move(const std::string_view& _String);
	GameEnginePath GetPlusFileName(const std::string_view& _String);



protected:


private:
	GameEnginePath Path; // ���� �����⿡ ���⼭ Path��°� ��ġ ���ͷ�����ó�� ����Ű���ִ°�!(����Ű���ִ� ���丮)�� �ǹ��ϴ°Ͱ���

};

