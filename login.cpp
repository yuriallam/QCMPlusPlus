#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "QDialog"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    mw = new MainWindow();
    ui->setupUi(this);
    ui->password->setEchoMode(QLineEdit::Password);

    matricules.push_back({"200447","bonjour"});
    matricules.push_back({"200448","bye"});
    matricules.push_back({"200489","merci"});

}

login::~login()
{
    delete ui;
    delete mw;
}

void login::on_loginBtn_clicked()
{
    bool valid = false;
    QString matrix = ui->matricule->text();
    QString pass = ui->password->text();


    for (int i=0;i<matricules.size() ;++i ) {
        if(matrix == matricules[i][0] && pass==matricules[i][1]){
            valid=true;
            mw->show();
            hide();
        }
    }
    if (!valid){
        ui->status->setText("Invalid input");
    }
}

