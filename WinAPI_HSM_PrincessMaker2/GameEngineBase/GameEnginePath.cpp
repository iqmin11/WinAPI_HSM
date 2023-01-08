#include "GameEnginePath.h"
#include <Windows.h> // 왜필요하지?
#include <GameEngineBase/GameEngineDebug.h>
#include <io.h>

GameEnginePath::GameEnginePath()
	:Path(std::filesystem::current_path()) //exe파일이 실행된 위치
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
	while (false == IsRoot()) // 상위폴더가 있어?
	{
		if (true == IsExistsToPlusString(_String)) // 있으면 해당경로에 접근이 가능해? (지금 디렉토리에 해당 파일이 있어?)
		{
			return; //그 폴더가 있는 Path인채로 함수 종료...인데 이거 의도대로라면 여기 Move가 있어야하는거아닌가? 아래로갔다가 자식폴더로 쇽 이동하려면
		}

		MoveParent(); // 상위폴더를 Path로
	}

	MsgAssert("이런 경로를 자식으로 가진 부모는 존재하지 않습니다."); // 상위폴더 없음.
}

bool GameEnginePath::IsRoot()
{
	return Path == Path.root_path(); // 패스가 루트 패스야?
}

bool GameEnginePath::IsExistsToPlusString(const std::string_view& _String) // 니가 인자로 받은 파일명을 현재 Path에서 접근 가능해??
{
	std::string Str = GetPathToString() + _String.data(); // Path + 파일명 → 해당파일 실행경로
	return 0 == _access(Str.c_str(), 0); // 그 경로에 접근이 가능해? 가능해면 0 리턴 ,인자로 받는 0은 검색 수준임 자세한건 msdn 참고
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


