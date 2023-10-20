#ifndef PDFSAVE_H
#define PDFSAVE_H

#include <QString>
#include <QPainter>
#include <QPrinter>
#include <QFont>
#include <QDate>
#include <QFileDialog>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDateTime>
#include <QStringList>
#include <QVariant>

class PdfSave {
public:
    PdfSave(const QString& title, const QString& query);

    void savePDF();

private:
    QString title;
    QString query;
};

#endif // PDFSAVE_H
