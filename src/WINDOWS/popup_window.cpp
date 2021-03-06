#include "popup_window.h"

PopupWindow::PopupWindow (std::string title, Vector2D size, Vector2D position, Color backgroundColor)
	: Window::Window (title, size, position, backgroundColor, true)
{
	bn_cancel = new OutlinedButton ("Cancel", LOC (10, (size.y - (80+10))), LOC ((size.x / 2) - (20), 35));
	bn_cancel->OnClickedEvent = MFUNC (&PopupWindow::bn_cancel_clicked, this);
	AddComponent (bn_cancel);
	
	Hide ();
}

void PopupWindow::bn_cancel_clicked ()
{
	this->Destroy ();
}




PopupColorWindow::PopupColorWindow (std::string title, Vector2D size, Vector2D position, Color backgroundColor, Color* color)
	: PopupWindow::PopupWindow (title, size, position, backgroundColor)
{
	this->color = color;
	this->old_color = *this->color;
	
	bn_save = new OutlinedButton ("Save", STACK (bn_cancel), LOC ((size.x / 2) - (20), 35));
	bn_cancel->OnClickedEvent = MFUNC (&PopupColorWindow::bn_cancel_revert_clicked, this);
	bn_save->OnClickedEvent = MFUNC (&PopupColorWindow::bn_save_clicked, this);
	AddComponent (bn_save);
}

void PopupColorWindow::bn_cancel_revert_clicked ()
{
	*this->color = this->old_color;
	this->Destroy ();
}

void PopupColorWindow::bn_save_clicked ()
{
	this->Destroy ();
}
