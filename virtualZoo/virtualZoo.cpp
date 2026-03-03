#include "Animal.h"
#include "Zoo.h"
#include "User.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h> 

using namespace std;

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
        if (choice != 0)
        {
            zoo.AllStatusReduce();
            zoo.save();
        }
    } while (choice != 0);

}
void Guest(Zoo& zoo)
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
        if (action != 0)
        {
            zoo.AllStatusReduce();
            zoo.save();
        }
    } while (action != 0);
}
enum Animals{bear,fox,dino,monkey,pinguin,hippo};
void AnimalsArt(int _type)
{
    switch (_type)
    {
        case bear:
        cout << R"(медведь
             __         __
            /^ \.-"""-./ ^\
            \    -   -    /
             |   o   o   |
             \ .- '''-.  /
              '-\__Y__/-'
                 `---`)" << endl; 
            break;
        case fox:
            cout<< R"( 
                 /|_/|
                / ^ ^(_o
               /    __.'
               /     \
              (_) (_) '._
                '.__     '. .-''-'.
                   ( '.   ('.____.''
                   _) )'_, )
                  (__/ (__/)" << endl;
            break;
        case dino:
            cout << R"(
                       __
                      / _)
             _.----._/ /
            /         /
         __/ (  | (  |
        /__.-'|_|--|_|)" << endl;
            break;
        case monkey:
            cout << R"(          
                    __,__
           .--.  .-"     "-.  .--.
          / .. \/  .-. .-.  \/ .. \
         | \   \  \ 0 | 0 /  /   / |
          \ '- ,\.-"`` ``"-./, -' /
            `'-' /_  ^ ^   _\ '-'`
                 \ \ `~` / /
                   '~---~')" << endl;
            break;
        case pinguin:
            cout << R"(
         __
      -=(o '.
         '.-.\
         /|  \\
         '|  ||
          _\_):,_)" << endl;
        case hippo:
            cout << R"(
              c~~p ,---------.
         ,---'oo  )           \
        ( O O                  )/
         `=^='                 /
               \    ,     .   /
               \\  |-----'|  /
               ||__|    |_|__|)"<<endl;
            break;
        default:
            cout<<R"(                                                           
                ####     ####                
               ######   ######                
                ####     ####                                       
          ####                  ####       
          ####      #####       #####       
          ###     ##########     ####                       
                ##############                
               ################              
               ################                      
                 ############)"<<endl;
        
            break;
    }
}
enum Pets { cat, dog, cow, pig, duck, sheep, horse, goat};
void PetsArt(int _type)
{
    switch (_type)
    {
    case cat: 
        cout << R"(        
                   |\_|\
                   \` ..\
              __,.-" =__Y=
            ."        )
      _    /   ,    \/\_
     ((____|    )_-\ \_-`
      `-----'`-----` `--`)" << endl;
        break;
    case dog:
        cout << R"(     
            _=,_
         o_/6 / \
         \__ |  /
            '|--\
            /    '-.
            \ |_   _'-. /
             |/ \_(   |" 
            C/ ,--___/)" << endl;
        break;
    case cow:
        cout << R"(
                  __n__n__
           .------`-\00/-'
          /  ##  ## (oo)
         / \## __   ./
            |//YY \|/
            |||   |||)" << endl;
        break;
    case pig:
        cout << R"(
            --.__.--
         ___\(0_0)/
      ~~/     (OO)
        \  __  /
         `='`='=)" << endl;
        break;
    case duck:
        cout << R"(
              ,--.
             (  6 )-_,
        (\___ )=='-'
         \ .   ) )
          \_`-'_/)" << endl;
         break;
    case sheep:
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
    case horse:
        cout << R"(
                   ,--,
             _ ___/ /\|
         ,;'( )__, )  
        //  //   '--; 
        '   \     | ^
             ^    ^)" << endl;
        break;
    case goat:
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
        break;

    default: 
        break;
    }
}
enum Aqua { goldFish, shark, dolphin, seaHorse, turtle, octopus, walrus, jellyfish};
void AquaArt(int _type)
{
    switch (_type)
    {
    case goldFish:
        cout << R"(
              /`·.¸
             /¸...¸`:·
         ¸.·´  ¸   `·.¸.·´)
        : © ):´;      ¸  {
         `·.¸ `·  ¸.·´\`·¸)
             `\\´´\¸.·)" << endl ;
        break;
    case shark:
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
        break;
    case dolphin:
        cout << R"(
                     ,-._
                   _.-'  '--.
                 .'      _  -`\_
                / .----.`_.'----'
                ;/     `
               /_;
        
            ._      ._      ._      ._
        _.-._)`\_.-._)`\_.-._)`\_.-._)`\_.-._)" << endl;
        break;
    case seaHorse:
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
          break;
    case turtle:
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
        break;
    case octopus:
        cout << R"( 
              .'.'
              .'-'.
          .  (  o O)
           \_ `  _,   _
        -.___'.) ( ,-'
             '-.O.'-..-..       
         ./\/\/ | \_.-._
                ;
             ._/)" << endl;
        break;
    case walrus:
        cout << R"( 
             ___  
            /  .\ 
           /  =__|
          /    ||)" << endl;
    case jellyfish:
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
        break;
    default:
        break;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    system("chcp 1251 > nul");
    locale rus(".1251");

    Zoo zoo("animals.txt");
    Zoo farm("farm.txt");
    Zoo aqua("aqua.txt");

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

//cout << "__         __" << endl;
//cout<<"/ \. - """-./  \" << endl;
//cout<<"\    -   -    /"<< endl;
//cout<<"| o   o |" << endl;
//cout<<"\  . - '''-.  /" << endl;
//cout<<"'-\__Y__/-'" << endl;
//cout<<"`---`" << endl;