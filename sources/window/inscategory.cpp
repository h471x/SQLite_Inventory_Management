#include "headers/window/inscategory.h"
#include "ui_inscategory.h"
#include "headers/window/mainapp.h"

InsertCategory::InsertCategory(QDialog *parent) :
    QDialog(parent),
    InsertCategoryUi(new Ui::InsertCategory)
{
    InsertCategoryUi->setupUi(this);
    keyConfig();
}

InsertCategory::~InsertCategory()
{
    delete InsertCategoryUi;
}

void InsertCategory::on_InsertCategoryBtn_clicked()
{
    QString category = InsertCategoryUi->CategoryName->text();
    QString seuil = InsertCategoryUi->Threshold->text();
    int threshold = seuil.toInt();

    // Use placeholders in the query
    query.prepare("INSERT OR IGNORE INTO CATEGORIE(NomCategorie, SeuilCategorie) VALUES(:nom, :seuil)");
    query.bindValue(":nom", category);
    query.bindValue(":seuil", threshold);
    query.exec();
    this->close();
    MainApp *app = new MainApp();
    app->focusMenu();
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



