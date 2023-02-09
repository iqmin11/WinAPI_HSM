#pragma once
#include <Windows.h>
#include <map>
#include <string>

class GameEngineWindow;
class GameEngineInput
{
	friend GameEngineWindow;

private:
	class GameEngineKey
	{
		friend GameEngineInput;

		bool Down = false; // 키가 들어갈때
		bool Press = false; // 키가 눌려진 상태
		bool Up = false;// 키가 나올때
		bool Free = true; // 키가 안눌려 있는 상태

		float PressTime = 0; // 누르고 있던 시간
		int Key = -1;

		bool KeyCheck() // 인풋이 있었냐 없었냐를 리턴하는 함수
		{
			return 0 != GetAsyncKeyState(Key); // 안눌렀을땐 0, 누르면 그 이외의 값을 리턴
		}

		void Update(float  _DeltaTime);
	};
	
public:

	// delete Function
	GameEngineInput(const GameEngineInput& _Other) = delete;
	GameEngineInput(GameEngineInput&& _Other) noexcept = delete;
	GameEngineInput& operator=(const GameEngineInput& _Other) = delete;
	GameEngineInput& operator=(GameEngineInput&& _Other) noexcept = delete;

	static void Update(float _DeltaTime);

	static void CreateKey(const std::string_view& _Name, int _Key); //키의 용도, 키의 아스키

	static bool IsKey(const std::string_view& _Name);

	static bool IsDown(const std::string_view& _Name);
	static bool IsUp(const std::string_view& _Name);
	static bool IsPress(const std::string_view& _Name);
	static bool IsFree(const std::string_view& _Name);
	static float GetPressTime(const std::string_view& _Name);

	static void MouseCursorOff();

	static bool IsAnyKey()
	{
		return IsAnyKeyValue;
	}


protected:


private:
	// construtor destructor
	GameEngineInput();
	~GameEngineInput();
	
	static std::map<std::string, GameEngineKey> Keys;
	static bool IsAnyKeyValue;
	static void IsAnyKeyOn()
	{
		IsAnyKeyValue = true;
	}

	static void IsAnyKeyOff()
	{
		IsAnyKeyValue = true;
	}

};

