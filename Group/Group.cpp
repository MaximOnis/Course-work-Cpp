#include "Group.h"

Group::Group(){}
Group::Group(const vector<Student> &m_list, const string &m_name){
    list = m_list;
    name = m_name;
}
void Group::addStudent(const Student &a){
    list.push_back(a);
    setIndexes();
    toFile();
}
void Group::setIndexes(){
    for (int i=0; i<(int)list.size(); i++) {
        list.at(i).setIndex(i+1);
    }
}
string Group::toString(){
    string res = "----------------------------"+name+"-----------------------------\n";
    for (int i=0; i<(int)list.size(); i++) {
        res.append(list.at(i).toString());
    }
    return res;
}
string Group::getName() const{
    return name;
}
vector<Student> Group::getlist(){
    return list;
}
void Group::removeStudent(int num){
    list.erase(list.begin()+num);
    setIndexes();
    toFile();
}
void Group::toFile() {
    string nameOfFile = name + ".txt";
    ofstream file;
    file.open(nameOfFile);
    file << toString();
    file.close();
}
void Group::removeFile() {
    string nameOfFile = name + ".txt";
    std::remove(nameOfFile.c_str());
}
void Group::refactorStudent(){
    try {
        string response;
        int numOfStudent;
        cout << "Введіть номер студента:";
        cin >> response;
        numOfStudent = stoi(response);
        if (numOfStudent<1 || numOfStudent>(int)list.size()){
            cout << "Неправильно введено номер!" << endl;
            return;
        }else{
            cout << list.at(numOfStudent-1).toString();
            cout << "Введіть параметр який хочете змінити:";
            cin >> response;
            if (response == "ім'я" || response == "Ім'я"){
                cout << "Введіть новий варіант:";
                cin >> response;
                list.at(numOfStudent-1).setName(response);
                cout << "Змінено." << endl;
            }else if (response == "прізвище" || response == "Прізвище"){
                cout << "Введіть новий варіант:";
                cin >> response;
                list.at(numOfStudent-1).setSurname(response);
                cout << "Змінено.";
            }else if (response == "по-батькові" || response == "По-батькові"){
                cout << "Введіть новий варіант:";
                cin >> response;
                list.at(numOfStudent-1).setLastname(response);
                cout << "Змінено.";
            }else if (response == "оцінки" || response == "Оцінки"){
                vector<Subject> subjects = list.at(numOfStudent-1).getSubjects();
                for (int i = 0; i < (int)list.at(numOfStudent-1).getSubjects().size(); ++i) {
                    float mark;
                    do {
                        try {
                            cout << subjects.at(i).toString() << endl;
                            cout << "Оцінка за цей предмет(1 - 10):";
                            cin >> response;
                            mark = stof(response);
                            if (mark<1 || mark>10){
                                cout << "Неправильно введено!";
                            }else{
                                subjects.at(i).setMark(mark);
                                break;
                            }
                        } catch (const exception &e) {
                            cout << "Неправильно введено!" << endl;
                        }
                    }while(true);
                }
                list.at(numOfStudent-1).setSubjects(subjects);
                cout << "Змінено." << endl;
            }else if (response == "предмети" || response == "Предмети"){
                int numberOfSubjects;
                do {
                    try {
                        cout << "Скільки у нього буде предметів?(максимум 5):";
                        cin >> response;
                        numberOfSubjects = stoi(response);
                        if (numberOfSubjects<0 || numberOfSubjects>5){
                            cout << "Неправильно введено!" << endl;
                        }else{
                            vector<Subject> subjects;
                            for (int i = 0; i < numberOfSubjects; i++){
                                cout << "Назва предмету:";
                                cin >> response;
                                Subject subject;
                                subject.setName(response);
                                do {
                                    try {
                                        float mark;
                                        cout << "Оцінка за цей предмет(1 - 10):";
                                        cin >> response;
                                        mark = stof(response);
                                        if (mark < 1 || mark > 10) {
                                            cout << "Неправильно введено!" << endl;
                                        } else {
                                            subject.setMark(mark);
                                            break;
                                        }
                                    }catch (const exception &e) {
                                        cout << "Неправильно введено!" << endl;
                                    }
                                }while (true);
                                subjects.push_back(subject);
                            }
                            list.at(numOfStudent-1).setSubjects(subjects);
                            break;
                        }
                    }catch(const exception &e){
                        cout << "Неправильно введено!" << endl;
                    }
                }while(true);
            }
        }
        setIndexes();
        toFile();
    }catch(const exception &e){
        cout << "Неправильно введено" << endl;
    }
}
void Group::toInfo(){
    for (int i = 0; i < (int)list.size(); i++) {
        try {
            string pib;
            pib.append(list.at(i).getSurname());
            pib.append(" ");
            pib.append(list.at(i).getName());
            pib.append(" ");
            pib.append(list.at(i).getLastname());
            cout << "---------------------------------------------------------------------------------------------------------------------------\n";
            string res;
            if (i<9){
                cout << "|  " << i+1 <<"  |" << pib << setw(45-(pib.size()/2+1)) << "|";
            }else{
                cout << "|  " << i+1 <<" |" << pib << setw(45-(pib.size()/2+1)) << "|";
            }
            res = "";
            int len = 0;
            for (auto & subject : list.at(i).getSubjects()){
                res.append(subject.getName() + ";  ");
                len = len + 3;
            }
            cout << res << setw((40-((((int)(res.size())-len)/2)+len))) << "|";
            res = "";
            for (auto & subject : list.at(i).getSubjects()){
                res.append(to_string(subject.getMark()));
                res.erase(res.end()-5, res.end());
                res.append("; ");
            }
            cout << res << setw(31-res.size()) << "|" << endl;
        }catch(int a){
            cout << "Помилка при створенні відомості.";
        }
    }
}
void Group::toInfoF(ofstream& file){
    for (int i = 0; i < (int)list.size(); i++) {
        try {
            string pib;
            pib.append(list.at(i).getSurname());
            pib.append(" ");
            pib.append(list.at(i).getName());
            pib.append(" ");
            pib.append(list.at(i).getLastname());
            file << "---------------------------------------------------------------------------------------------------------------------------\n";
            string res;
            if (i<9){
                file << "|  " << i+1 <<"  |" << pib << setw(45-(pib.size()/2+1)) << "|";
            }else{
                file << "|  " << i+1 <<" |" << pib << setw(45-(pib.size()/2+1)) << "|";
            }
            res = "";
            int len = 0;
            for (auto & subject : list.at(i).getSubjects()){
                res.append(subject.getName() + ";  ");
                len = len + 3;
            }
            file << res << setw((40-((((int)(res.size())-len)/2)+len))) << "|";
            res = "";
            for (auto & subject : list.at(i).getSubjects()){
                res.append(to_string(subject.getMark()));
                res.erase(res.end()-5, res.end());
                res.append("; ");
            }
            file << res << setw(31-res.size()) << "|" << endl;
        }catch(int a){
            cout << "Помилка при створенні відомості.";
        }
    }
}
Group::~Group(){}