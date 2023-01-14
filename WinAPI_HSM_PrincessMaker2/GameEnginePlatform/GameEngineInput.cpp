#include "GameEngineInput.h"
#include <GameEngineBase/GameEngineString.h>
#include <GameEngineBase/GameEngineDebug.h>

void GameEngineInput::Update(float _DeltaTime)
{
	/*std::map<std::string, GameEngineKey>::iterator StartKeyIter = Keys.begin();
	std::map<std::string, GameEngineKey>::iterator EndKeyIter = Keys.end();
	for (; StartKeyIter != EndKeyIter; ++StartKeyIter)
	{
		StartKeyIter->second.Update(_DeltaTime);
	}*/

	/*for (std::pair<std::string, GameEngineKey> i : Keys)
	{
		i.second.Update(_DeltaTime);
	}*/

	for (auto& i : Keys)
	{
		i.second.Update(_DeltaTime);
	}
}

void GameEngineInput::CreateKey(const std::string_view& _Name, int _Key)
{
	std::string UpperName = GameEngineString::ToUpper(_Name);

	if (Keys.end() != Keys.find(UpperName))
	{
		MsgAssert("�̹� �����ϴ� �̸��� ũ�⸦ �� ������� �߽��ϴ�.");
	}
	
	_Key = toupper(_Key); // ��ҹ��� ��ȯ �Լ� �ƽ�Ű �����ΰ�����

	Keys[UpperName].Key = _Key; // Keys[UpperName].Key -> Keys��� map �ȿ� UpperName�̶�� first���� ���� ���ο� node�� �����, '.'�� second, Key�� second�� Key��
}

bool GameEngineInput::IsKey(const std::string_view& _Name)
{
	std::string UpperName = GameEngineString::ToUpper(_Name);

	return Keys.end() != Keys.find(UpperName); // _Name�̶�� first �� Keys �ȿ� �־�?
}

bool GameEngineInput::IsDown(const std::string_view& _Name)
{
	std::string UpperName = GameEngineString::ToUpper(_Name);

	if (Keys.end() == Keys.find(UpperName))
	{
		MsgAssert("�������� �ʴ� Ű�� ����Ϸ��� �߽��ϴ�." + UpperName);
	}


	return Keys[UpperName].Down; //���⼭�� find ������ �ϰڳ׿� UpperName�� Ű�� Down�� true��?
}

bool GameEngineInput::IsUp(const std::string_view& _Name)
{
	std::string UpperName = GameEngineString::ToUpper(_Name);

	if (Keys.end() == Keys.find(UpperName))
	{
		MsgAssert("�������� �ʴ� Ű�� ����Ϸ��� �߽��ϴ�." + UpperName);
	}


	return Keys[UpperName].Up;
}

bool GameEngineInput::IsPress(const std::string_view& _Name)
{
	std::string UpperName = GameEngineString::ToUpper(_Name);

	if (Keys.end() == Keys.find(UpperName))
	{
		MsgAssert("�������� �ʴ� Ű�� ����Ϸ��� �߽��ϴ�." + UpperName);
	}


	return Keys[UpperName].Press;
}

bool GameEngineInput::IsFree(const std::string_view& _Name)
{
	std::string UpperName = GameEngineString::ToUpper(_Name);

	if (Keys.end() == Keys.find(UpperName))
	{
		MsgAssert("�������� �ʴ� Ű�� ����Ϸ��� �߽��ϴ�." + UpperName);
	}


	return Keys[UpperName].Free;
}

float GameEngineInput::GetPressTime(const std::string_view& _Name)
{
	std::string UpperName = GameEngineString::ToUpper(_Name);

	if (Keys.end() == Keys.find(UpperName))
	{
		MsgAssert("�������� �ʴ� Ű�� ����Ϸ��� �߽��ϴ�." + UpperName);
	}

	return Keys[UpperName].PressTime;
}

GameEngineInput::GameEngineInput()
{

}

GameEngineInput::~GameEngineInput()
{

}

std::map<std::string, GameEngineInput::GameEngineKey> GameEngineInput::Keys;

void GameEngineInput::GameEngineKey::Update(float _DeltaTime)
{
	if (true == KeyCheck()) // Ű�Է��� �ִ�
	{
		if (true == Free) // Ű�Է��� �ֱ� ������ Free���¿��� �� Down
		{
			Down = true;
			Press = true;
			Up = false;
			Free = false;
			PressTime = _DeltaTime; // Down ���� üũ
		}
		else if (true == Press) //Ű�Է��� �ִµ�, �������� Ű �Է��� �־��� �� Press
		{
			Down = false;
			Press = true;
			Up = false;
			Free = false;
			PressTime += _DeltaTime;
		}
	}
	else // Ű�Է��� ����
	{
		PressTime = 0.0f; // Ű�Է��� ������ ������ PressTime�� 0�� ��
		if (true == Press) // ���� Ű�Է��� ���µ� �������� Ű�Է��� �־��ٸ� �� Up
		{
			Down = false;
			Press = false;
			Up = true;
			Free = true; // ����: 1������ ������ Up Down �ݺ� �� ù������. Ű �Է�O Down �� Press true / ��������. Ű �Է�X  Up true Free false / �� ������. Ű �Է�O ������ �Ȱɸ� �״�� Ż�� / ��������. Ű �Է�X false false false true�� �ǰڳ� / �ټ���° ������. Down�� �ǰڳ�
		}                // ������ ������ �����Ӷ� �Է��� �����ٴ°�
		else if (true == Up) // Ű�Է��� ���µ� ������ Up�̾��� // Free���¿��� ���ž��� ��� Ż��, ������ ���µ� ���࿡ FreeTime���� ������� ���� ������ �ȿ� ������ �̰͵� ������ ���� �� ����
		{        //���� �̰� true == free������ ���ڴ�
			Down = false;
			Press = false;
			Up = false;
			Free = true; 
		}
	}
}
