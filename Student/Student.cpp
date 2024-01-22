#include "Student.h"

Student::Student(){}
Student::Student(const string &m_name, const string &m_surname, const string &m_lastname, const vector<Subject> &m_subjects){
    name = m_name;
    surname = m_surname;
    lastname = m_lastname;
    subjects = m_subjects;
}
string Student::getName(){
    return name;
}
string Student::getSurname(){
    return surname;
}
string Student::getLastname(){
    return lastname;
}
void Student::setName(const string &m_name){
    name = m_name;
}
void Student::setSurname(const string &m_surname){
    surname = m_surname;
}
void Student::setLastname(const string &m_lastname) {
    lastname = m_lastname;
}
void Student::setIndex(int a){
    index = a;
}
void Student::setSubjects(const vector<Subject> &a){
    subjects = a;
}
vector<Subject> Student::getSubjects(){
    return subjects;
}
Student::~Student(){}
string Student::toString(){
    string res;
    for (auto & subject : subjects){
        res = res + " " + subject.toString() + ";";
    }
    return to_string(index)+". "+surname+" "+name+" "+lastname+"(Предмети:"+res+");\n";
}