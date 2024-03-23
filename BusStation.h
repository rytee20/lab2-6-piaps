#pragma once
#include <vector>
#include "Cars.h"
//#include "AbstractFactory.h"
//#include "CarsAndPeople.h"
using namespace std;

class BusStation {
public:

	//float earnings = 0;
	vector<Cars*> cars;
	vector<Driver*> drivers;
	vector<PassengerAdult*> passengersAdult;
	vector<PassengerChild*> passengersChild;
	vector<PassengerPreferential*> passengersPreferential;


	void info() {
		int i;
		for (i = 0; i < cars.size(); ++i) cars[i]->info();
		for (i = 0; i < drivers.size(); ++i) drivers[i]->info();
		for (i = 0; i < passengersAdult.size(); ++i) passengersAdult[i]->info();
		for (i = 0; i < passengersChild.size(); ++i) passengersChild[i]->info();
		for (i = 0; i < passengersPreferential.size(); ++i) passengersPreferential[i]->info();
	}

	BusStation() {}


	//PASSENGERS

	void deletePassengerAdult(int iPass) {
		this->passengersAdult.erase(passengersAdult.begin() + iPass);
	}

	void deletePassengerChild(int iPass) {
		this->passengersChild.erase(passengersChild.begin() + iPass);
	}

	void deletePassengerPreferential(int iPass) {
		this->passengersPreferential.erase(passengersPreferential.begin() + iPass);
	}

	void deletePassengersAdult(int amount) {
		this->passengersAdult.erase(passengersAdult.begin() + 0, passengersAdult.begin() + amount);
	}

	void deletePassengersChild(int amount) {
		this->passengersChild.erase(passengersChild.begin() + 0, passengersChild.begin() + amount);
	}

	void deletePassengersPreferential(int amount) {
		this->passengersPreferential.erase(passengersPreferential.begin() + 0, passengersPreferential.begin() + amount);
	}


	//DRIVERS

	void deleteDriver(int iDriv) {
		this->drivers.erase(drivers.begin() + iDriv);
	}

	void deleteDrivers(int amount) {
		this->drivers.erase(drivers.begin() + 0, drivers.begin() + amount);
	}


	//CARS

	void deleteCar(int iCar) {
		this->cars.erase(cars.begin() + iCar);
	}

	void deleteCars(int iCar) {
		this->cars.erase(cars.begin() + iCar);
	}


	//BOARDING

	void boardPassengerAdult(int iCar, int iPass) {
		this->cars[iCar]->BoardPassenger(this->passengersAdult[iPass]);
		this->deletePassengerAdult(iCar);
	}
	void boardPassengerChild(int iCar, int iPass) {
		this->cars[iCar]->BoardPassenger(this->passengersChild[iPass]);
		this->deletePassengerChild(iCar);
	}
	void boardPassengerPreferential(int iCar, int iPass) {
		this->cars[iCar]->BoardPassenger(this->passengersPreferential[iPass]);
		this->deletePassengerPreferential(iCar);
	}

	void boardPassengersAdult(int iCar, int amount) {
		if (amount < 4)
			for (int i = 0; i < (this->cars[iCar])->getMaxPassengers(); i++)
				this->boardPassengerAdult(iCar,i);
	}

	void boardPassengersChild(int iCar, int amount) {
		if (amount < 4)
			for (int i = 0; i < (this->cars[iCar])->getMaxPassengers(); i++)
				this->boardPassengerChild(iCar, i);
	}

	void boardPassengersPreferential(int iCar, int amount) {
		if (amount < 4)
			for (int i = 0; i < (this->cars[iCar])->getMaxPassengers(); i++)
				this->boardPassengerPreferential(iCar, i);
	}

	void boardDriver(int iCar, int iDriv) {
		this->cars[iCar]->BoardDriver(this->drivers[iDriv]);
		this->deleteDriver(iDriv);
	}


	//ISREADY

	bool carIsReady(Cars* car) {
		if (car->readyToDrive()) {
			cout << "Может ехать." << endl;
			return true;
		}
		else {
			cout << "Не может ехать." << endl;
			return false;
		}
	}


	//MONEY

	/*int getEarnings() {
		return earnings;
	}

	void setEarningsToZero() {
		earnings = 0;
	}*/


	~BusStation() {
		int i;
		for (i = 0; i < cars.size(); ++i) delete cars[i];
		for (i = 0; i < drivers.size(); ++i) delete drivers[i];
		for (i = 0; i < passengersAdult.size(); ++i) delete passengersAdult[i];
		for (i = 0; i < passengersChild.size(); ++i) delete passengersChild[i];
		for (i = 0; i < passengersPreferential.size(); ++i) delete passengersPreferential[i];
	}
};
