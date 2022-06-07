//
// Created by Alexandru-Paul Sirbu on 19.05.2022.
//

#include "UI.h"

GUI::GUI(Service &sv) :srv{sv}{
    init_GUI();
    connectSignals();
    reloadList(srv.get_all_ent());
}

void GUI::init_GUI() {
    setLayout(lyMain);
    lst=new QListWidget;
    lyMain->addWidget(lst);

    del_zone=new QWidget;
    del_ly=new QVBoxLayout;
    del_zone->setLayout(del_ly);

    lyMain->addWidget(del_zone);

    QWidget* wdg_r=new QWidget;
    QVBoxLayout* r_lay=new QVBoxLayout;
    wdg_r->setLayout(r_lay);

    QWidget* form=new QWidget;
    QFormLayout* form_lay=new QFormLayout;
    form->setLayout(form_lay);

    QLabel* lbl_name=new QLabel("Nume");
    txtName=new QLineEdit;
    txtSname=new QLineEdit;
    txtClas=new QLineEdit;
    txtMed=new QLineEdit;
    QLabel* lbl_sname=new QLabel("Prenume");
    QLabel* lbl_clas=new QLabel("Clasa");
    QLabel* lbl_med=new QLabel("Medie");

    form_lay->addRow(lbl_name,txtName);
    form_lay->addRow(lbl_sname,txtSname);
    form_lay->addRow(lbl_clas,txtClas);
    form_lay->addRow(lbl_med,txtMed);

    r_lay->addWidget(form);

    btnNm=new QPushButton("Sort by name");
    btnMed=new QPushButton("Sort by med");
    btnCls=new QPushButton("Sort by class");
    btnR=new QPushButton("Reset");

    r_lay->addWidget(btnMed);
    r_lay->addWidget(btnCls);
    r_lay->addWidget(btnNm);
    r_lay->addWidget(btnR);

    lyMain->addWidget(wdg_r);

}

void GUI::connectSignals() {
    QObject::connect(lst,&QListWidget::itemSelectionChanged,[=](){
        QListWidgetItem* sel_item;
        if(lst->selectedItems().empty()){
            txtName->setText("");
            txtSname->setText("");
            txtClas->setText("");
            txtMed->setText("");
            return;
        }
        try{
            sel_item=lst->selectedItems().at(0);
        } catch(...){
            return;
        }
        int index=sel_item->data(Qt::UserRole).toInt();
        auto std=srv.get_all_ent()[index];
        txtName->setText(QString::fromStdString(std.get_name()));
        txtSname->setText(QString::fromStdString(std.get_sname()));
        txtClas->setText(QString::fromStdString(std.get_clas()));
        txtMed->setText(QString::number(std.get_medie()));
    });

    QObject::connect(btnR,&QPushButton::clicked,[=](){
        reloadList(srv.get_all_ent());
    });

    QObject::connect(btnNm,&QPushButton::clicked,[=](){
        reloadList(srv.sort(2));
    });

    QObject::connect(btnMed,&QPushButton::clicked,[=](){
        reloadList(srv.sort(0));
    });

    QObject::connect(btnCls,&QPushButton::clicked,[=](){
        reloadList(srv.sort(1));
    });
}

void GUI::reloadList(vector<Student> all) {
    lst->clear();
    for(auto but :buts){
        del_ly->removeWidget(but);
        delete but;
    }
    buts.clear();
    int index=0;
    for(auto elem:all){
        QListWidgetItem* itm=new QListWidgetItem(QString::fromStdString(elem.get_cod()+" "+elem.get_name()));
        itm->setData(Qt::UserRole,index);
        double medie=elem.get_medie();
        if(medie<=5){
            itm->setData(Qt::BackgroundRole,QBrush{Qt::red,Qt::SolidPattern});
        } else if(5<medie && medie<9){
            itm->setData(Qt::BackgroundRole,QBrush{Qt::yellow,Qt::SolidPattern});
        } else {
            itm->setData(Qt::BackgroundRole,QBrush{Qt::green,Qt::SolidPattern});
        }
        lst->addItem(itm);
        ++index;
        buts.push_back(new QPushButton(QString::fromStdString(elem.get_cod())));
    }
    for(auto but:buts){
        del_ly->addWidget(but);
        QObject::connect(but,&QPushButton::clicked,[=](){
            QMessageBox* box=new QMessageBox;
            box->setText("Do you want to delete?");
            box->setStandardButtons(QMessageBox::Yes|QMessageBox::No);
            auto ret=box->exec();
            switch(ret){
                case QMessageBox::Yes:
                    srv.del(0);
                    reloadList(srv.get_all_ent());
                    break;
                case QMessageBox::No:
                    box->close();
                    break;
                default:
                    box->close();
                    break;
            }
        });
    }

}
