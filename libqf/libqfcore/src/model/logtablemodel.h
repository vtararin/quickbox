#ifndef QF_CORE_MODEL_LOGTABLEMODEL_H
#define QF_CORE_MODEL_LOGTABLEMODEL_H

#include "../core/coreglobal.h"
#include "../core/logcore.h"

#include <QAbstractTableModel>

namespace qf {
namespace core {
namespace model {

class QFCORE_DECL_EXPORT LogTableModel : public QAbstractTableModel
{
	Q_OBJECT
private:
	typedef QAbstractTableModel Super;
public:
	enum Cols {Severity, Category, File, Line, Message, TimeStamp, UserData, Count};
	class Row {
	public:
		explicit Row() {}
		explicit Row(qf::core::Log::Level severity, const QString& domain, const QString& file, int line, const QString& msg, const QDateTime& time_stamp, const QVariant &user_data = QVariant());

		QVariant value(int col) const;
	private:
		QVector<QVariant> m_data;
	};
public:
	LogTableModel(QObject *parent = 0);

	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
	int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
	int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
	QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;

	void clear();
	Row rowAt(int row) const;
	void addLogEntry(qf::core::Log::Level severity, const QString& category, const QString &file, int line, const QString& msg, const QDateTime& time_stamp, const QVariant &user_data = QVariant());
private:
	QList<Row> m_rows;
};

}}}

#endif // QF_CORE_MODEL_LOGTABLEMODEL_H
