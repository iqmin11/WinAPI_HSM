#include "GameEnginePath.h"
#include <Windows.h>
#include <GameEngineBase/GameEngineDebug.h>
#include <io.h>

GameEnginePath::GameEnginePath()
	:Path(std::filesystem::current_path())
{

}

GameEnginePath::GameEnginePath(std::filesystem::path _Path)
	:Path(_Path) 
{
}

GameEnginePath::GameEnginePath(const std::string& _Path)
	:Path(_Path)
{
}

GameEnginePath::~GameEnginePath()
{

}

GameEnginePath::GameEnginePath(const GameEnginePath& _Other)
	: Path(_Other.Path)
{
}

GameEnginePath::GameEnginePath(GameEnginePath&& _Other)
	: Path(_Other.Path)
{
}

std::string GameEnginePath::GetFileName() const
{
	return Path.filename().string();
}

std::string GameEnginePath::GetPathToString() const
{
	return Path.string();
}

void GameEnginePath::MoveParent()
{
	Path = Path.parent_path();
}

void GameEnginePath::MoveParentToChildPath(const std::string_view& _String)
{
	while (false == IsRoot()) 
	{
		if (true == IsExistsToPlusString(_String))
		{
			return; 
		}

		MoveParent();
	}

	MsgAssert("이런 경로를 자식으로 가진 부모는 존재하지 않습니다."); 
}

bool GameEnginePath::IsRoot()
{
	return Path == Path.root_path();
}

bool GameEnginePath::IsExistsToPlusString(const std::string_view& _String)
{
	std::string Str = GetPathToString() + _String.data();
	return 0 == _access(Str.c_str(), 0); 
}

bool GameEnginePath::IsExists()
{
	return 0 == _access(Path.string().c_str(), 0); 
}

bool GameEnginePath::Move(const std::string_view& _Path)
{
	Path += _Path;
	if (false == IsExists())
	{
		MsgAssert("존재하지 않는 경로로 이동하려고 했습니다.");
		return false;
	}
	return true;
}


