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

private slots:

	void openPort();
	void closePort();
	void writeData(const QByteArray &data);
	void readData();
	void openConfig();
};
