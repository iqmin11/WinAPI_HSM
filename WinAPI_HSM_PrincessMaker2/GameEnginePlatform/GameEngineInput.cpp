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
		MsgAssert("이미 존재하는 이름의 크기를 또 만들려고 했습니다.");
	}
	
	_Key = toupper(_Key); // 대소문자 변환 함수 아스키 기준인가보다

	Keys[UpperName].Key = _Key; // Keys[UpperName].Key -> Keys라는 map 안에 UpperName이라는 first값을 가진 새로운 node를 만들고, '.'는 second, Key는 second의 Key값
}

bool GameEngineInput::IsKey(const std::string_view& _Name)
{
	std::string UpperName = GameEngineString::ToUpper(_Name);

	return Keys.end() != Keys.find(UpperName); // _Name이라는 first 가 Keys 안에 있어?
}

bool GameEngineInput::IsDown(const std::string_view& _Name)
{
	std::string UpperName = GameEngineString::ToUpper(_Name);

	if (Keys.end() == Keys.find(UpperName))
	{
		MsgAssert("존재하지 않는 키를 사용하려고 했습니다." + UpperName);
	}


	return Keys[UpperName].Down; //여기서는 find 역할을 하겠네요 UpperName의 키의 Down이 true냐?
}

bool GameEngineInput::IsUp(const std::string_view& _Name)
{
	std::string UpperName = GameEngineString::ToUpper(_Name);

	if (Keys.end() == Keys.find(UpperName))
	{
		MsgAssert("존재하지 않는 키를 사용하려고 했습니다." + UpperName);
	}


	return Keys[UpperName].Up;
}

bool GameEngineInput::IsPress(const std::string_view& _Name)
{
	std::string UpperName = GameEngineString::ToUpper(_Name);

	if (Keys.end() == Keys.find(UpperName))
	{
		MsgAssert("존재하지 않는 키를 사용하려고 했습니다." + UpperName);
	}


	return Keys[UpperName].Press;
}

bool GameEngineInput::IsFree(const std::string_view& _Name)
{
	std::string UpperName = GameEngineString::ToUpper(_Name);

	if (Keys.end() == Keys.find(UpperName))
	{
		MsgAssert("존재하지 않는 키를 사용하려고 했습니다." + UpperName);
	}


	return Keys[UpperName].Free;
}

float GameEngineInput::GetPressTime(const std::string_view& _Name)
{
	std::string UpperName = GameEngineString::ToUpper(_Name);

	if (Keys.end() == Keys.find(UpperName))
	{
		MsgAssert("존재하지 않는 키를 사용하려고 했습니다." + UpperName);
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
	if (true == KeyCheck()) // 키입력이 있다
	{
		if (true == Free) // 키입력이 있기 전까지 Free상태였다 → Down
		{
			Down = true;
			Press = true;
			Up = false;
			Free = false;
			PressTime = _DeltaTime; // Down 시점 체크
		}
		else if (true == Press) //키입력이 있는데, 그전에도 키 입력이 있었다 → Press
		{
			Down = false;
			Press = true;
			Up = false;
			Free = false;
			PressTime += _DeltaTime;
		}
	}
	else // 키입력이 없다
	{
		PressTime = 0.0f; // 키입력이 없으면 언제나 PressTime은 0이 됨
		if (true == Press) // 지금 키입력이 없는데 이전까지 키입력이 있었다면 → Up
		{
			Down = false;
			Press = false;
			Up = true;
			Free = true; // 가정: 1프레임 단위로 Up Down 반복 → 첫프레임. 키 입력O Down 및 Press true / 둘프레임. 키 입력X  Up true Free false / 셋 프레임. 키 입력O 로직에 안걸림 그대로 탈출 / 넷프레임. 키 입력X false false false true가 되겠네 / 다섯번째 프레임. Down이 되겠네
		}                // 문제는 세번쨰 프레임때 입력이 씹혔다는것
		else if (true == Up) // 키입력이 없는데 이전에 Up이었다 // Free상태에서 갱신없이 계속 탈출, 문제는 없는데 만약에 FreeTime같은 멤버변수 갱신 로직이 안에 있으면 이것도 문제가 있을 수 있음
		{        //나는 이게 true == free였으면 좋겠다
			Down = false;
			Press = false;
			Up = false;
			Free = true; 
		}
	}
}
