#pragma once

#include <iostream>
#include <String>
#include <windows.h>  
#include <vector>

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

int rest_factor_multiplyier = 0;
int Saturation = 0;
int Rest = 0;
int Sleep_ = 0;
int Money = 0;
string Name = "";


string NameNPC_Random[]{ "Алекс", "" };


enum class Food { Steak = 1, Bread, Chicken, Potato, Fries, Ice_Cream };
enum class Statistic { Saturation, Rest, Sleep, Money };
enum class Player_Action { Choice_1 = 1, Choice_2, Choice_3, Choice_4 };
enum class Rest_Action { Lying_on_the_couch = 1, Go_to_the_park, Walk_along_the_embankment, Walking_with_friends, Watching_movies, Watch_TikTok, Watch_TV };

void Setup() {
	Saturation = 100;
	Rest = 100;
	Sleep_ = 100;
	Money = 1000;
	cout << "Ваше имя: ";getline(cin, Name);
	rest_factor_multiplyier = 100;
}

void Event_Random() {}

int Screen_Choice(vector<string> choices) {
	int user;
	bool flag = true;
	int counter = 1;
	cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*" << endl;
	for (int i = 0; i < choices.size(); i++) {
		cout << i + 1 << ": " << choices[i] << "\n";
		counter++;
	}
	cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*" << endl;
	cout << endl;
	while (flag) {
		cout << "Ваш Выбор: ";
		cin >> user;
		if ((user > 0) && (user < counter)) {
			break;
		}
	}
	return user;
}


void Screen_Dialog( string Name_NPC, string dialog, int color_message = 15,int color_name = 15, int background = 0) {
	
	SetColor(color_name,background);
	cout << Name_NPC;
	cout << " : ";
	SetColor(color_name, background);
	cout << dialog;
	cin.get();
} 


void Sleep_Event_Global(int Rest_Factor) {

	cout << "Вы уснули.";
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

void Eat_Event(Food Food) {
	
	switch (Food)
	{
		case Food::Bread:
			Saturation += 20;
			break;
		case Food::Steak:
			Saturation += 50;
			break;
		case Food::Chicken:
			Saturation += 60;
			break;
		case Food::Fries:
			Saturation += 35;
			break;
		case Food::Ice_Cream:
			Saturation += 15;
			break;
		case Food::Potato:
			Saturation += 16;
			break;
	default:
		cout << "Ошибка в еде!";
	}
	if (Saturation > 100) Saturation = 100;
}

void Rest_Event(Rest_Action action) {
	switch (action) {
	case Rest_Action::Lying_on_the_couch:
		Rest += 10;
		break;
	case Rest_Action::Go_to_the_park:
		Rest += 20;
		break;
	case Rest_Action::Walk_along_the_embankment:
		Rest += 35;
		break;
	case Rest_Action::Walking_with_friends:
		Rest += 63;
		break;
	case Rest_Action::Watching_movies:
		Rest += 50;
		break;
	case Rest_Action::Watch_TikTok:
		Rest += 40;
		break;
	case Rest_Action::Watch_TV:
		Rest += 40;
		break;
	default:
		break;
	}
	if (Rest > 100) Rest = 100;
}
void Money_Event(int Money_) {
	cout << "Вы получили: " << Money_ << " $";
	Money += Money_;
	cout << "Ваши Сбережения: " << Money;
}