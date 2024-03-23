#pragma once
#include <iostream>
using namespace std;

enum Category {D, B};

class Driver {
public:
	Category category;

	Driver() {};

	void info() {
		cout << "��������." << endl;
	}
};

class BusDriver : public Driver {
public:
	BusDriver() {
		category = D;
		cout << "������ ����� �������� ��������." << endl;
	}

	void info() {
		cout << "�������� ��������." << endl;
	}
};

class TaxiDriver : public Driver {
public:
	TaxiDriver() {
		category = B;
		cout << "������ ����� �������� �����." << endl;
	}

	void info() {
		cout << "�������� �����." << endl;
	}
};
