//
// Created by Alexandru-Paul Sirbu on 19.05.2022.
//

#include "repo.h"

double to_nr(string str){
    int ip,fp,l;
    ip=fp=0;
    l=1;
    bool point=false;
    for(auto ch:str){
        if(ch=='.'){
            point=true;
        } else if('0'<=ch && ch<='9'){
            if(!point){
                ip=ip*10+(ch-'0');
            } else {
                fp=fp*10+(ch-'0');
                l=l*10;
            }
        }
    }
    return (double)ip+(double)fp/l;
}

FileRepo::FileRepo(string file) {
    filename=file;
    load_from_file();
}

void FileRepo::load_from_file() {
    ifstream fin(filename);
    string line;
    while(getline(fin,line)){
        stringstream s_line(line);
        string buffer;
        vector<string> all;
        while(getline(s_line,buffer,';')){
            all.push_back(buffer);
        }
        add_stud(Student(all[0],all[1],all[2],all[3],to_nr(all[4])));
    }
}

void FileRepo::add_stud(Student s) {
    studs.push_back(s);
}

vector<Student> FileRepo::get_all() {
    return studs;
}

void FileRepo::erase_item(int poz) {
    studs.erase((studs.begin()+poz));
}

void test_repo(){
    assert(to_nr("9.57")==9.57);
    assert(to_nr("0.78")==0.78);
    assert(to_nr("10")==10);
    assert(to_nr("156.847")==156.847);

    FileRepo fp{"test.txt"};
    assert(fp.get_all().size()==10);
    //066604;Guta;Liviu;4;8.76
    assert(fp.get_all()[0].get_cod()=="066604");
    assert(fp.get_all()[0].get_name()=="Guta");
    assert(fp.get_all()[0].get_sname()=="Liviu");
    assert(fp.get_all()[0].get_clas()=="4");
    assert(fp.get_all()[0].get_medie()==8.76);
}