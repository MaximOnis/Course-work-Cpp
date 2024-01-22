#ifndef COURSE_WORK1_SUBJECT_H
#define COURSE_WORK1_SUBJECT_H

#include <iostream>
#include <string>

using namespace std;

class Subject {
    float mark;
    string name;
public:
    Subject();
    Subject(const string &m_name, float a);
    string getName();
    float getMark();
    void setMark(const float &markk);
    void setName(const string &m_name);
    string toString();
    ~Subject();
};

#endif //COURSE_WORK1_SUBJECT_H
