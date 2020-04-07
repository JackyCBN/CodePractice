#include "uimainwindow.h"
#include <QFileDialog>
#include <QTimer>
#include <QSignalMapper>
#include <QFormLayout>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QLabel>
#include <QWindow>
#include <Windows.h>
#include <QDebug>
#include <QtGui/5.10.1/QtGui/qpa/qplatformnativeinterface.h>

uiMainWindow::uiMainWindow(HWND hWnd)
	:m_hwnd(hWnd)
{
	m_tabWidget = new QTabWidget();
	setCentralWidget(m_tabWidget);
	m_tabWidget->setTabsClosable(true);
	m_tabWidget->setMovable(true);
	m_tabWidget->setFocusPolicy(Qt::FocusPolicy::StrongFocus);


	auto label = new QLabel("ClickMidMouseBtn");
	m_tabWidget->addTab(label,"tab");


}

bool uiMainWindow::eventFilter(QObject* target, QEvent* event)
{
	if (event->type() == QEvent::FocusIn)
		qDebug() << "focusIn" << target;

	if (event->type() == QEvent::FocusOut)
		qDebug() << "focusOut" << target;
	return QMainWindow::eventFilter(target, event);
}
static QWindow* windowForWidget(const QWidget* widget)
{
	QWindow* window = widget->windowHandle();
	if (window)
		return window;
	const QWidget* nativeParent = widget->nativeParentWidget();
	if (nativeParent)
		return nativeParent->windowHandle();
	return 0;
}
HWND getHWNDForWidget(const QWidget* widget)
{
	QWindow* window = ::windowForWidget(widget);
	if (window && window->handle())
	{
		QPlatformNativeInterface* interface2 = QGuiApplication::platformNativeInterface();
		return static_cast<HWND>(interface2->nativeResourceForWindow(QByteArrayLiteral("handle"), window));
	}
	return 0;
}

bool bClicked = false;
void uiMainWindow::mousePressEvent(QMouseEvent* evnet2)
{
	if (evnet2->button() == Qt::MouseButton::MidButton)
	{
		if(!bClicked)
		{
			bClicked = true;
			m_tabWidget->removeTab(0);
			//style |= WS_CHILD; // owned window of this one...
			m_unityWindow = QWindow::fromWinId((WId)m_hwnd);
			m_unityWindow->setObjectName("xxxxx");
			m_unityWindowContainer = QWidget::createWindowContainer(m_unityWindow/*, this, Qt::Widget*/);
			//m_unityWindowContainer->setMinimumSize(m_unityWindow->size());
			if (m_unityWindowContainer)
			{
				m_tabWidget->addTab(m_unityWindowContainer, "Main");
			}

			m_unityWindowContainer->setFocusPolicy(Qt::StrongFocus);

			// fix focus not get
			long style = GetWindowLong(m_hwnd, GWL_STYLE);  // WINDOWS CALL

			style &= ~WS_CHILD;
			style |= WS_POPUP; // owned window of this one...

			style &= ~WS_CAPTION;
			style &= ~WS_BORDER;
			style &= ~WS_THICKFRAME;

			SetWindowLong(m_hwnd, GWL_STYLE, style);  // WINDOWS CALL

			m_unityWindow->installEventFilter(this);
		}

	}
	QMainWindow::mousePressEvent(evnet2);
}

void uiMainWindow::mouseDoubleClickEvent(QMouseEvent* evnet2)
{
	QMainWindow::mouseDoubleClickEvent(evnet2);
}

void uiMainWindow::keyPressEvent(QKeyEvent* event)
{
	QMainWindow::keyPressEvent(event);
}

void uiMainWindow::keyReleaseEvent(QKeyEvent* event)
{
	QMainWindow::keyReleaseEvent(event);
}

bool uiMainWindow::event(QEvent* event)
{
	//if (event->type() == QEvent::ActivationChange ||
	//	event->type() == QEvent::WindowUnblocked) {
	//	if(this->isActiveWindow() && m_unityWindowContainer &&m_unityWindow)
	//	{
	//		//m_unityWindowContainer->activateWindow();
	//		//m_unityWindow->requestActivate();
	//		m_unityWindowContainer->setFocus();
	//		//window()->activateWindow();
	//		return true;
	//	}		
	//}
	// handle events that don't match
	return QWidget::event(event);
}
