#include <Windows.h>
#include <GameEngineContents/PM2Core.h>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{

	PM2Core::GetInst().CoreStart(hInstance);
	return 0;
}