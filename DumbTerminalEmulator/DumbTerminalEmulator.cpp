#include "DumbTerminalEmulator.h"
#include <QToolBar>
#include <iostream>
#include "console.h"

DumbTerminalEmulator::DumbTerminalEmulator(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	serial = new QSerialPort(this);
	console = new Console;
	setCentralWidget(console);

	console->setLocalEchoEnabled(true);

	connect(ui.actionConnect, &QAction::triggered, this, &DumbTerminalEmulator::openConfig);
	
	
}


void DumbTerminalEmulator::openPort()
{

}

void DumbTerminalEmulator::closePort()
{

}

void DumbTerminalEmulator::writeData(const QByteArray &data)
{

}

void DumbTerminalEmulator::readData()
{

}

void DumbTerminalEmulator::openConfig()
{

}