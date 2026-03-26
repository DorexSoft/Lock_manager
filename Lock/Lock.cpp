#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void generate_pass() {
    short pass1 = 1000+rand()%9999;
    short pass2 = 1000+rand()%9999;
    short pass3 = 1000+rand()%9999;
    short pass4 = 1000+rand()%9999;
    cout << "Password: " << pass1<< pass2 << pass3 << pass4 << endl;
}
void remember_pass() {
    string name;
    string service;
    string login;
    string pass;

    cout << "Enter name keys: "; 
    cin >> name; 
    name = name + ".txt";
    cout << "Enter name service: ";
    cin >> service; 
    cout << "Enter login: ";
    cin >> login;  
    cout << "Enter pass: ";
    cin >> pass;

    ofstream file(name, ios_base::out);
    file << "Service: " << service << endl;
    file << "Login: " << login << endl;
    file << "Pass: " << pass << endl;
    file.close();
}
void view_keys() {
    string name_keys;
    cout << "Enter name keys: ";
    cin >> name_keys;
    name_keys = name_keys + ".txt";

    ifstream file(name_keys);
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

int main()
{
    setlocale(LC_ALL, "RU");
    int function;

    cout << "Lock manager 0.1 " << endl;
    cout << "Done by. https://github.com/DorexSoft/" << endl;
    cout << endl <<  "1. generate a password" << endl;
    cout << "2. remember password" << endl;
    cout << "3. view keys" << endl;
    cout << "4. exit" << endl; 
    cout << "enter functions: ";
    cin >> function;

    while (function < 4) {
        if (function == 1)
            generate_pass();
        else if (function == 2)
            remember_pass();

        else if (function == 3)
            view_keys();

        cout << "enter functions: ";
        cin >> function;
    }
}