#include "Unik/Unik.h"
void commands(){
    cout << "================================Команди===================================" << endl;
    cout << "--> Створити групу - createGroup " << endl;
    cout << "--> Видалити групу - removeGroup " << endl;
    cout << "--> Переглянути всі групи - printAll " << endl;
    cout << "--> Переглянути певну групу - print " << endl;
    cout << "--> Вивести назви груп - groups " << endl;
    cout << "--> Сформувати відомість - info " << endl;
    cout << "--> Редагувати групу - refactor " << endl;
    cout << "--> Пошук студента по всіх групах - find " << endl;
    cout << "--> Вивести список команд - commands " << endl;
    cout << "--> Очистити консоль - clear" << endl;
    cout << "--> Вийти - exit <--" << endl;
    cout << "==========================================================================" << endl;
}
void menu(Unik unik){
    commands();
    do {
        string response;
        cout << "==========================================================================" << endl;
        cout << "--->:";
        cin >> response;
        cout << "==========================================================================" << endl;
        if (response == "createGroup"){
            unik.createGroup();
        }else if(response == "removeGroup"){
            unik.removeGroup();
        }else if(response == "printAll"){
            unik.printall();
        }else if(response == "print"){
            unik.printGroup();
        }else if(response == "refactor"){
            unik.refactor();
        }else if(response == "find"){
            unik.find();
        }else if(response == "info"){
            unik.getInformation();
        }else if(response == "exit"){
            cout << "Бувай!!!!" << endl;
            return;
        }else if(response == "commands"){
            commands();
        }else if(response == "groups"){
            unik.printNames();
        }else if(response == "clear"){
            system("clear");
        }else{
            cout << "Невідома команда!" << endl;
        }
    }while(true);
}
int main() {
    vector<Group> groups;
    Unik unik(groups);
    vector<Subject> sub;
    sub.emplace_back("АСД", 2.3);
    sub.emplace_back("ОП", 2.5);
    sub.emplace_back("МАТАН", 7.8);
    vector<Student> group;
    group.emplace_back("Іван", "Барабаш", "Миколайович", sub);
    group.emplace_back("Максим", "Бондаренко", "Іванович", sub);
    group.emplace_back("Назар", "Вознюк", "Олександрович", sub);
    sub.emplace_back("АНГЛ", 2.53);
    group.emplace_back("Назар", "Бульботко", "Анатолійович", sub);
    group.emplace_back("Максим", "Грицюк", "Ігорович", sub);
    group.emplace_back("Ярослав", "Бізюк", "Тарасович", sub);
    group.emplace_back("Микита", "Бугаєнко", "Вікторович", sub);
    sub.emplace_back("ЛАТАГ", 5.3);
    group.emplace_back("Олексій", "Горбатько", "Миколайович", sub);
    group.emplace_back("Микита", "Данечкін", "Павлович", sub);
    group.emplace_back("Павло", "Іщук", "Ярославович", sub);
    Group temp1(group, "ТВ-21");
    unik.addGroup(temp1);
    group.clear();
    sub.clear();
    sub.emplace_back("ОКСМ", 6.7);
    sub.emplace_back("ЛАТАГ", 3.8);
    group.emplace_back("Микита", "Карпенко", "Віталійович", sub);
    group.emplace_back("Віталік", "Кошинський", "Іванович", sub);
    group.emplace_back("Максим", "Оніщук", "Іванович", sub);
    sub.emplace_back("АНГЛ", 5.53);
    group.emplace_back("Володимир", "Кривой", "Ігорович", sub);
    group.emplace_back("Констянтин", "Лапа", "Володимирович", sub);
    group.emplace_back("Руслан", "Макаринський", "Констянтинович", sub);
    sub.emplace_back("ІНТ", 10);
    group.emplace_back("Олександр", "Михайлович", "Анатолійович", sub);
    group.emplace_back("Вероніка", "Омельченко", "Олександрівна", sub);
    group.emplace_back("Богдан", "Переход", "Русланович", sub);
    Group temp2(group, "ТВ-22");
    unik.addGroup(temp2);
    group.clear();
    sub.clear();
    sub.emplace_back("КПІ", 4.456);
    group.emplace_back("Дмитро", "Стариченко", "Анатолійович", sub);
    group.emplace_back("Михайло", "Полупан", "Дмитрович", sub);
    group.emplace_back("Олександр", "Семенчук", "Ігорович", sub);
    sub.emplace_back("АНГЛ", 5.53);
    group.emplace_back("Артем", "Сівоздрав", "Володимирович", sub);
    group.emplace_back("Дмитро", "Сущенко", "Михайлович", sub);
    sub.emplace_back("ЗОЖ", 7.3);
    group.emplace_back("Владислав", "Турніцький", "Анатолійович", sub);
    group.emplace_back("Ярослав", "Федорчук", "Максимович", sub);
    group.emplace_back("Дмитро", "Чеповський", "Олександрович", sub);
    Group temp3(group, "ТВ-23");
    unik.addGroup(temp3);
    menu(unik);
    return 0;
}