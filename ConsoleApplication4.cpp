#include <iostream>
#include <String>
#include<windows.h>  

enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

// устанавливает цвет текста и подложки в консоли
void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}



#define screen_width 120
#define screen_height 30
using namespace std;


int Saturation = 0;
int Rest = 0;
int Sleep_ = 0;
int Money = 0;
string Name;    


string NameNPC_Random[]{ "Алекс", ""};


enum class Food { Steak = 1, Bread, Chicken, Potato, Fries, Ice_Cream };
enum class Statistic { Saturation, Rest, Sleep, Money };
enum class Player_Action { Choice_1 = 1, Choice_2, Choice_3, Choice_4 };
enum class Rest_Action { Lying_on_the_couch = 1, Go_to_the_park, Walk_along_the_embankment,Walking_with_friends, Watching_movies, Watch_TikTok }; 

void Setup() {
	Saturation = 100;
	Rest = 100;
	Sleep_ = 100;
	Money = 1000;
	getline(cin, Name);
}


void Event_Random(){}


void Screen_Choice(string Choice_1, string Choice_2, string Choice_3, string Choice_4, string Name_NPC, char NPC_Sprite[]) {
	int rows = sizeof NPC_Sprite / sizeof NPC_Sprite[0];
	int cols = sizeof  NPC_Sprite[0] / sizeof(int);
}
void Screen_Dialog(string Name_NPC, string dialog){
	
}
void Screen_Cutscene(string Name_NPC, char Cutscene[]) {}


void Sleep_Event_Global(int Rest_Factor) {
	Sleep_ = 100;
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
	Sleep_ += rand() % 20;

	if (Sleep_ > 100) Sleep_ = 100;
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

void Eat_Event(int Food_Type) {
	if (Food_Type == (int)Food::Bread) Saturation += 20;
	if (Food_Type == (int)Food::Steak) Saturation += 50;
	if (Food_Type == (int)Food::Chicken) Saturation += 60;
	if (Food_Type == (int)Food::Fries) Saturation += 35;
	if (Food_Type == (int)Food::Ice_Cream) Saturation += 15;
	if (Food_Type == (int)Food::Potato) Saturation += 16;
	if (Saturation > 100) Saturation = 100;
}

void Rest_Evemt(int Rest_Type) {
    if (Rest_Type == (int)Rest_Action::Lying_on_the_couch) Rest += 10;
	if (Rest_Type == (int)Rest_Action::Go_to_the_park) Rest += 20;
	if (Rest_Type == (int)Rest_Action::Walk_along_the_embankment) Rest += 35;
	if (Rest_Type == (int)Rest_Action::Walking_with_friends) Rest  +=630;
	if (Rest_Type == (int)Rest_Action::Watching_movies) Rest += 50;
	if (Rest_Type == (int)Rest_Action::Watch_TikTok) Rest += 40;
	if (Rest > 100) Rest = 100;	
	
}

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	Setup();
	SetColor(14, 0);
	cout << "qweqwe";
	return 0;
}