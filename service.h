//
// Created by Alexandru-Paul Sirbu on 19.05.2022.
//

#ifndef SIMULAREOOP_SERVICE_H
#define SIMULAREOOP_SERVICE_H

#include "repo.h"
#include <algorithm>

//clasa service
class Service{
private:
    FileRepo& rp;
public:
    //constructor
    Service(FileRepo& rp): rp{rp}{};

    //returneaza toate elementele
    vector<Student> get_all_ent();

    //sorteaza pe un anumit crteriu
    vector<Student> sort(int crit);

    void del(int poz);
};

void test_service();

#endif //SIMULAREOOP_SERVICE_H
