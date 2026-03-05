#include "Animal.h"
#include "Zoo.h"
#include "User.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h> 
#include <cctype> 

using namespace std;

void Admin(Zoo& zoo);
void Guest(Zoo& zoo, const string& zooType);
void AnimalsArt(const string& animalType);
void PetsArt(const string& animalType);
void AquaArt(const string& animalType);

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
        case 2: zoo.listAnimals(); zoo.removeAnimal(); break;
        case 3: zoo.listAnimals(); zoo.editAnimal(); break;
        case 4: zoo.listAnimals(); break;
        }
        if (choice != 0)
        {
            zoo.AllStatusReduce();
            zoo.save();
        }
    } while (choice != 0);
}

void Guest(Zoo& zoo, const string& zooType)
{
    if (zoo.isEmpty())
    {
        cout << "В этом зоопарке пока нет животных! Возвращаемся в меню.\n";
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

        if (zooType == "zoo") {AnimalsArt(selectedAnimal->getType());}
        else if (zooType == "farm") { PetsArt(selectedAnimal->getType());}
        else if (zooType == "aqua") {AquaArt(selectedAnimal->getType());}

        selectedAnimal->Show();
        cout << "1. Покормить\n";
        cout << "2. Погладить\n";
        cout << "3. Информация\n";
        cout << "0. Назад\n";
        cout << "Выберите действие: ";
        cin >> action;

        switch (action)
        {
        case 1:
            selectedAnimal->feed();
            zoo.save();
            break;
        case 2:
            selectedAnimal->pet();
            zoo.save();
            break;
        case 3:
            selectedAnimal->Show();
            break;
        }
        if (action != 0)
        {
            zoo.AllStatusReduce();
            zoo.save();
        }
    } while (action != 0);
}

