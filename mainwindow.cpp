#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "question.h"
#include "reponse.h"
#include <vector>
#include <iostream>
#include<string>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Question q0("Quelle est la capitale du Liban?");
    q0.ajouter(Reponse("Beirut", true));
    q0.ajouter(Reponse("Paris"));
    q0.ajouter(Reponse("Tripoli"));
    q0.ajouter(Reponse("Adonis"));

    Question q1("3+2=");
    q1.ajouter(Reponse("5", true));
    q1.ajouter(Reponse("6-1", true));
    q1.ajouter(Reponse("1+4", true));
    q1.ajouter(Reponse("25/5", true));

    Question q2("Qui est le plus beau?");
    q2.ajouter(Reponse("Youssef"));
    q2.ajouter(Reponse("Bakouny", true));
    q2.ajouter(Reponse("Flavia"));
    q2.ajouter(Reponse("Rita"));

    questions.push_back(q0);
    questions.push_back(q1);
    questions.push_back(q2);

    choices = {ui->choix1,ui->choix2,ui->choix3,ui->choix4};
    ShowQuestion(questions[counter]);
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ShowQuestion(const Question &q)
{
    ui->question->setText(QString::fromStdString(q.getTexte()));
    for (int i=0;i<4 ;++i ) {
        choices[i]->setText(QString::fromStdString(q[i].getTexte()));
        choices[i]->setChecked(reponses[counter][i]);
    }
}


void MainWindow::on_NextPage_clicked()
{
    for (int i = 0; i < 4;++i) {
        reponses[counter][i] = choices[i]->isChecked();
    }

    int n=questions.size();
    if(counter==n-1){
        counter=-1;
    }
    counter++;
    ShowQuestion(questions[counter]);
}


void MainWindow::on_PrevPage_clicked()
{
    for (int i = 0; i < 4;++i) {
        reponses[counter][i] = choices[i]->isChecked();
    }

    int n=questions.size();
    if(counter==0){
        counter=n;
    }
    --counter;

    ShowQuestion(questions[counter]);
}


void MainWindow::on_Terminer_clicked()
{
    int note=0;
    for(int i=0; i<3;++i){
        for (int j=0; j<4;++j){
            if (reponses[i][j]){
                if(questions[i][j].isCorrect()){
                    note+=1;

                }
            }
        }
    }

    string snote = to_string(note);
    ui->note->setText(QString::fromStdString(snote));
    ui->NextPage->setEnabled(false);
    ui->PrevPage->setEnabled(false);
    for (int i = 0; i<4 ;++i ) {
        choices[i]->setEnabled(false);
    }

}



