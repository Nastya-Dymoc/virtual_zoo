#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>  

using namespace std;

class Animal
{
private:
    int id;
    string name;
    string type;
    int satiety;
    int happiness;

public:
    Animal() : id(0), name("Лев"), type("Лев"), satiety(50), happiness(50) {}

    Animal(int id, string name, string type) : id(id), name(name), type(type), satiety(50), happiness(50) {}

    int getId() { return id; }
    string getName() { return name; }
    string getType() { return type; }
    int getSatiety() { return satiety; }
    int getHappiness() { return happiness; }

    void setName(string n) { name = n; }
    void setType(string t) { type = t; }
    void setSatiety(int s)
    {
        if (s < 0) satiety = 0;
        else if (s > 100) satiety = 100;
        else satiety = s;
    }
    void setHappiness(int h)
    {
        if (h < 0) happiness = 0;
        else if (h > 100) happiness = 100;
        else happiness = h;
    }

    void feed() 
    {
        setSatiety(satiety + 10);
        cout << "Вы покормили " << name << "!\n";
    }
    void pet()
    {
        setHappiness(happiness + 10);
        cout << "Вы погладили " << name << "!\n";
    }
    void saveToFile(ofstream& file)
    {
        file << id << endl << name << endl << type << endl << satiety << endl << happiness << endl;
    }
    bool loadFromFile(ifstream& file)
    {
        file >> id;
        file.ignore();
        getline(file, name);
        getline(file, type);
        file >> satiety >> happiness;
        return file.good();
    }

    void Show() 
    {
        cout << "ID: " << id;
        cout << ", Имя: " << name;
        cout << ", Вид: " << type;
        cout << ", Сытость: " << satiety;
        cout << ", Счастье: " << happiness << endl;
    }
};

class Zoo
{
private:
    vector<Animal> animals;
    string filename;

public:
    bool isEmpty()
    {
        return animals.empty();
    }
    Zoo(string fname) : filename(fname)
    {
        load();
    }
    void load()
    {
        ifstream file(filename);
        if (!file.is_open()) return;
         file.imbue(locale(".1251"));

        animals.clear();
        int id, satiety, happiness;
        string name, type;

        while (file >> id)
        {
            file.ignore();
            getline(file, name);
            getline(file, type);
            file >> satiety >> happiness;

            Animal a(id, name, type);
            a.setSatiety(satiety);
            a.setHappiness(happiness);
            animals.push_back(a);
        }
        file.close();
    }

    void save()
    {
        ofstream file(filename);
        if (!file.is_open()) return;
        file.imbue(locale(".1251"));

        for (Animal& a : animals)
        {
            a.saveToFile(file);
        }
        file.close();
    }
    void addAnimal()
    {
        string name, type;
        cout << "Введите имя животного: ";
        cin >> name;
        cout << "Введите вид животного: ";
        cin >> type;

        int newId = animals.size() + 1;
        Animal a(newId, name, type);
        animals.push_back(a);

        cout << "Животное добавлено!\n";
        save();
    }
   
    void removeAnimal()
    {
        int id;
        cout << "Введите ID животного для удаления: ";
        cin >> id;

        for (int i = 0; i < animals.size(); i++)
        {
            if (animals[i].getId() == id)
            {
                animals.erase(animals.begin() + i);
                cout << "Животное удалено!\n";
                save();
                return;
            }
        }
        cout << "Животное с таким ID не найдено!\n";
    }
    void editAnimal()
    {
        int id;
        cout << "Введите ID животного для редактирования: ";
        cin >> id;

        for (Animal& a : animals)
        {
            if (a.getId() == id)
            {
                string newName, newType;
                cout << "Текущее имя: " << a.getName() << "\nНовое имя: ";
                cin >> newName;
                cout << "Текущий вид: " << a.getType() << "\nНовый вид: ";
                cin >> newType;

                a.setName(newName);
                a.setType(newType);
                cout << "Данные обновлены!\n";
                save();
                return;
            }
        }
        cout << "Животное не найдено!\n";
    }
    void listAnimals()
    {
        if (animals.empty())
        {
            cout << "В зоопарке нет животных!\n";
            return;
        }

        cout << "\n| СПИСОК ЖИВОТНЫХ |\n";
        for (Animal& a : animals)
        {
            a.Show();
        }
    }
    Animal* findAnimal(int id)
    {
        for (Animal& a : animals)
        {
            if (a.getId() == id)
                return &a;
        }
        return nullptr;
    }
};

