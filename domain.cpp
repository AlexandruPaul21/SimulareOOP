//
// Created by Alexandru-Paul Sirbu on 19.05.2022.
//

#include "domain.h"

Student::Student(string cod, string name, string sname, string clas, double medie) {
    this->cod=cod;
    this->name=name;
    this->sname=sname;
    this->clas=clas;
    this->medie=medie;
}

string Student::get_cod() {
    return cod;
}

string Student::get_name() {
    return name;
}

string Student::get_sname() {
    return sname;
}

string Student::get_clas() {
    return clas;
}

double Student::get_medie() {
    return medie;
}

void test_domain(){
    auto elem= Student("06660","Guta","Liviu","4",5.76);
    assert(elem.get_cod()=="06660");
    assert(elem.get_name()=="Guta");
    assert(elem.get_sname()=="Liviu");
    assert(elem.get_clas()=="4");
    assert(elem.get_medie()==5.76);
}