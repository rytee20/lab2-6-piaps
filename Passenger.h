#pragma once
#include <iostream>
using namespace std;

enum PassCategory {Adult,Child,Preferential};

class Passenger
{
protected:
	PassCategory category;

public:

	Passenger() {
		//cout << "Пассажир создан." << endl; 
	}

	void info() {
		cout << "Пассажир." << endl;
	}

	PassCategory getCategory() {
		return category;
	}
};

class PassengerAdult : public Passenger
{
public:
	PassengerAdult() {
		category = Adult;
		cout << "Пассажир-взрослый создан." << endl;
	}

	void info() {
		cout << "Пассажир-взрослый." << endl;
	}
};

class PassengerChild : public Passenger
{
public:
	PassengerChild() {
		category = Child;
		cout << "Пассажир-ребенок создан." << endl;
	}

	void info() {
		cout << "Пассажир-ребенок." << endl;
	}
};

class PassengerPreferential : public Passenger
{
public:
	PassengerPreferential() {
		category = Preferential;
		cout << "Пассажир-льготник создан." << endl;
	}

	void info() {
		cout << "Пассажир-льготник." << endl;
	}
};