void Admin(Zoo& zoo)
{
    int choice;
    do
    {
        cout << "\n| АДМИНИСТРАТОР |\n";
        cout << "1. Добавить животное\n";
        cout << "2. Удалить животное\n";
        cout << "3. Редактировать животное\n";
        cout << "4. Список животных\n";
        cout << "0. Назад\n";
        cout << "Выберите действие: ";

        cin >> choice;

            switch (choice)
            {
            case 1: zoo.addAnimal(); break;
            case 2: zoo.removeAnimal(); break;
            case 3: zoo.editAnimal(); break;
            case 4: zoo.listAnimals(); break;
            }
    } while (choice != 0);
    
}

void Guest(Zoo & zoo)
{ 
    if (zoo.isEmpty())
    {
        cout << "В зоопарке пока нет животных! Возвращаемся в меню.\n";
        return;
    }

     zoo.listAnimals(); 
    
     int id;
     cout << "Выберите ID животного: ";
     cin >> id;
    
     Animal* selectedAnimal = zoo.findAnimal(id);
     if (selectedAnimal == nullptr)
     {
         cout << "Животное не найдено!\n";
         return;
     }
    
     int action;
     do {
         cout << "\n| ГОСТЬ |\n";
         selectedAnimal->Show(); 
         cout << "1. Покормить\n";
         cout << "2. Погладить\n";
         cout << "3. Информация\n";
         cout << "0. Назад\n";
         cout << "Выберите действие: ";
         cin >> action;
    
         switch (action)
         {
         case 1: selectedAnimal->feed();
             zoo.save(); 
         break;
         case 2: selectedAnimal->pet();
             zoo.save(); 
         break;
         case 3: selectedAnimal->Show(); 
         break;
         }
     } while (action != 0);
}
class User
{
private:
    string username;
    string password;
    string role; 

public:
    User() : username(""), password(""), role("guest") {}

    User(string u, string p, string r) : username(u), password(p), role(r) {}

    string getUsername() { return username; }
    string getRole() { return role; }

    bool checkPassword(string p) { return password == p; }

    void saveToFile(ofstream& file)
    {
        file << username << endl << password << endl << role << endl;
    }

    bool loadFromFile(ifstream& file)
    {
        file >> username >> password >> role;
        return file.good();
    }

    void Show()
    {
        cout << "Имя: " << username << ", Роль: " << role << endl;
    }
};
int main()
{
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251); 
    setlocale(LC_ALL, "Russian");
    system("chcp 1251 > nul");
    locale rus(".1251");

    Zoo zoo("animals.txt");

    User admin("admin", "1234", "admin");

    int mode;
    string username, password;

    cout << "----------------------- " << endl;
    cout << "  ВИРТУАЛЬНЫЙ ЗООПАРК    " << endl;
    cout << "----------------------- " << endl;
    while (true)
    {
        cout << "\n1. Войти как администратор\n2. Войти как гость\n0. Выход\nВыберите режим: ";
        cin >> mode;

        if (mode == 0)
        {
            cout << "До свидания!\n";
            break;
        }
        else if (mode == 1)
        {
            cout << "Логин: ";
            cin >> username;
            cout << "Пароль: ";
            cin >> password;

            if (username == admin.getUsername() && admin.checkPassword(password))
            {
                cout << "Добро пожаловать, администратор!\n";
                Admin(zoo);
            }
            else
            {
                cout << "Неверный логин или пароль!\n";
            }
        }
        else if (mode == 2)
        {
            cout << "Вход как гость...\n";
            Guest(zoo);
        }
    }
    return 0;
}