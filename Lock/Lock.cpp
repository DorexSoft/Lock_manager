#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void generate_pass() { // функция для генерации пароля
    // { "0","1","2","3","4","5","6","7","8","9","!","#","$",";","%","^","@",":","&","?","*","(",")","<",">","{","}","[","]","=","+","/","a","b", 
    // "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N",
    // "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
    string elements = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*";
    int random_element;
    cout << "Password: ";
    for (int i = 0; i < 16; i++) {
        random_element = rand() % elements.length();
        cout << elements[random_element];
}
    cout << endl;
}
void remember_pass() { // функция для записи ключа
    string service;
    string login;
    string pass;

    cout << "Enter name service: ";
    cin >> service; 
    cout << "Enter login: ";
    cin >> login;  
    cout << "Enter pass: ";
    cin >> pass;

    ofstream file("keys.txt", ios_base::app);
    file << "Service: " << service << endl;
    file << "Login: " << login << endl;
    file << "Pass: " << pass << endl << endl;
    file.close();
}
void view_keys() { // функция для просмотра ключей
    ifstream file("keys.txt");
    string line;
    cout << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}
void info() { // функция для просмотра информации
    ifstream file("info.txt");
    string line;
    cout << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}
int main(){
    setlocale(LC_ALL, "RU");
    srand(time(0));
    int function;
    // текстовое меню
    cout << "Lock manager 0.2 " << endl;
    cout << "Done by. https://github.com/DorexSoft/" << endl;
    cout << endl <<  "1. generate a password" << endl;
    cout << "2. remember password" << endl;
    cout << "3. view keys" << endl;
    cout << "4. info" << endl;
    cout << "5. exit" << endl << endl; 
    cout << "enter functions: ";
    cin >> function;

    if (function > 0 && function < 5) { // запуск цикла, для выбора функций
        while (function < 5 && function > 0) {
            if (function == 1)
                generate_pass();
            else if (function == 2)
                remember_pass();
            else if (function == 3)
                view_keys();
            else if (function == 4)
                info();

            cout << "enter functions: ";
            cin >> function;
        } if (function > 5 or function < 1)
            cout << "Error.";
        else
            cout << "Exit.";
    } else if (function == 5)
        cout << "Exit.";
    else
        cout << "Error.";
}