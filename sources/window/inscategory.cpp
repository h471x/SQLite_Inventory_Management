#include "headers/window/inscategory.h"
#include "ui_inscategory.h"
#include "headers/window/mainapp.h"

InsertCategory::InsertCategory(QDialog *parent) :
    QDialog(parent),
    InsertCategoryUi(new Ui::InsertCategory)
{
    InsertCategoryUi->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    QDialog dialog;
    dialog.setStyleSheet("QDialog { background-color: #c5cad6; }");

    keyConfig();
}

InsertCategory::~InsertCategory()
{
    delete InsertCategoryUi;
}

void setRedBorderCategory(QLineEdit* lineEdit) {
    QString styleSheet = "QLineEdit { border-bottom: 4px solid red; }";
    lineEdit->setStyleSheet(styleSheet);
}

void InsertCategory::keyConfig(){
    // Connect returnPressed() signal of UsernameLineEdit to switch focus to PasswordLineEdit
    connect(InsertCategoryUi->CategoryName, &QLineEdit::returnPressed, this, [=]() {
        InsertCategoryUi->Threshold->setFocus();
    });

    // Connect returnPressed() signal of PasswordLineEdit to trigger the login button
    connect(InsertCategoryUi->Threshold, &QLineEdit::returnPressed, this, &InsertCategory::on_InsertCategoryBtn_clicked);

    // Connect the clicked() signal of the LoginButton to your login function
    connect(InsertCategoryUi->InsertCategoryBtn, &QPushButton::clicked, this, &InsertCategory::on_InsertCategoryBtn_clicked);

    connect(InsertCategoryUi->CategoryName, &QLineEdit::textChanged, this, [=]() {
        if (!inserted) {
            // Reset the border when user starts typing
            InsertCategoryUi->CategoryName->setStyleSheet("");
        }
    });

    connect(InsertCategoryUi->Threshold, &QLineEdit::textChanged, this, [=]() {
        if (!inserted) {
            // Reset the border when user starts typing
            InsertCategoryUi->Threshold->setStyleSheet("");
        }
    });
}

// Detects the arrow keys to change focus within the LoginUi
void InsertCategory::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Up) {
        //if Password as focus then focus on Username
        if (InsertCategoryUi->Threshold->hasFocus()) {
            InsertCategoryUi->CategoryName->setFocus();
        }
    } else if (event->key() == Qt::Key_Down) {
        //if Username has focus then focus on Password
        if (InsertCategoryUi->CategoryName->hasFocus()) {
            InsertCategoryUi->Threshold->setFocus();
        }
    }
}

void InsertCategory::on_InsertCategoryBtn_clicked()
{
    QString category = InsertCategoryUi->CategoryName->text();
    QString seuil = InsertCategoryUi->Threshold->text();

    bool isSeuilEmpty = seuil.isEmpty();
    bool isCategoryEmpty = category.isEmpty();

    if (isSeuilEmpty && isCategoryEmpty) {
        error();
        return;
    } else if (isCategoryEmpty) {
        error(); // Category must not be empty
        return;
    } else if (!isSeuilEmpty) {
        bool isSeuilNumber;
        int threshold = seuil.toInt(&isSeuilNumber);

        if (!isSeuilNumber) {
            error(); // Seuil must be a number
            return;
        } else {
            query.prepare("INSERT INTO CATEGORIE(NomCategorie, SeuilCategorie) SELECT :nom, :seuil WHERE NOT EXISTS (SELECT 1 FROM CATEGORIE WHERE NomCategorie = :nom)");
            query.bindValue(":nom", category);
            query.bindValue(":seuil", threshold);
        }
    } else {
        query.prepare("INSERT INTO CATEGORIE(NomCategorie) SELECT :nom WHERE NOT EXISTS (SELECT 1 FROM CATEGORIE WHERE NomCategorie = :nom)");
        query.bindValue(":nom", category);
    }

    if (query.exec()) {
        if (query.numRowsAffected() > 0) {
            this->close();
        } else {
//            QMessageBox msgBox;
//            msgBox.setStyleSheet("color: black;"); // Set text color to black
//            msgBox.critical(this, "Error", " .");
            error(); //Already Existing Category
        }
    } else {
        return;
    }
}


void InsertCategory::error(){
    InsertCategoryUi->CategoryName->clear();
    InsertCategoryUi->Threshold->clear();
    setRedBorderCategory(InsertCategoryUi->CategoryName);
    setRedBorderCategory(InsertCategoryUi->Threshold);
    InsertCategoryUi->CategoryName->setFocus();
}



