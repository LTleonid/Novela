#include <iostream>
#include <String>
#include <windows.h>  
int counter = 0;
using namespace std;

int main() {
	string choices[]{ "Я педоГОГ","asdasd" };
	for (string item : choices) {
		couneter++;
		cout << counter << ": " << item;
	}
	return 0;
}