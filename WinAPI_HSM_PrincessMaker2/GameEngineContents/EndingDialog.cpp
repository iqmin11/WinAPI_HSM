#include "EndingDialog.h"

EndingDialog::EndingDialog()
{

}

EndingDialog::~EndingDialog()
{

}

void EndingDialog::Start()
{
	Dialog::Start();
	SetDialogScale({390, 150});
	SetPos(ActorPos);
}
