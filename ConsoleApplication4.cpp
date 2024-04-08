#include <iostream>
#include <String>
using namespace std;
int Hunger = 0;
int Rest = 0;
int Sleep = 0;
int Money = 0;
string Name;
string NameNPC[]{ "Алекс", "Командир Кирилл Витальевич"};
enum class Statistic { Hunger, Rest, Sleep, Money };
enum class Player_Action { Choice_1 = 1, Choice_2, Choice_3, Choice_4 };
void Setup() {
	Hunger = 100;
	Rest = 100;
	Sleep = 100;
	Money = 1000;
	getline(cin, Name);
}

void Screen_Choice(string Choice_1, string Choice_2, string Choice_3, string Choice_4){}
void Screen_Dialog(string Name_NPC, string dialog){}
void Screen_Cutscene(string Name_NPC, char Cutscene[]) {}

void Sleep_Event_Global(int Rest_Factor) {
	Sleep = 100;
	if (Rest_Factor > 20) {
		Rest = 100;
	}
	else if (Rest_Factor > 10) {
		Rest += 40;
	}
	else if (Rest_Factor > 5) {
		Rest += 20;
	}
	else {
		Rest += 10;
	}
	if (Rest > 100) {
		Rest = 100;
	}
}
void Sleep_Event_Radnom(int Rest_Factor) {
	Sleep += rand() % 20;

	if (Sleep > 100) Sleep = 100;
	if (Rest_Factor > 20) {
		Rest = 100;
	}
	else if (Rest_Factor > 10) {
		Rest += 40;
	}
	else if (Rest_Factor > 5) {
		Rest += 20;
	}
	else {
		Rest += 10;
	}
	if (Rest > 100) {
		Rest = 100;
	}
}
int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	Setup();

	return 0;
}