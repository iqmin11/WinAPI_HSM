#include "GameEnginePath.h"
#include <Windows.h> // ���ʿ�����?
#include <GameEngineBase/GameEngineDebug.h>
#include <io.h>

GameEnginePath::GameEnginePath()
	:Path(std::filesystem::current_path()) //exe������ ����� ��ġ
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
	while (false == IsRoot()) // ���������� �־�?
	{
		if (true == IsExistsToPlusString(_String)) // ������ �ش��ο� ������ ������? (���� ���丮�� �ش� ������ �־�?)
		{
			return; //�� ������ �ִ� Path��ä�� �Լ� ����...�ε� �̰� �ǵ���ζ�� ���� Move�� �־���ϴ°žƴѰ�? �Ʒ��ΰ��ٰ� �ڽ������� �� �̵��Ϸ���
		}

		MoveParent(); // ���������� Path��
	}

	MsgAssert("�̷� ��θ� �ڽ����� ���� �θ�� �������� �ʽ��ϴ�."); // �������� ����.
}

bool GameEnginePath::IsRoot()
{
	return Path == Path.root_path(); // �н��� ��Ʈ �н���?
}

bool GameEnginePath::IsExistsToPlusString(const std::string_view& _String) // �ϰ� ���ڷ� ���� ���ϸ��� ���� Path���� ���� ������??
{
	std::string Str = GetPathToString() + _String.data(); // Path + ���ϸ� �� �ش����� ������
	return 0 == _access(Str.c_str(), 0); // �� ��ο� ������ ������? �����ظ� 0 ���� ,���ڷ� �޴� 0�� �˻� ������ �ڼ��Ѱ� msdn ����
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
		MsgAssert("�������� �ʴ� ��η� �̵��Ϸ��� �߽��ϴ�.");
		return false;
	}
	return true;
}


