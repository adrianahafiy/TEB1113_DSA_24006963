/*
ID: 24006963
Name: Nur Adrianahafiy binti Muhammad Yazid
Group: G1
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
    struct Student {
        int id;
        string name;
        string contact;
        string email;
    };

    Student stdArray[5];

    for (int i = 0; i < 5; i++){
        cout << "Student " << i+1 << endl;
        cout << "Input student id: ";
        cin >> stdArray[i].id;
        cout << "Input student name: ";
        cin >> stdArray[i].name;
        cout << "Input contact details: ";
        cin >> stdArray[i].contact;
        cout << "Input email: ";
        cin >> stdArray[i].email;
        cout << endl;
    }

    for (int i = 0; i < 5; i++){
        cout << "*********************************** \n";
        cout << "Student " << i+1 << endl;
        cout << "ID: " << stdArray[i].id << endl;
        cout << "Name: " << stdArray[i].name << endl;
        cout << "Contact: " << stdArray[i].contact << endl;
        cout << "Email: " << stdArray[i].email << endl;
    }

    return 0;
}
