#include "headers/window/pdfsave.h"

PdfSave::PdfSave(const QString& title, const QString& query)
    : title(title), query(query) {
}

void PdfSave::savePDF() {
    // Select the path for the output PDF
    QString pdfPath = QFileDialog::getSaveFileName(nullptr, "Save PDF File", "", "PDF Files (*.pdf)");

    if (pdfPath.isEmpty()) {
        // The user canceled the file dialog or didn't choose a path
        return;
    }

    // Create a PDF printer
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(pdfPath);

    if (!printer.isValid()) {
        // Handle any errors related to the printer
        return;
    }

    // Create a QPainter to draw on the PDF
    QPainter painter;
    if (!painter.begin(&printer)) {
        // Handle any errors related to QPainter initialization
        return;
    }

    // Execute the SQL query
    QSqlQuery sqlQuery(query);
    if (!sqlQuery.exec()) {
        // Handle any errors related to the query execution
        return;
    }

    // Get the column names from the query result
    QStringList headers;
    QSqlRecord record = sqlQuery.record();
    for (int i = 0; i < record.count(); i++) {
        headers.append(record.fieldName(i));
    }

    // Define the position and dimensions of the table
    int tableX = 50;
    int tableY = 100; // Adjust the vertical position for the title
    int cellHeight = 30;

    // Calculate the width for each header
    int headerWidth = (printer.width() - tableX) / headers.size();

    // Draw the title with the current date
    painter.setFont(QFont("Arial", 16, QFont::Bold));
    QString formattedDate = QDate::currentDate().toString("dd/MM/yyyy");
    painter.drawText(tableX, tableY - 50, printer.width(), 40, Qt::AlignCenter, title + " " + formattedDate);

    // Draw the table headers and grid
    painter.setFont(QFont("Arial", 10, QFont::Bold));
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine));
    int x = tableX;
    for (int i = 0; i < headers.size(); i++) {
        painter.drawText(x, tableY, headerWidth, cellHeight, Qt::AlignCenter, headers[i]);
        painter.drawRect(x, tableY, headerWidth, cellHeight);
        x += headerWidth;
    }

    // Draw the table data and grid
    painter.setFont(QFont("Arial", 10));
    int row = 1; // Start from the second row (first row is for headers)
    while (sqlQuery.next()) {
        x = tableX;
        for (int i = 0; i < headers.size(); i++) {
            QString data = sqlQuery.value(i).toString();
            painter.drawText(x, tableY + row * cellHeight, headerWidth, cellHeight, Qt::AlignCenter, data);
            painter.drawRect(x, tableY + row * cellHeight, headerWidth, cellHeight);
            x += headerWidth;
        }
        row++;
    }

    painter.end();
}
