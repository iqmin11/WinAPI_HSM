#pragma once
#include "GameEnginePath.h"

// Ό³Έν :
class GameEngineFile
{
public:
	// constrcuter destructer
	GameEngineFile();
	~GameEngineFile();
	GameEngineFile(std::filesystem::path _Path);

	std::string GetFullPath()
	{
		return Path.Path.string();
	}

protected:

private:
	GameEnginePath Path;
};