void AnimalsArt(const string& animalType)
{
    string type = animalType;
    for (char& c : type) 
    {
        c = tolower(c);
    }

    if (type == "медведь" || type == "bear") 
    {
        cout << R"(
             __         __
            /^ \.-"""-./ ^\
            \    -   -    /
             |   o   o   |
             \ .- '''-.  /
              '-\__Y__/-'
                 `---`)" << endl;
    }
    else if (type == "лиса" || type == "fox" || type == "лисица")
    {
        cout << R"( 
                 /|_/|
                / ^ ^(_o
               /    __.'
               /     \
              (_) (_) '._
                '.__     '. .-''-'.
                   ( '.   ('.____.''
                   _) )'_, )
                  (__/ (__/)" << endl;
    }
    else if (type == "динозавр" || type == "dino" || type == "дракон")
    {
        cout << R"(
                       __
                      / _)
             _.----._/ /
            /         /
         __/ (  | (  |
        /__.-'|_|--|_|)" << endl;
    }
    else if (type == "обезьяна" || type == "monkey" || type == "мартышка")
    {
        cout << R"(          
                    __,__
           .--.  .-"     "-.  .--.
          / .. \/  .-. .-.  \/ .. \
         | \   \  \ 0 | 0 /  /   / |
          \ '- ,\.-"`` ``"-./, -' /
            `'-' /_  ^ ^   _\ '-'`
                 \ \ `~` / /
                   '~---~')" << endl;
    }
    else if (type == "пингвин" || type == "pinguin" || type == "penguin") 
    {
        cout << R"(
         __
      -=(o '.
         '.-.\
         /|  \\
         '|  ||
          _\_):,_)" << endl;
    }
    else if (type == "бегемот" || type == "hippo" || type == "гиппопотам") 
    {
        cout << R"(
              c~~p ,---------.
         ,---'oo  )           \
        ( O O                  )/
         `=^='                 /
               \    ,     .   /
               \\  |-----'|  /
               ||__|    |_|__|)" << endl;
    }
    else 
    {
        cout << R"(                                                           
                ####     ####                
               ######   ######                
                ####     ####                                       
          ####                  ####       
          ####      #####       #####       
          ###     ##########     ####                       
                ##############                
               ################              
               ################                      
                 ############)" << endl;
    }
}

void PetsArt(const string& animalType)
{
    string type = animalType;
    for (char& c : type) {
        c = tolower(c);
    }

    if (type == "кот" || type == "кошка" || type == "cat") 
    {
        cout << R"(        
                   |\_|\
                   \` ..\
              __,.-" =__Y=
            ."        )
      _    /   ,    \/\_
     ((____|    )_-\ \_-`
      `-----'`-----` `--`)" << endl;
    }
    else if (type == "собака" || type == "пёс" || type == "dog")
    {
        cout << R"(     
            _=,_
         o_/6 / \
         \__ |  /
            '|--\
            /    '-.
            \ |_   _'-. /
             |/ \_(   |" 
            C/ ,--___/)" << endl;
    }
    else if (type == "корова" || type == "cow") 
    {
        cout << R"(
                  __n__n__
           .------`-\00/-'
          /  ##  ## (oo)
         / \## __   ./
            |//YY \|/
            |||   |||)" << endl;
    }
    else if (type == "свинья" || type == "pig" || type == "хрюшка") 
    {
        cout << R"(
            --.__.--
         ___\(0_0)/
      ~~/     (OO)
        \  __  /
         `='`='=)" << endl;
    }
    else if (type == "утка" || type == "duck" || type == "селезень") 
    {
        cout << R"(
              ,--.
             (  6 )-_,
        (\___ )=='-'
         \ .   ) )
          \_`-'_/)" << endl;
    }
    else if (type == "овца" || type == "sheep" || type == "баран")
    {
        cout << R"(
                        _,._
                    __.'   _)
                   <_,)'.-"a\
                     /' (    \
         _.-----..,-'   (`"--^
        //              |
       (|   `;      ,   |
         \   ;.----/  ,/
          ) // /   | |\ \
          \ \\`\   | |/ /
           \ \\ \  | |\/
            `" `"  `"`)" << endl;
    }
    else if (type == "лошадь" || type == "конь" || type == "horse") 
    {
        cout << R"(
                   ,--,
             _ ___/ /\|
         ,;'( )__, )  
        //  //   '--; 
        '   \     | ^
             ^    ^)" << endl;
    }
    else if (type == "коза" || type == "goat" || type == "козёл") 
    {
        cout << R"(
                     ,--._,--.
                   ,'  ,'   ,-`.
        (`-.__    /  ,'   /
         `.   `--'        \__,--'-.
           `--/       ,-.  ______/
             (o-.     ,o- /
              `. ;        \
               |:          \
              ,'`       ,   \
             (o o ,  --'     :
              \--','.        ;
               `;;  :       /
                ;'  ;  ,' ,'
                ,','  :  '
                \ \   :)" << endl;
    }
    else
    {
        cout << R"(
              ((...))
              ( . . )
              (  u  )
              (( Y )))" << endl;
    }
}

void AquaArt(const string& animalType)
{
    string type = animalType;
    for (char& c : type)
    {
        c = tolower(c);
    }

    if (type == "золотая рыбка" || type == "goldfish" || type == "рыбка")
    {
        cout << R"(
              /`·.¸
             /¸...¸`:·
         ¸.·´  ¸   `·.¸.·´)
        : © ):´;      ¸  {
         `·.¸ `·  ¸.·´\`·¸)
             `\\´´\¸.·)" << endl;
    }
    else if (type == "акула" || type == "shark") 
    {
        cout << R"(
         _________         .    .
        (..       \_    ,  |\  /|
         \       O  \  /|  \ \/ /
          \______    \/ |   \  / 
             vvvv\    \ |   /  |
             \^^^^  ==   \_/   |
              `\_   ===    \.  |
              / /\_   \ /      |
              |/   \_  \|      /
                     \________/)" << endl;
    }
    else if (type == "дельфин" || type == "dolphin")
    {
        cout << R"(
                     ,-._
                   _.-'  '--.
                 .'      _  -`\_
                / .----.`_.'----'
                ;/     `
               /_;
        
            ._      ._      ._      ._
        _.-._)`\_.-._)`\_.-._)`\_.-._)`\_.-._)" << endl;
    }
    else if (type == "морской конёк" || type == "seahorse" || type == "конёк") 
    {
        cout << R"(
              \/)/)
            _'  oo(_.-. 
          /'.     .---'
        /'-./    (
        )     ; __\
        \_.'\ : __|
             )  _/
            (  (,.
             '-.-')" << endl;
    }
    else if (type == "черепаха" || type == "turtle")
    {
        cout << R"(     
                    _,--.---.---.--.._ 
               _.-' `-`---.`---'-. _,`--.._
              /`--._ .     `.     `,`-.`-._\
             ||   \  `---.__`__..-`. ,'`-._/
        _  ,`\ `-._\      `.    `_.-`-._,``-.
     ,`   `-_ \/ `-.`-\    _\_.-'\__.-`-.`-._`.
    (_.o> ,--. `._/'--`,--`  \_.-'       \`-._ \
     `---'    `._ `---/__,----`           `-. `-\
               /_, ,  .-'                    `-._\
               \_, \/ (
                \_, \/_\
                 `._,\._\  
                    `_-_-_.-')" << endl;
    }
    else if (type == "осьминог" || type == "octopus" || type == "спрут")
    {
        cout << R"( 
              .'.'
              .'-'.
          .  (  o O)
           \_ `  _,   _
        -.__.'_) ( ,-'
             '-.O.'-..-..       
         ./\/\/ | \_.-._
                ;
             ._/)" << endl;
    }
    else if (type == "морж" || type == "walrus") 
    {
        cout << R"( 
             ___  
            /  .\ 
           /  =__|
          /    ||)" << endl;
    }
    else if (type == "медуза" || type == "jellyfish") 
    {
        cout << R"(   
              _______
         ,-~~~       ~~~-,
        (                 )
         \_-, , , , , ,-_/
            / / | | \ \
            | | | | | |
            | | | | | |
           / / /   \ \ \
           | | |   | | |)" << endl;
    }
    else
    {
        cout << R"(
            ><(((('>
            ><((('>
            ><((('>
            ><((('>)" << endl;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    system("chcp 1251 > nul");

    Zoo zoo("animals.txt");
    Zoo farm("farm.txt");
    Zoo aqua("aqua.txt");

    User admin("admin", "1234", "admin");

    int mode, zooChoice;
    string username, password;

    cout << "--------------------------------" << endl;
    cout << "     ВИРТУАЛЬНЫЙ ЗООПАРК       " << endl;
    cout << "--------------------------------" << endl;

    while (true)
    {
        cout << "\n1. Войти как администратор\n";
        cout << "2. Войти как гость\n";
        cout << "0. Выход\n";
        cout << "Выберите режим: ";
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
                cout << "Выберите зоопарк для управления:\n";
                cout << "1. Зоопарк (дикие животные)\n";
                cout << "2. Ферма (домашние животные)\n";
                cout << "3. Аквариум (водные животные)\n";
                cout << "Выбор: ";
                cin >> zooChoice;

                switch (zooChoice)
                {
                case 1: Admin(zoo); break;
                case 2: Admin(farm); break;
                case 3: Admin(aqua); break;
                default: cout << "Неверный выбор!\n";
                }
            }
            else
            {
                cout << "Неверный логин или пароль!\n";
            }
        }
        else if (mode == 2)
        {
            cout << "\nВыберите зоопарк для посещения:\n";
            cout << "1. Зоопарк (дикие животные)\n";
            cout << "2. Ферма (домашние животные)\n";
            cout << "3. Аквариум (водные животные)\n";
            cout << "Выбор: ";
            cin >> zooChoice;

            cout << "Вход как гость...\n";
            switch (zooChoice)
            {
            case 1: Guest(zoo, "zoo"); break;
            case 2: Guest(farm, "farm"); break;
            case 3: Guest(aqua, "aqua"); break;
            default: cout << "Неверный выбор!\n";
            }
        }
    }
    return 0;
}