#include <iostream>
#include <String>
#include <windows.h>
#include <vector>
using namespace std;

int Screen_Choice(vector<string>& choices, string Name_NPC = "", string Question = "") {
    int counter = 0;
    int user;
    cout << Name_NPC << ": " << Question << endl;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*" << endl;
    for (string& item : choices) {
        counter++;
        cout << counter << ": " << item << "\n";
    }
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*" << endl;
    cout << endl;
    cout << "Ваш Выбор: ";
    cin >> user;
    return user;
}

int main() {
    vector<string> arr = { "asd", "sdd", "sdd" };
    cout << Screen_Choice(arr, "string Name_NPC = none", "ТЫ чмо?");
    return 0;
}