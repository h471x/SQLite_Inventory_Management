#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include "headers/database/init/dbinit.h"

class TableView : public QSqlTableModel {
public:
    TableView(QObject *parent, QSqlDatabase db = QSqlDatabase())
        : QSqlTableModel(parent, db) {}

public:
    void setQuery(const QString &query) {
        QSqlQuery q;
        q.prepare(query);
        if (q.exec()) {
            QSqlTableModel::setQuery(q);
        }
    }
};

#endif // TABLEVIEW_H
