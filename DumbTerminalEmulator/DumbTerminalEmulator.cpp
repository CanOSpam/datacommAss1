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

	//Connection menu connects
	connect(ui.actionConnect, &QAction::triggered, this, &DumbTerminalEmulator::connectSerial);
	connect(ui.actionConnect, &QAction::triggered, this, &DumbTerminalEmulator::disconnectSerial);

	//Baud rate connects
	connect(ui.action1200, &QAction::triggered, this, &DumbTerminalEmulator::baudSet);
	connect(ui.action2400, &QAction::triggered, this, &DumbTerminalEmulator::baudSet);
	connect(ui.action4800, &QAction::triggered, this, &DumbTerminalEmulator::baudSet);
	connect(ui.action9600, &QAction::triggered, this, &DumbTerminalEmulator::baudSet);
	connect(ui.action19200, &QAction::triggered, this, &DumbTerminalEmulator::baudSet);
	connect(ui.action38400, &QAction::triggered, this, &DumbTerminalEmulator::baudSet);
	connect(ui.action57600, &QAction::triggered, this, &DumbTerminalEmulator::baudSet);
	connect(ui.action115200, &QAction::triggered, this, &DumbTerminalEmulator::baudSet);
	

	//Com port connects
	connect(ui.actionCom_1, &QAction::triggered, this, &DumbTerminalEmulator::port1Enable);
	connect(ui.actionCom_2, &QAction::triggered, this, &DumbTerminalEmulator::port2Enable);
	connect(ui.actionCom_3, &QAction::triggered, this, &DumbTerminalEmulator::port3Enable);
	connect(ui.actionCom_4, &QAction::triggered, this, &DumbTerminalEmulator::port4Enable);

	//Parity Connects
	connect(ui.actionEven, &QAction::triggered, this, &DumbTerminalEmulator::setEven);
	connect(ui.actionOdd, &QAction::triggered, this, &DumbTerminalEmulator::setOdd);
	connect(ui.actionNone, &QAction::triggered, this, &DumbTerminalEmulator::setNone);


	//Stop Bit Connects
	connect(ui.actionOneStop, &QAction::triggered, this, &DumbTerminalEmulator::stop1);
	connect(ui.actionOneAndAHalfStop, &QAction::triggered, this, &DumbTerminalEmulator::stop1_5);
	connect(ui.actionTwoStop, &QAction::triggered, this, &DumbTerminalEmulator::stop2);

}


void DumbTerminalEmulator::writeData(const QByteArray &data)
{
	serial->write(data);
}

void DumbTerminalEmulator::readData()
{
	
}

void DumbTerminalEmulator::connectSerial()
{
	serial->open(QIODevice::ReadWrite);
}

void DumbTerminalEmulator::disconnectSerial()
{
	if (serial->isOpen())
		serial->close();
}

void DumbTerminalEmulator::baudSet()
{
	int baudRate =((QAction*)QObject::sender())->text().toInt();

	//Uncheck all options
	ui.action1200->setChecked(false);
	ui.action2400->setChecked(false);
	ui.action4800->setChecked(false);
	ui.action9600->setChecked(false);
	ui.action19200->setChecked(false);
	ui.action38400->setChecked(false);
	ui.action57600->setChecked(false);
	ui.action115200->setChecked(false);

	//Check selected option
	((QAction*)QObject::sender())->setChecked(true);

	serial->setBaudRate(baudRate);
}

void DumbTerminalEmulator::port1Enable()
{
	//Uncheck all options
	ui.actionCom_1->setChecked(false);
	ui.actionCom_2->setChecked(false);
	ui.actionCom_3->setChecked(false);
	ui.actionCom_4->setChecked(false);

	//Check selected option
	((QAction*)QObject::sender())->setChecked(true);

	serial->setPortName("com1");
}

void DumbTerminalEmulator::port2Enable()
{
	//Uncheck all options
	ui.actionCom_1->setChecked(false);
	ui.actionCom_2->setChecked(false);
	ui.actionCom_3->setChecked(false);
	ui.actionCom_4->setChecked(false);

	//Check selected option
	((QAction*)QObject::sender())->setChecked(true);

	serial->setPortName("com2");
}

void DumbTerminalEmulator::port3Enable()
{
	//Uncheck all options
	ui.actionCom_1->setChecked(false);
	ui.actionCom_2->setChecked(false);
	ui.actionCom_3->setChecked(false);
	ui.actionCom_4->setChecked(false);

	//Check selected option
	((QAction*)QObject::sender())->setChecked(true);

	serial->setPortName("com3");
}

void DumbTerminalEmulator::port4Enable()
{
	//Uncheck all options
	ui.actionCom_1->setChecked(false);
	ui.actionCom_2->setChecked(false);
	ui.actionCom_3->setChecked(false);
	ui.actionCom_4->setChecked(false);

	//Check selected option
	((QAction*)QObject::sender())->setChecked(true);

	serial->setPortName("com4");
}


//Set Parity Functions
void DumbTerminalEmulator::setEven()
{
	//Uncheck all options
	ui.actionEven->setChecked(false);
	ui.actionOdd->setChecked(false);
	ui.actionNone->setChecked(false);

	//Check selected option
	((QAction*)QObject::sender())->setChecked(true);

	serial->setParity(QSerialPort::EvenParity);

}
void DumbTerminalEmulator::setOdd()
{
	//Uncheck all options
	ui.actionEven->setChecked(false);
	ui.actionOdd->setChecked(false);
	ui.actionNone->setChecked(false);

	//Check selected option
	((QAction*)QObject::sender())->setChecked(true);

	serial->setParity(QSerialPort::OddParity);
}

void DumbTerminalEmulator::setNone()
{
	//Uncheck all options
	ui.actionEven->setChecked(false);
	ui.actionOdd->setChecked(false);
	ui.actionNone->setChecked(false);

	//Check selected option
	((QAction*)QObject::sender())->setChecked(true);

	serial->setParity(QSerialPort::NoParity);
}


//Stop Bit Functions
void DumbTerminalEmulator::stop1()
{
	//Uncheck all options
	ui.actionOneStop->setChecked(false);
	ui.actionOneAndAHalfStop->setChecked(false);
	ui.actionTwoStop->setChecked(false);

	//Check selected option
	((QAction*)QObject::sender())->setChecked(true);

	serial->setStopBits(QSerialPort::OneStop);
}

void DumbTerminalEmulator::stop1_5()
{
	//Uncheck all options
	ui.actionOneStop->setChecked(false);
	ui.actionOneAndAHalfStop->setChecked(false);
	ui.actionTwoStop->setChecked(false);

	//Check selected option
	((QAction*)QObject::sender())->setChecked(true);

	serial->setStopBits(QSerialPort::OneAndHalfStop);
}

void DumbTerminalEmulator::stop2()
{
	//Uncheck all options
	ui.actionOneStop->setChecked(false);
	ui.actionOneAndAHalfStop->setChecked(false);
	ui.actionTwoStop->setChecked(false);

	//Check selected option
	((QAction*)QObject::sender())->setChecked(true);

	serial->setStopBits(QSerialPort::TwoStop);
}