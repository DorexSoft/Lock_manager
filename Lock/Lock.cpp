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

string xor_encrypt_decrypt(const std::string& text, const std::string& key) { // функция для шифрования/дешифрования
    string result = text;
    int key_len = key.length();
    for (size_t i = 0; i < text.length(); ++i) {
        result[i] = text[i] ^ key[i % key_len];
    }
    return result;
}

void remember_pass() { // функция для записи ключа
    string service;
    string login;
    string pass;
    string encryption_key = "-p@$$wOrd_f0r_XOR_Alg0r1thm!7y";

    cout << "Enter name service: ";
    cin >> service;
    cout << "Enter login: ";
    cin >> login;
    cout << "Enter pass: ";
    cin >> pass;

    ofstream file("keys.txt", ios_base::app);
    file << "Service: " << xor_encrypt_decrypt(service, encryption_key) << endl;
    file << "Login: " << xor_encrypt_decrypt(login, encryption_key) << endl;
    file << "Pass: " << xor_encrypt_decrypt(pass, encryption_key) << endl;
    file << "---" << endl;  
    file.close();
}

void view_keys() { // функция для просмотра ключей
    string encryption_key = "-p@$$wOrd_f0r_XOR_Alg0r1thm!7y";
    ifstream file("keys.txt");
    if (!file.is_open()) {
        cout << "no key file found. Error 1. Check the info" << endl;
        return;
    }
    string line;
    cout << "\n=== Saved Keys ===\n" << endl;
    while (getline(file, line)) {
        if (line.empty() || line == "---") {
            cout << endl;
            continue;
        }
        size_t separator = line.find(": ");
        if (separator != string::npos) {
            string label = line.substr(0, separator + 2);
            string encrypted = line.substr(separator + 2);
            string decrypted = xor_encrypt_decrypt(encrypted, encryption_key);
            cout << label << decrypted << endl;
        }
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

void delete_keys() { // функция для удаления ключей
    ofstream file("keys.txt", ios::trunc);
    file.close();
}

int main(){
    setlocale(LC_ALL, "RU");
    srand(time(0));
    int function;
    // текстовое меню
    cout << "Lock manager 0.3" << endl;
    cout << "Done by. https://github.com/DorexSoft/" << endl;
    cout << endl <<  "1. generate a password" << endl;
    cout << "2. remember password" << endl;
    cout << "3. view keys" << endl;
    cout << "4. info" << endl;
    cout << "5. delete Keys" << endl;
    cout << "6. exit" << endl << endl; 
    cout << "enter functions: ";
    cin >> function;

    if (function > 0 && function < 6) { // запуск цикла, для выбора функций
        while (function < 6 && function > 0) {
            if (function == 1)
                generate_pass();
            else if (function == 2)
                remember_pass();
            else if (function == 3)
                view_keys();
            else if (function == 4)
                info();
            else if (function == 5)
                delete_keys();
            cout << "enter functions: ";
            cin >> function;
        } if (function > 6 or function < 1)
            cout << "Error.";
        else
            cout << "Exit.";
    } else if (function == 6)
        cout << "Exit.";
    else
        cout << "Error.";

    return 0;
}