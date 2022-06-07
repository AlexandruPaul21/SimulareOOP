//
// Created by Alexandru-Paul Sirbu on 19.05.2022.
//

#ifndef SIMULAREOOP_REPO_H
#define SIMULAREOOP_REPO_H

#include "domain.h"
#include <vector>
#include <fstream>
#include <sstream>

class FileRepo{
private:
    vector<Student> studs;
    string filename;
    void load_from_file();
    //void save_to_file();
public:
    //basic constructor
    FileRepo(string file);

    //adauga sutdent in lista
    void add_stud(Student s);

    //returneaza toate elementele
    vector<Student> get_all();

    void erase_item(int poz);

};

void test_repo();

#endif //SIMULAREOOP_REPO_H
