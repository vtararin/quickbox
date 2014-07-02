#include "mainwindow.h"
#include "application.h"

#include <qf/core/log.h>
#include <qf/core/logdevice.h>

#include <QtQml>

int main(int argc, char *argv[])
{
	QScopedPointer<qf::core::LogDevice> file_log_device(qf::core::FileLogDevice::install());
	file_log_device->setDomainTresholds(argc, argv);
	file_log_device->setPrettyDomain(true);

	QScopedPointer<qf::core::LogDevice> signal_log_device(qf::core::SignalLogDevice::install());
	signal_log_device->setLogTreshold(qf::core::Log::LOG_DEB);

	qfError() << "QFLog(ERROR) test OK.";
	qfWarning() << "QFLog(WARNING) test OK.";
	qfInfo() << "QFLog(INFO) test OK.";
	qfDebug() << "QFLog(DEBUG) test OK.";

	qDebug() << "creating application instance";
	//qFatal("ASSERT");

	Application app(argc, argv);

	MainWindow main_window;
	//QObject::connect(signal_log_device.data(), &qf::core::SignalLogDevice::logEntry, &main_window, &MainWindow::logEntry, Qt::QueuedConnection);
	QObject::connect(signal_log_device.data(), SIGNAL(logEntry(int, QVariantMap)),
					 &main_window, SIGNAL(logEntry(int, QVariantMap)),
					 Qt::QueuedConnection);
	main_window.loadPlugins();
	main_window.show();

	int ret = app.exec();

	return ret;
}
