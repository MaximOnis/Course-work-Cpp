#include "Unik.h"

Unik::Unik(const vector<Group> &m_groups) {
    groups = m_groups;
}
void Unik::printNames(){
    cout << "Групи:";
    for (const auto & group : groups){
        cout << group.getName() << " ";
    }
    cout << ";\n";
}
void Unik::printall() {
    for (auto &group: groups) {
        cout << group.toString() << endl;
    }
}
void Unik::printGroup(){
    string nameOfGroup;
    cout << "Яку групу вивести?:";
    cin >> nameOfGroup;
    for (auto &group: groups) {
        if (group.getName() == nameOfGroup){
            cout << group.toString() << endl;
        }
    }
}
void Unik::addGroup(Group a) {
    a.setIndexes();
    a.toFile();
    groups.push_back(a);
}
void Unik::createGroup(){
    Group tempGroup;
    cout << "Введіть назву групи:";
    string nameOfGroup;
    cin >> nameOfGroup;
    do {
        cout << "Скільки студентів у групі буде?(1-10):";
        string input;
        cin >> input;
        try {
            int numberOfStudents = stoi(input);
            if (numberOfStudents < 1 || numberOfStudents > 10) {
                cout << "Неправильно введено!" << endl;
            } else {
                vector<Student> students;
                for (int i = 0; i < numberOfStudents; i++) {
                    Student student = createStudent();
                    students.push_back(student);
                }
                Group group(students, nameOfGroup);
                addGroup(group);
                break;
            }
        } catch (const exception& e) {
            cout << "Неправильно введено!" << endl;
        }
    }while(true);
}
void Unik::removeGroup(){
    cout << "Введіть назву групи:";
    string response;
    cin >> response;
    int num;
    bool isHere=false;
    for(int i = 0; i < (int)groups.size(); i++){
        if(response == groups.at(i).getName()){
            num = i;
            isHere=true;
            break;
        }
    }
    if(!isHere){
        cout << "Групу не знайдено!" << endl;
    } else{
        do {
            cout << "Ви впевнені що хочете видалити групу?:";
            cin >> response;
            if (response == "так" || response == "Так"){
                groups.at(num).removeFile();
                groups.erase(groups.begin()+num);
                cout << "Видалено." << endl;
            }else if(response == "ні" || response == "Ні"){
                return;
            }else{
                cout << "Введіть коректну відповідь!" << endl;
            }
        }while(response != "так" && response != "Так" && response != "ні" && response != "Ні");
    }
}
void Unik::refactorGroup(){
    cout << "Введіть назву групи:";
    string response;
    cin >> response;
    int num;
    bool isHere = false;
    for (int i = 0; i < (int)groups.size(); i++) {
        if (response == groups.at(i).getName()) {
            num = i;
            isHere = true;
            break;
        }
    }
    if (!isHere) {
        cout << "Групу не знайдено!" << endl;
    }else{
        groups.at(num).refactorStudent();
    }
}
void Unik::removeStudent() {
    cout << "Введіть назву групи:";
    string res;
    cin >> res;
    int num;
    bool isHere = false;
    for (int i = 0; i < (int)groups.size(); i++) {
        if (res == groups.at(i).getName()) {
            num = i;
            isHere = true;
            break;
        }
    }
    if (!isHere) {
        cout << "Групу не знайдено!" << endl;
    } else {
        try {
            cout << "Введіть номер студента:";
            int index;
            cin >> res;
            index = stoi(res);
            if (index <= 0 || index > (int)groups.at(num).getlist().size()) {
                cout << "Неправильно введено номер студента!!!" << endl;
                return;
            } else {
                cout << groups.at(num).getlist().at(index-1).toString();
                do {
                    cout << "Ви впевнені що хочете видалити студента зі списку?:";
                    cin >> res;
                    if (res == "так" || res == "Так") {
                        groups.at(num).removeStudent(index-1);
                        cout << "Видалено." << endl;
                    } else if (res == "ні" || res == "Ні") {
                        return;
                    } else {
                        cout << "Введіть коректну відповідь!" << endl;
                    }
                } while (res != "так" && res != "Так" && res != "ні" && res != "Ні");
            }
        } catch (const exception &e) {
            cout << "Неправильно введено!" << endl;
        }
    }
}
Student Unik::createStudent(){
    Student temp;
    cout << "-------------Введіть дані-------------\nІм'я:";
    string res;
    cin >> res;
    temp.setName(res);
    cout << "Прізвище:";
    cin >> res;
    temp.setSurname(res);
    cout << "По-батькові:";
    cin >> res;
    temp.setLastname(res);
    do {
        try {
            cout << "Скільки у нього буде предметів?(максимум 5):";
            cin >> res;
            int numberOfSub = stoi(res);
            if (numberOfSub<0 || numberOfSub>5){
                cout << "Неправильно введено!" << endl;
            }else{
                vector<Subject> subjects;
                for (int i = 0; i < numberOfSub; i++){
                    cout << "Назва предмету:";
                    cin >> res;
                    Subject subject;
                    subject.setName(res);
                    string input;
                    do {
                        try {
                            cout << "Оцінка за цей предмет(1 - 10):";
                            cin >> input;
                            float mark = stof(input);
                            if (mark<1 || mark>10){
                                cout << "Неправильно введено!" << endl;
                            }else{
                                subject.setMark(mark);
                                break;
                            }
                        } catch (const exception &e) {
                            cout << "Неправильно введено!" << endl;
                        }
                    }while(true);
                    subjects.push_back(subject);
                }
                temp.setSubjects(subjects);
                break;
            }
        }catch(const exception &e){
            cout << "Неправильно введено!" << endl;
        }
    }while(true);
    return temp;
}
void Unik::addStudent(){
    cout << "Введіть назву групи:";
    string res;
    cin >> res;
    int num;
    bool isHere = false;
    for (int i = 0; i < (int)groups.size(); i++) {
        if (res == groups.at(i).getName()) {
            num = i;
            isHere = true;
            break;
        }
    }
    if (!isHere) {
        cout << "Групу не знайдено!" << endl;
    }else{
        Student temp = createStudent();
        groups.at(num).addStudent(temp);
    }
}
void Unik::refactor(){
    string res;
    cout << "-> add - додати студента" << endl;
    cout << "-> remove - видалити студента" << endl;
    cout << "-> refactor - змінити дані студента" << endl;
    cout << ">:";
    cin >> res;
    if (res == "add"){
        addStudent();
    }else if(res == "remove"){
        removeStudent();
    }else if(res == "refactor"){
        refactorGroup();
    }
}
void Unik::getInformation(){
    string info = "---------------------------------------------------------------------------------------------------------------------------\n";
    info.append("|  №  |                   ПІБ                      |                Предмети               |       Оцінки(відповідно)     |\n");
    cout << info;
    for (auto & group : groups){
        group.toInfo();
    }
    cout << "---------------------------------------------------------------------------------------------------------------------------\n";
    string res;
    do {
        cout << "Записати у файл відомість?:";
        cin >> res;
        if (res == "так" || res == "Так"){
            ofstream file;
            file.open("Відомість.txt", ios_base::trunc);//очищення файлу
            file.close();
            file.open("Відомість.txt", ios_base::app);
            if (!file.is_open()){
                cout << "bad" << endl;
            }
            file << "---------------------------------------------------------------------------------------------------------------------------\n";
            file << "|  №  |                   ПІБ                      |                Предмети               |       Оцінки(відповідно)     |\n";
            for (auto & group : groups){
                group.toInfoF(file);
            }
            file << "---------------------------------------------------------------------------------------------------------------------------\n";
            file.close();
            break;
        }else if(res == "ні" || res == "Ні"){
            break;
        }else{
            cout << "Введіть так або ні!" << endl;
        }
    }while(true);
}
void Unik::find(){
    cout << "Введіть відомі дані(0 - якщо невідомо)" << endl;
    string name;
    string surname;
    string lastname;
    cout << "Ім'я:";
    cin >> name;
    cout << "Прізвище:";
    cin >> surname;
    cout << "По-батькові:";
    cin >> lastname;
    if (name != "0" && surname != "0" && lastname != "0"){
        for (auto & group : groups){
            for (int j = 0; j < (int)group.getlist().size(); j++) {
                if(group.getlist().at(j).getLastname()==lastname && group.getlist().at(j).getName()==name && group.getlist().at(j).getSurname()==surname){
                    cout << group.getName()<< ": " << group.getlist().at(j).toString();
                }
            }
        }

    }else if(name != "0" && surname != "0" && lastname == "0"){
        for (auto & group : groups){
            for (int j = 0; j < (int)group.getlist().size(); j++) {
                if(group.getlist().at(j).getName()==name && group.getlist().at(j).getSurname()==surname){
                    cout << group.getName()<< ": " << group.getlist().at(j).toString();
                }
            }
        }
    }else if(name != "0" && surname == "0" && lastname != "0"){
        for (auto & group : groups){
            for (int j = 0; j < (int)group.getlist().size(); j++) {
                if(group.getlist().at(j).getLastname()==lastname && group.getlist().at(j).getName()==name){
                    cout << group.getName()<< ": " << group.getlist().at(j).toString();
                }
            }
        }
    }else if(name == "0" && surname != "0" && lastname != "0"){
        for (auto & group : groups){
            for (int j = 0; j < (int)group.getlist().size(); j++) {
                if(group.getlist().at(j).getLastname()==lastname && group.getlist().at(j).getSurname()==surname){
                    cout << group.getName()<< ": " << group.getlist().at(j).toString();
                }
            }
        }
    }else if(name != "0" && surname == "0" && lastname == "0"){
        for (auto & group : groups){
            for (int j = 0; j < (int)group.getlist().size(); j++) {
                if(group.getlist().at(j).getName()==name){
                    cout << group.getName()<< ": " << group.getlist().at(j).toString();
                }
            }
        }
    }else if(name == "0" && surname != "0" && lastname == "0"){
        for (auto & group : groups){
            for (int j = 0; j < (int)group.getlist().size(); j++) {
                if(group.getlist().at(j).getSurname()==surname){
                    cout << group.getName()<< ": " << group.getlist().at(j).toString();
                }
            }
        }
    }else if(name == "0" && surname == "0" && lastname != "0"){
        for (auto & group : groups){
            for (int j = 0; j < (int)group.getlist().size(); j++) {
                if(group.getlist().at(j).getLastname()==lastname){
                    cout << group.getName()<< ": " << group.getlist().at(j).toString();
                }
            }
        }
    }else if(name == "0" && surname == "0" && lastname == "0"){
        return;
    }
}