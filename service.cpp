//
// Created by Alexandru-Paul Sirbu on 19.05.2022.
//

#include "service.h"


vector<Student> Service::get_all_ent() {
    return rp.get_all();
}

bool comp0(Student& a,Student& b){
    return a.get_medie()<b.get_medie();
}

bool comp1(Student& a,Student& b){
    return a.get_clas()<b.get_clas();
}

bool comp2(Student& a,Student& b){
    return a.get_name()<b.get_name();
}

vector<Student> Service::sort(int crit) {
    vector<Student> ret;
    ret.clear();
    ret=get_all_ent();
    if(crit==0){
        ::sort(ret.begin(),ret.end(), comp0);
    } else if(crit==1){
        ::sort(ret.begin(),ret.end(),comp1);
    } else if(crit==2){
        ::sort(ret.begin(),ret.end(),comp2);
    }
    return ret;
}

void Service::del(int poz) {
    rp.erase_item(poz);
}

void test_service(){
    FileRepo rp{"test.txt"};
    Service sv{rp};

    assert(sv.get_all_ent().size()==10);
    auto rez=sv.sort(2);

    assert(sv.get_all_ent().size()==10);
    sv.del(0);
    assert(sv.get_all_ent().size()==9);

}