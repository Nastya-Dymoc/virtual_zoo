#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h> 

using namespace std;

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

