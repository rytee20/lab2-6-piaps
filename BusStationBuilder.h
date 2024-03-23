#pragma once
#include "BusStation.h"

class BusStationBuilder
{
protected:
	BusStation* bs;
public:
	BusStationBuilder() : bs(nullptr) {};
	virtual ~BusStationBuilder() {};
	virtual void createBusStation() = 0;
	virtual void buildPassengerAdult() = 0;
	virtual void buildPassengerChild() = 0;
	virtual void buildPassengerPreferential() = 0;
	virtual void buildCar() = 0;
	virtual void buildDriver() = 0;
	BusStation* getBusStation() { return bs; }
};

class TaxiBuilder : public BusStationBuilder
{
public:
	void createBusStation() { bs = new BusStation(); }
	void buildDriver() { bs->drivers.push_back(new TaxiDriver()); }
	void buildCar() { bs->cars.push_back(new CarTaxi()); }
	void buildPassengerAdult() { bs->passengersAdult.push_back(new PassengerAdult()); }
	void buildPassengerChild() { bs->passengersChild.push_back(new PassengerChild()); }
	void buildPassengerPreferential() {}
};

class BusBuilder : public BusStationBuilder
{
public:
	void createBusStation() { bs = new BusStation(); }
	void buildDriver() { bs->drivers.push_back(new BusDriver()); }
	void buildCar() { bs->cars.push_back(new CarBus()); }
	void buildPassengerAdult() { bs->passengersAdult.push_back(new PassengerAdult()); }
	void buildPassengerChild() { bs->passengersChild.push_back(new PassengerChild()); }
	void buildPassengerPreferential() { bs->passengersPreferential.push_back(new PassengerPreferential()); }
};
