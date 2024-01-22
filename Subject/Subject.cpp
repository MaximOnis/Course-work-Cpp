#include "Subject.h"

using namespace std;

Subject::Subject(){}
Subject::Subject(const string &m_name, float a){
    name = m_name;
    mark = a;
}
string Subject::getName(){
    return name;
}
float Subject::getMark(){
    return mark;
}
void Subject::setMark(const float &markk){
    mark = markk;
}
void Subject::setName(const string &m_name){
    name = m_name;
}
string Subject::toString(){
    string res = name+": "+to_string(mark);
    res.erase(res.end()-5, res.end());
    return res;
}
Subject::~Subject(){}
