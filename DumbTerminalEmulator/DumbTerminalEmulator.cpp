/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: DumbTerminalEmulator.cpp - An application that can send and receive characters 
--					over an RS232 connection.
--
-- PROGRAM: DumbTerminalEmulator
--
-- FUNCTIONS:
-- Serial port operation functions:
--		void writeData(const QByteArray &data)
--		void readData()
--		void connectSerial()
--		void disconnectSerial()
--
-- Serial port Configuration functions:
--		void baudSet()
--		void port1Enable()
--		void port2Enable()
--		void port3Enable()
--		void port4Enable()
--		void setEven()
--		void setOdd()
--		void setNone()
--		void stop1()
--		void stop1_5()
--		void stop2()
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
-- The program will take configuration from the user, use that configuration to open a serial port, and then use
-- that serial port to communicate with another RS232 terminal application.
--
-- The user can configure the com port, the baud rate, the parity, and the stop bits of the connection.
-- 
-- Local echo is disabled, but may be enabled in the source code on line 58.
----------------------------------------------------------------------------------------------------------------------*/

#include "DumbTerminalEmulator.h"
#include <qdebug.h>
#include <qactiongroup.h>
#include "console.h"

DumbTerminalEmulator::DumbTerminalEmulator(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	serial = new QSerialPort("COM1", this);
	console = new Console;
	setCentralWidget(console);

	console->setLocalEchoEnabled(false);

	//Set defaults
	serial->setPortName("COM1");
	serial->setBaudRate(QSerialPort::Baud2400);
	serial->setDataBits(QSerialPort::Data8);
	serial->setParity(QSerialPort::NoParity);
	serial->setStopBits(QSerialPort::OneStop);
	serial->setFlowControl(QSerialPort::HardwareControl);

	//QAction Groups
	comGroup = new QActionGroup(this);
	comGroup->addAction(ui.actionCom_1);
	comGroup->addAction(ui.actionCom_2);
	comGroup->addAction(ui.actionCom_3);
	comGroup->addAction(ui.actionCom_4);

	baudGroup = new QActionGroup(this);
	baudGroup->addAction(ui.action1200);
	baudGroup->addAction(ui.action2400);
	baudGroup->addAction(ui.action4800);
	baudGroup->addAction(ui.action9600);
	baudGroup->addAction(ui.action19200);
	baudGroup->addAction(ui.action38400);
	baudGroup->addAction(ui.action57600);
	baudGroup->addAction(ui.action115200);

	parityGroup = new QActionGroup(this);
	parityGroup->addAction(ui.actionEven);
	parityGroup->addAction(ui.actionOdd);
	parityGroup->addAction(ui.actionNone);

	stopGroup = new QActionGroup(this);
	stopGroup->addAction(ui.actionOneStop);
	stopGroup->addAction(ui.actionOneAndAHalfStop);
	stopGroup->addAction(ui.actionTwoStop);

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




/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: writeData
--
-- DATE: October 4th, 2017
--
-- REVISIONS: None
--
-- DESIGNER: Tim Bruecker
--
-- PROGRAMMER: Tim Bruecker
--
-- INTERFACE: void writeData(const QByteArray &data)
--
-- RETURNS: void
--
-- NOTES:
-- Call this function to write (send) data to the serial port. This function is called when a keystroke is registered
-- in console.cpp.
----------------------------------------------------------------------------------------------------------------------*/
void DumbTerminalEmulator::writeData(const QByteArray &data)
{
	serial->write(data);
}


/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: readData
--
-- DATE: October 4th, 2017
--
-- REVISIONS: None
--
-- DESIGNER: Tim Bruecker
--
-- PROGRAMMER: Tim Bruecker
--
-- INTERFACE: void readData()
--
-- RETURNS: void
--
-- NOTES:
-- Call this function to read data from the serial port. This function is called when the serial port object emits a 
-- readyRead signal.
----------------------------------------------------------------------------------------------------------------------*/
void DumbTerminalEmulator::readData()
{
	QByteArray data = serial->readAll();
	console->putData(data);
}


/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: connectSerial
--
-- DATE: October 4th, 2017
--
-- REVISIONS: None
--
-- DESIGNER: Tim Bruecker
--
-- PROGRAMMER: Tim Bruecker
--
-- INTERFACE: void connectSerial()
--
-- RETURNS: void
--
-- NOTES:
-- Call this function to open a serial port using the configuration options that have been set by the user.
----------------------------------------------------------------------------------------------------------------------*/
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


/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: disconnectSerial
--
-- DATE: October 4th, 2017
--
-- REVISIONS: None
--
-- DESIGNER: Tim Bruecker
--
-- PROGRAMMER: Tim Bruecker
--
-- INTERFACE: void disconnectSerial()
--
-- RETURNS: void
--
-- NOTES:
-- Call this function to flush and close the open serial port.
----------------------------------------------------------------------------------------------------------------------*/
void DumbTerminalEmulator::disconnectSerial()
{

	if (serial->isOpen())
		serial->flush();
		serial->close();
}


/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: baudSet
--
-- DATE: October 4th, 2017
--
-- REVISIONS: None
--
-- DESIGNER: Tim Bruecker
--
-- PROGRAMMER: Tim Bruecker
--
-- INTERFACE: void baudSet()
--
-- RETURNS: void
--
-- NOTES:
-- Call this function to set the baud rate that the serial port will use. This function is called by all of the
-- baud set actions in the baud setting action group. The function reads the text value in the baud actions, and assigns
-- that value to the serial port baud rate.
----------------------------------------------------------------------------------------------------------------------*/
void DumbTerminalEmulator::baudSet()
{
	int baudRate =((QAction*)QObject::sender())->text().toInt();

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



/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: port1Enable
--
-- DATE: October 4th, 2017
--
-- REVISIONS: None
--
-- DESIGNER: Tim Bruecker
--
-- PROGRAMMER: Tim Bruecker
--
-- INTERFACE: void port1Enable()
--
-- RETURNS: void
--
-- NOTES:
-- Call this function to set the serial port to use COM1 as the communications port. This function is called by the
-- COM1 action.
----------------------------------------------------------------------------------------------------------------------*/
void DumbTerminalEmulator::port1Enable()
{
	//Check selected option
	((QAction*)QObject::sender())->setChecked(true);

	serial->setPortName("COM1");
}


/*--------- COMM SET FUNCTIONS ---------*/
/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: port2Enable
--
-- DATE: October 4th, 2017
--
-- REVISIONS: None
--
-- DESIGNER: Tim Bruecker
--
-- PROGRAMMER: Tim Bruecker
--
-- INTERFACE: void port2Enable()
--
-- RETURNS: void
--
-- NOTES:
-- Call this function to set the serial port to use COM2 as the communications port. This function is called by the
-- COM2 action.
----------------------------------------------------------------------------------------------------------------------*/
void DumbTerminalEmulator::port2Enable()
{
	//Check selected option
	((QAction*)QObject::sender())->setChecked(true);

	serial->setPortName("COM2");
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: port3Enable
--
-- DATE: October 4th, 2017
--
-- REVISIONS: None
--
-- DESIGNER: Tim Bruecker
--
-- PROGRAMMER: Tim Bruecker
--
-- INTERFACE: void port3Enable()
--
-- RETURNS: void
--
-- NOTES:
-- Call this function to set the serial port to use COM3 as the communications port. This function is called by the
-- COM3 action.
----------------------------------------------------------------------------------------------------------------------*/
void DumbTerminalEmulator::port3Enable()
{
	//Check selected option
	((QAction*)QObject::sender())->setChecked(true);

	serial->setPortName("COM3");
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: port4Enable
--
-- DATE: October 4th, 2017
--
-- REVISIONS: None
--
-- DESIGNER: Tim Bruecker
--
-- PROGRAMMER: Tim Bruecker
--
-- INTERFACE: void port4Enable()
--
-- RETURNS: void
--
-- NOTES:
-- Call this function to set the serial port to use COM4 as the communications port. This function is called by the
-- COM4 action.
----------------------------------------------------------------------------------------------------------------------*/
void DumbTerminalEmulator::port4Enable()
{
	//Check selected option
	((QAction*)QObject::sender())->setChecked(true);

	serial->setPortName("COM4");
}

/*--------- PARITY SET FUNCTIONS ---------*/
/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: setEven
--
-- DATE: October 4th, 2017
--
-- REVISIONS: None
--
-- DESIGNER: Tim Bruecker
--
-- PROGRAMMER: Tim Bruecker
--
-- INTERFACE: void setEven()
--
-- RETURNS: void
--
-- NOTES:
-- Call this function to set the serial port to use 'even' parity. This function is called by the setEven action.
----------------------------------------------------------------------------------------------------------------------*/
void DumbTerminalEmulator::setEven()
{
	//Check selected option
	((QAction*)QObject::sender())->setChecked(true);

	serial->setParity(QSerialPort::EvenParity);

}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: setOdd
--
-- DATE: October 4th, 2017
--
-- REVISIONS: None
--
-- DESIGNER: Tim Bruecker
--
-- PROGRAMMER: Tim Bruecker
--
-- INTERFACE: void setOdd()
--
-- RETURNS: void
--
-- NOTES:
-- Call this function to set the serial port to use 'odd' parity. This function is called by the setEven action.
----------------------------------------------------------------------------------------------------------------------*/
void DumbTerminalEmulator::setOdd()
{
	//Check selected option
	((QAction*)QObject::sender())->setChecked(true);

	serial->setParity(QSerialPort::OddParity);
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: setNone
--
-- DATE: October 4th, 2017
--
-- REVISIONS: None
--
-- DESIGNER: Tim Bruecker
--
-- PROGRAMMER: Tim Bruecker
--
-- INTERFACE: void setNone()
--
-- RETURNS: void
--
-- NOTES:
-- Call this function to set the serial port to use 'none' parity. This function is called by the setEven action.
----------------------------------------------------------------------------------------------------------------------*/
void DumbTerminalEmulator::setNone()
{
	//Check selected option
	((QAction*)QObject::sender())->setChecked(true);

	serial->setParity(QSerialPort::NoParity);
}


/*--------- PARITY SET FUNCTIONS ---------*/
/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: stop1
--
-- DATE: October 4th, 2017
--
-- REVISIONS: None
--
-- DESIGNER: Tim Bruecker
--
-- PROGRAMMER: Tim Bruecker
--
-- INTERFACE: void stop1()
--
-- RETURNS: void
--
-- NOTES:
-- Call this function to set the serial port to use one stop bit. This function is called by the 1 stop action.
----------------------------------------------------------------------------------------------------------------------*/
void DumbTerminalEmulator::stop1()
{
	//Check selected option
	((QAction*)QObject::sender())->setChecked(true);

	serial->setStopBits(QSerialPort::OneStop);
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: stop1_5
--
-- DATE: October 4th, 2017
--
-- REVISIONS: None
--
-- DESIGNER: Tim Bruecker
--
-- PROGRAMMER: Tim Bruecker
--
-- INTERFACE: void stop1_5()
--
-- RETURNS: void
--
-- NOTES:
-- Call this function to set the serial port to use one and a half stop bits. 
-- This function is called by the 1.5 stop action.
----------------------------------------------------------------------------------------------------------------------*/
void DumbTerminalEmulator::stop1_5()
{
	//Check selected option
	((QAction*)QObject::sender())->setChecked(true);

	serial->setStopBits(QSerialPort::OneAndHalfStop);
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: stop2
--
-- DATE: October 4th, 2017
--
-- REVISIONS: None
--
-- DESIGNER: Tim Bruecker
--
-- PROGRAMMER: Tim Bruecker
--
-- INTERFACE: void stop2()
--
-- RETURNS: void
--
-- NOTES:
-- Call this function to set the serial port to use one stop bit. This function is called by the 2 stop action.
----------------------------------------------------------------------------------------------------------------------*/
void DumbTerminalEmulator::stop2()
{
	//Check selected option
	((QAction*)QObject::sender())->setChecked(true);

	serial->setStopBits(QSerialPort::TwoStop);
}