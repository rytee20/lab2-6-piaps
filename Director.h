#pragma once
#include "BusStationBuilder.h"

class Director
{
public:
	BusStation* createBusStation(BusStationBuilder& builder, int amountCar = 1, int amountDriver = 1, int amountAdult = 1, 
		int amountChild = 1, int amountPreferential = 0) {
		builder.createBusStation();
		for (int i = 0; i < amountCar; i++) builder.buildCar();
		for (int i = 0; i < amountDriver; i++) builder.buildDriver();
		for (int i = 0; i < amountAdult; i++) builder.buildPassengerAdult();
		for (int i = 0; i < amountChild; i++) builder.buildPassengerChild();
		for (int i = 0; i < amountPreferential; i++) builder.buildPassengerPreferential();
		return(builder.getBusStation());
	}
};
