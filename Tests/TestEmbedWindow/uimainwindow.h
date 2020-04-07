#ifndef UIMAINWINDOW_H
#define UIMAINWINDOW_H

#pragma execution_character_set("utf-8")
#include <QApplication>
#include <QMainWindow>
#include <QMouseEvent>
#include <QKeyEvent>

class uiMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit uiMainWindow(HWND hWnd);
protected:

	//don't accept drop event from another application
	bool eventFilter(QObject *target, QEvent *event) override;

	void mousePressEvent(QMouseEvent* evnet) override;
	void mouseDoubleClickEvent(QMouseEvent* evnet) override;

	void keyPressEvent(QKeyEvent* event) override;
	void keyReleaseEvent(QKeyEvent* event) override;
	bool event(QEvent *event2) override;
	HWND m_hwnd;
	QTabWidget* m_tabWidget = nullptr;
	QWidget* m_unityWindowContainer = nullptr;
	QWindow* m_unityWindow = nullptr;
};

#endif // UIMAINWINDOW_H
