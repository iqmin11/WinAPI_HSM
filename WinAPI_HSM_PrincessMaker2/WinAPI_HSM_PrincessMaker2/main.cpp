#include <Windows.h>
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEngineMath.h>

void PM2Start()
{
}

void PM2Loop()
{
}

void PM2End()
{
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{

	GameEngineDebug::LeakCheck();

	GameEngineWindow::WindowCreate(hInstance, "PrincessMaker2", { 800, 640 }, {0, 0});

	GameEngineWindow::WindowLoop(PM2Start, PM2Loop, PM2End);


	return 0;
}