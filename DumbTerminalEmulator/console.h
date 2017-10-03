#pragma once
#include <QPlainTextEdit>

class Console : public QPlainTextEdit
{
	Q_OBJECT

signals:
	void getData(const QByteArray &data);

public:
	explicit Console(QWidget *parent = 0);
	void putData(const QByteArray &data);
	void setLocalEchoEnabled(bool set);

protected:
	virtual void keyPressEvent(QKeyEvent *e);

private:
	bool localEchoEnabled;

};
