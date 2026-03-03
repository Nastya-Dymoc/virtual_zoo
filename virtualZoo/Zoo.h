#pragma once
#include "Animal.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h> 

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
    void AllStatusReduce()
    {
        for (Animal& i: animals)
        {
            i.StatusReduce();
        }
    }
};

