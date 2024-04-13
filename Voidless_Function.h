#pragma once

#include <iostream>
#include <String>
#include <windows.h>  


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


string NameNPC_Random[]{ "Алекс", "" };


enum class Food { Steak = 1, Bread, Chicken, Potato, Fries, Ice_Cream };
enum class Statistic { Saturation, Rest, Sleep, Money };
enum class Player_Action { Choice_1 = 1, Choice_2, Choice_3, Choice_4 };
enum class Rest_Action { Lying_on_the_couch = 1, Go_to_the_park, Walk_along_the_embankment, Walking_with_friends, Watching_movies, Watch_TikTok };

void Setup() {
	Saturation = 100;
	Rest = 100;
	Sleep_ = 100;
	Money = 1000;
	getline(cin, Name);
}


void Event_Random() {}


void Screen_Choice(string choices[], string Name_NPC = none, string Question) {
	int counter = 0;
	cout << Name_NPC << ": " << Question;
	cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*";
	cout << endl;
	cout << "Ваш Выбор: \n"
		for (string item : choices) {
			couneter++;
			cout << counter << ": " << item;
		}
	}
	cout << endl;
	cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*";
}

void Screen_Dialog(string Name_NPC, string dialog, ) {

} 


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
	switch (Food_Type)
	{
		(int)Food::Bread:
			Saturation += 20;
			break;
		(int)Food::Steak:
			Saturation += 50;
			break;
		(int)Food::Chicken:
			Saturation += 60;
			break;
		(int)Food::Fries:
			Saturation += 35;
			break;
		(int)Food::Ice_Cream:
			Saturation += 15;
			break;
		(int)Food::Potato:
			Saturation += 16;
			break;
	default:
		cout << "Ошибка в еде!" << Food_Type;
	}
	if (Saturation > 100) Saturation = 100;
}

void Rest_Event(int Rest_Type) {
	switch (Rest_Type)
	{
		(int)Rest_Action::Lying_on_the_couch:
			Rest += 10;
			break;
		(int)Rest_Action::Go_to_the_park:
			Rest += 20;
			break;
		(int)Rest_Action::Walk_along_the_embankment:
			Rest += 35;
			break;
		(int)Rest_Action::Walking_with_friends:
			Rest += 63;
			break;
		(int)Rest_Action::Watching_movies:
			Rest += 50;
			break;
		(int)Rest_Action::Watch_TikTok:
			Rest += 40;
			break;
		default:
			break;
	}
	if (Rest > 100) Rest = 100;

}
