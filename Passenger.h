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
		//cout << "�������� ������." << endl; 
	}

	void info() {
		cout << "��������." << endl;
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
		cout << "��������-�������� ������." << endl;
	}

	void info() {
		cout << "��������-��������." << endl;
	}
};

class PassengerChild : public Passenger
{
public:
	PassengerChild() {
		category = Child;
		cout << "��������-������� ������." << endl;
	}

	void info() {
		cout << "��������-�������." << endl;
	}
};

class PassengerPreferential : public Passenger
{
public:
	PassengerPreferential() {
		category = Preferential;
		cout << "��������-�������� ������." << endl;
	}

	void info() {
		cout << "��������-��������." << endl;
	}
};