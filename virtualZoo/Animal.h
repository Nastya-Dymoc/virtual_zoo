#pragma once
#include <fstream>
#include <iostream>
#include <string>

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

