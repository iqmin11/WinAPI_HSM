#pragma once
#include "GameEnginePath.h"
#include <string_view>

// 반면 Directory와 File의 역할은 좀더 정적일것같음, 해당 폴더, 해당 파일에 대한 역할만 수행하지않을까 생각
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
	GameEnginePath Path; // 내가 느끼기에 여기서 Path라는건 마치 이터레이터처럼 가리키고있는곳!(가리키고있는 디렉토리)를 의미하는것같아

};

