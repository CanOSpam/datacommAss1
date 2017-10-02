#include "DumbTerminalEmulator.h"
#include <qdebug.h>
#include "console.h"

DumbTerminalEmulator::DumbTerminalEmulator(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	serial = new QSerialPort("COM1", this);
	console = new Console;
	setCentralWidget(console);

	console->setLocalEchoEnabled(true);

	//Set defaults
	serial->setPortName("COM1");
	serial->setBaudRate(QSerialPort::Baud1200);
	serial->setDataBits(QSerialPort::Data8);
	serial->setParity(QSerialPort::EvenParity);
	serial->setStopBits(QSerialPort::OneStop);
	serial->setFlowControl(QSerialPort::NoFlowControl);
	

	//Connection menu connects
	connect(ui.actionConnect, &QAction::triggered, this, &DumbTerminalEmulator::connectSerial);
	connect(ui.actionDisconnect, &QAction::triggered, this, &DumbTerminalEmulator::disconnectSerial);

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

	//Reading Connect
	connect(serial, &QSerialPort::readyRead, this, &DumbTerminalEmulator::readData);

	//Writing Connect
	connect(console, &Console::getData, this, &DumbTerminalEmulator::writeData);
}


void DumbTerminalEmulator::writeData(const QByteArray &data)
{
	serial->write(data);
}

void DumbTerminalEmulator::readData()
{
	QByteArray data = serial->readAll();
	console->putData(data);
}

void DumbTerminalEmulator::connectSerial()
{
	if (!serial->open(QIODevice::ReadWrite)) {
		qDebug() << serial->errorString();
		return;
	}
	else
	{
		qDebug() << serial->isOpen();
		qDebug() << serial->baudRate();
		qDebug() << serial->portName();
	}
}

void DumbTerminalEmulator::disconnectSerial()
{

	if (serial->isOpen())
		serial->flush();
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

	switch (baudRate)
	{
		case 1200:
			serial->setBaudRate(QSerialPort::Baud1200);
		break;

		case 2400:
			serial->setBaudRate(QSerialPort::Baud2400);
		break;

		case 4800:
			serial->setBaudRate(QSerialPort::Baud4800);
		break;

		case 9600:
			serial->setBaudRate(QSerialPort::Baud9600);
		break;

		case 19200:
			serial->setBaudRate(QSerialPort::Baud19200);
		break;

		case 38400:
			serial->setBaudRate(QSerialPort::Baud38400);
		break;

		case 57600:
			serial->setBaudRate(QSerialPort::Baud57600);
		break;

		case 115200:
			serial->setBaudRate(QSerialPort::Baud115200);
		break;

	default:
		break;
	}
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

	serial->setPortName("COM1");
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

	serial->setPortName("COM2");
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

	serial->setPortName("COM3");
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

	serial->setPortName("COM4");
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