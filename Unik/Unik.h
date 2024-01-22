#ifndef COURSE_WORK1_UNIK_H
#define COURSE_WORK1_UNIK_H

#include "../Group/Group.h"

class Unik {
    vector<Group> groups;
public:
    Unik(const vector<Group> &m_groups);
    void printNames();
    void printall();
    void printGroup();
    void addGroup(Group a);
    void createGroup();
    void removeGroup();
    void refactorGroup();
    void removeStudent();
    static Student createStudent();
    void addStudent();
    void refactor();
    void getInformation();
    void find();
};


#endif //COURSE_WORK1_UNIK_H
