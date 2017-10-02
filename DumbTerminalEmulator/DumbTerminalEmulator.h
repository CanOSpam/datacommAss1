#pragma once

#include <QtWidgets/QMainWindow>
#include <QtSerialPort/QSerialPort>
#include "ui_DumbTerminalEmulator.h"

class Console;

class DumbTerminalEmulator : public QMainWindow
{
	Q_OBJECT

public:
	DumbTerminalEmulator(QWidget *parent = Q_NULLPTR);

private:
	Ui::DumbTerminalEmulatorClass ui;
	QSerialPort *serial;
	Console *console;

	QActionGroup *comGroup;
	QActionGroup *baudGroup;
	QActionGroup *parityGroup;
	QActionGroup *stopGroup;


private slots:

	void writeData(const QByteArray &data);
	void readData();
	void connectSerial();
	void disconnectSerial();

	//Set Baud Rate
	void baudSet();
	
	//Set Com port
	void port1Enable();
	void port2Enable();
	void port3Enable();
	void port4Enable();

	//Set Parity
	void setEven();
	void setOdd();
	void setNone();

	//Set Stop Bits
	void stop1();
	void stop1_5();
	void stop2();
};
