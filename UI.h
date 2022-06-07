//
// Created by Alexandru-Paul Sirbu on 19.05.2022.
//

#ifndef SIMULAREOOP_UI_H
#define SIMULAREOOP_UI_H

#include "service.h"
#include <QWidget>
#include <QListWidget>
#include <QLayout>
#include <QLabel>
#include <QFormLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>

/**
 * Clasa de GUI
 * */
class GUI:public QWidget{
private:
    Service& srv;
    QHBoxLayout* lyMain=new QHBoxLayout;
    QListWidget* lst;
    QWidget* del_zone;
    QVBoxLayout* del_ly;
    vector<QPushButton*> buts;
    QLineEdit* txtName;
    QLineEdit* txtSname;
    QLineEdit* txtClas;
    QLineEdit* txtMed;
    QPushButton* btnMed;
    QPushButton* btnCls;
    QPushButton* btnNm;
    QPushButton* btnR;

    //initializeaza GUI
    void init_GUI();
    //conecteaza semnalele
    void connectSignals();
    //reia lista de elemente
    void reloadList(vector<Student> all);
public:
    //constructor
    GUI(Service& sv);
};

#endif //SIMULAREOOP_UI_H
