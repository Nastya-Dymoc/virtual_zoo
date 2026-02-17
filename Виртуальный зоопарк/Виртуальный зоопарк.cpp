#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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

    void feed() 
    {
        satiety += 10;
        if (satiety > 100) satiety = 100;
        cout << "Вы покормили " << name << "!\n";
    }

    void pet()
    {
        happiness += 10;
        if (happiness > 100) happiness = 100;
        cout << "Вы погладили " << name << "!\n";
    }

    void saveToFile(ofstream& file)
    {
        file << id << endl << name << endl << satiety << endl << happiness << endl;
    }

    bool loadFromFile(ifstream& file)

    {
        
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
    Zoo(string fname) : filename(fname)
    {
        load();
    }
    void load() {}
    void addAnimal() {}
    void removeAnimal() {}
    void editAnimal() {}
    void listAnimals() {}
    
};

void Admin(Zoo& zoo)
{
    int choice;
    do
    {
        cout << "\n--- АДМИНИСТРАТОР ---\n";
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
    int id;
    cout << "Выберите ID животного: ";
    cin >> id;

    int action;
    do {
        cout << "\n--- ГОСТЬ ---\n";
        //cout << "Животное: \n";
        cout << "1. Покормить\n";
        cout << "2. Погладить\n";
        cout << "3. Информация\n";
        cout << "0. Назад\n";
        cout << "Выберите действие: ";
        cin >> action;
    } while (action != 0);
}

int main()
{
    setlocale(LC_ALL, "");
    Zoo zoo("animals.txt");
    int mode;
    cout << "----------------------- " << endl;
    cout << "  ВИРТУАЛЬНЫЙ ЗООПАРК    " << endl;
    cout << "----------------------- " << endl;

    while (true) 
    {
        cout << "1. Администратор\n2. Гость\n0. Выход\nВыберите режим: ";
        cin >> mode;

        if (mode == 0)
        {
            cout << "До свидания!\n";
            break;
        }
        else if (mode == 1)
        {
            //Admin();
            
        }
        else if (mode == 2) 
        {
            //Guest();
        }
    }
    return 0;
}
