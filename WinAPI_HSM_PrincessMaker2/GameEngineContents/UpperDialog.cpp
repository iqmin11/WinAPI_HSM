#include "UpperDialog.h"
#include <GameEnginePlatform/GameEngineWindow.h>

UpperDialog::UpperDialog()
{

}

UpperDialog::~UpperDialog()
{

}

void UpperDialog::Start()
{
	Dialog::Start();
	SetPos({ GameEngineWindow::GetScreenSize().half()});
	
}
