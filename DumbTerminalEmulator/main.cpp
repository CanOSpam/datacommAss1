#include "DumbTerminalEmulator.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	DumbTerminalEmulator w;
	w.show();
	return a.exec();
}
