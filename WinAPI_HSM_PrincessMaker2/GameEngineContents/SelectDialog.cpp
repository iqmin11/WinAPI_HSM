#include "SelectDialog.h"

SelectDialog::SelectDialog()
{

}

SelectDialog::~SelectDialog()
{

}

void SelectDialog::Start()
{
	Dialog::Start();
	SetDialogScale(ActorScale);
	SetPos(ActorPos);
}
