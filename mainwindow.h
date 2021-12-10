#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "question.h"
#include "reponse.h"

#include <QMainWindow>
#include <QDialog>
#include <QVector>
#include <QCheckBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void ShowQuestion(const Question &q);


private slots:
    void on_NextPage_clicked();

    void on_PrevPage_clicked();

    void on_Terminer_clicked();

private:
    QVector<QCheckBox *> choices;
    bool reponses[3][4] = {{false}};
    std::vector<Question> questions;
    int counter=0;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
