#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QString>
#include "mainwindow.h"

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_loginBtn_clicked();

private:
    MainWindow *mw;
    Ui::login *ui;
    std::vector<std::vector<QString>> matricules;
};

#endif // LOGIN_H
