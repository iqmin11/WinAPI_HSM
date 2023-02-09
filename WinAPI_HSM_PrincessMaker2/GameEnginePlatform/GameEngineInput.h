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

		bool Down = false; // Ű�� ����
		bool Press = false; // Ű�� ������ ����
		bool Up = false;// Ű�� ���ö�
		bool Free = true; // Ű�� �ȴ��� �ִ� ����

		float PressTime = 0; // ������ �ִ� �ð�
		int Key = -1;

		bool KeyCheck() // ��ǲ�� �־��� �����ĸ� �����ϴ� �Լ�
		{
			return 0 != GetAsyncKeyState(Key); // �ȴ������� 0, ������ �� �̿��� ���� ����
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

	static void CreateKey(const std::string_view& _Name, int _Key); //Ű�� �뵵, Ű�� �ƽ�Ű

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

