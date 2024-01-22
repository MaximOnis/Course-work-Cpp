#ifndef COURSE_WORK1_GROUP_H
#define COURSE_WORK1_GROUP_H

#include "../Student/Student.h"
#include <iomanip>
#include <exception>
#include <fstream>

class Group{
    vector<Student> list;
    string name;
public:
    Group();
    Group(const vector<Student> &m_list, const string &m_name);
    void addStudent(const Student &a);
    void setIndexes();
    string toString();
    string getName() const;
    vector<Student> getlist();
    void removeStudent(int num);
    void toFile();
    void removeFile();
    void refactorStudent();
    void toInfo();
    void toInfoF(ofstream& file);
    ~Group();
};

#endif //COURSE_WORK1_GROUP_H
