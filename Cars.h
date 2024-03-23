#pragma once
#include <vector>
#include "Driver.h"
#include "Passenger.h"
using namespace std;

class BoardException {};
class NullException {};

class Cars {
protected:
	Driver* driver = nullptr;
	int maxPassengeres = 1;
	std::vector<Passenger*> passengers;

public:
	//double earnedMoney = 0;

	bool readyToDrive() {
		if (driver == nullptr)
			return false;
		if (passengers.size() < 1)
			return false;
		if (passengers.size() > maxPassengeres)
			return false;
		return true;
	}

	void BoardPassenger(Passenger* p)
	{
		if (p)
			passengers.push_back(p);
		else
			throw NullException();
	}

	void BoardDriver(Driver* d)
	{
		if (d)
			driver = d;
		else
			throw NullException();
	}

	int getMaxPassengers() {
		return maxPassengeres;
	}

	void info() {
		cout << "������." << endl;
	}

	~Cars()
	{
		if (driver)
			delete driver;
		for (auto p : passengers)
			delete p;
	}
};

class CarTaxi : public Cars
{
public:
	int childSafetySeat = 0;

	CarTaxi()
	{
		maxPassengeres = 3;
		cout << "����� �������." << endl;
	}

	void BoardTaxiDriver(Driver* d)
	{
		if (d)
			if ((*d).category == B) {
				driver = d;
				cout << "�������� ��� � �����." << endl;
			}
			else
				throw BoardException();
		else
			throw NullException();
	}

	void BoardPassenger(Passenger* p)
	{
		if (p) {
				passengers.push_back(p);
				if (p->getCategory() == Child) {
					childSafetySeat++;
				}
				cout << "�������� ��� � �����." << endl;
		}
		else
			throw NullException();
	}

	void info() {
		cout << "�����." << endl;
	}

	bool readyToDrive() {
		if (driver == nullptr)
			return false;
		if (passengers.size() < 1 || passengers.size() < maxPassengeres)
			return false;
		
		return true;
	}

	~CarTaxi() {};
};

class CarBus : public Cars
{
public:

	CarBus()
	{
		maxPassengeres = 29;
		cout << "������� ������." << endl;
	}

	void BoardBusDriver(Driver* d)
	{
		if (d)
			if ((*d).category == D) {
				driver = d;
				cout << "�������� ��� � �������." << endl;
			}
			else
				throw BoardException();
		else
			throw NullException();
	}

	void BoardPassenger(Passenger* p)
	{
		if (p) {
			passengers.push_back(p);
			cout << "�������� ��� � �������." << endl;
		}
		else
			throw NullException();
	}

	void info() {
		cout << "�������." << endl;
	}

	bool readyToDrive() {
		if (driver == nullptr)
			return false;
		if (passengers.size() < 1 || passengers.size() > maxPassengeres)
			return false;
		return true;
	}

	~CarBus() {};
};
