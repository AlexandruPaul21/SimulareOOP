//
// Created by Alexandru-Paul Sirbu on 19.05.2022.
//

#ifndef SIMULAREOOP_DOMAIN_H
#define SIMULAREOOP_DOMAIN_H

#include <string>

using namespace std;

class Student{
private:
    string cod;
    string name;
    string sname;
    string clas;
    double medie;
public:
    //constructor
    Student(string cod,string name,string sname,string clas,double medie);

    //gettere si settere
    string get_cod();

    string get_name();

    string get_sname();

    string get_clas();

    double get_medie();

};

void test_domain();
#endif //SIMULAREOOP_DOMAIN_H
