#ifndef COURSE_WORK1_STUDENT_H
#define COURSE_WORK1_STUDENT_H

#include <vector>
#include "../Subject/Subject.h"

using namespace std;

class Student{
    vector<Subject> subjects;
    string name;
    string surname;
    string lastname;
    int index;
public:
    Student();
    Student(const string &m_name, const string &m_surname, const string &m_lastname, const vector<Subject> &m_subjects);
    string getName();
    string getSurname();
    string getLastname();
    void setName(const string &m_name);
    void setSurname(const string &m_surname);
    void setLastname(const string &m_lastname);
    void setIndex(int a);
    void setSubjects(const vector<Subject> &a);
    vector<Subject> getSubjects();
    ~Student();
    string toString();
};

#endif //COURSE_WORK1_STUDENT_H
