/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: console.cpp - This application is the main text window used in the Dumb Terminal Emulator
--
-- PROGRAM: console
--
-- FUNCTIONS:
--		void getData(const QByteArray &data)
--		explicit Console(QWidget *parent = 0)
--		void putData(const QByteArray &data)
--		void setLocalEchoEnabled(bool set)
--		virtual void keyPressEvent(QKeyEvent *e)
--
--
-- DATE: October 04, 2017
--
-- REVISIONS: None
--
-- DESIGNER: Tim Bruecker
--
-- PROGRAMMER: Tim Bruecker
--
-- NOTES:
-- This program displays and reads in the characters that are sent over the serial connection. It handles keystrokes 
-- and shows incoming characters.
----------------------------------------------------------------------------------------------------------------------*/

#include "console.h"

#include <QtCore/QDebug>

Console::Console(QWidget *parent)
	: QPlainTextEdit(parent)
	, localEchoEnabled(false)
{
	document()->setMaximumBlockCount(100);

}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: putData
--
-- DATE: October 4th, 2017
--
-- REVISIONS: None
--
-- DESIGNER: Tim Bruecker
--
-- PROGRAMMER: Tim Bruecker
--
-- INTERFACE: void putData(const QByteArray &data)
--
-- RETURNS: void
--
-- NOTES:
-- This function writes a QString to the text box.
----------------------------------------------------------------------------------------------------------------------*/
void Console::putData(const QByteArray &data)
{
	insertPlainText(QString(data));
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: setLocalEchoEnabled
--
-- DATE: October 4th, 2017
--
-- REVISIONS: None
--
-- DESIGNER: Tim Bruecker
--
-- PROGRAMMER: Tim Bruecker
--
-- INTERFACE: void setLocalEchoEnabled(bool set)
--
-- RETURNS: void
--
-- NOTES:
-- This function disables or enables local echo. If local echo is enabled, the users keystrokes will appear in their
-- own terminal, otherwise they will only be sent to the serial port.
----------------------------------------------------------------------------------------------------------------------*/
void Console::setLocalEchoEnabled(bool set)
{
	localEchoEnabled = set;
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: keyPressEvent
--
-- DATE: October 4th, 2017
--
-- REVISIONS: None
--
-- DESIGNER: Tim Bruecker
--
-- PROGRAMMER: Tim Bruecker
--
-- INTERFACE: void keyPressEvent(QKeyEvent *e)
--
-- RETURNS: void
--
-- NOTES:
-- This function is called when a keypress is detected. It ignores backspace, and the arrow keys. If local echo is
-- enabled, it sends the event to the parent objects keyPressEvent, which writes it to the textbox. Then the function
-- emits a getData signal which will be caught in DumbTerminalEmulator.cpp and cause a write to the serial port.
----------------------------------------------------------------------------------------------------------------------*/
void Console::keyPressEvent(QKeyEvent *e)
{
	switch (e->key()) {
	case Qt::Key_Backspace:
	case Qt::Key_Left:
	case Qt::Key_Right:
	case Qt::Key_Up:
	case Qt::Key_Down:
		break;
	default:
		if (localEchoEnabled)
			QPlainTextEdit::keyPressEvent(e);
		emit getData(e->text().toLocal8Bit());
	}
}