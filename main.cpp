#include <iostream>
#include "Director.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");

    float earningMoney = 0;
    float cost = 90;
    float billTaxi = 4;
    float billBusAdult = 1;
    float billBusChild = 0.5;
    float billBusPreferential = 0;

    Director dir;
    BusBuilder busBuilder;
    TaxiBuilder taxiBuilder;

    BusStation* bus = dir.createBusStation(busBuilder,1,1,20,3,1);
    BusStation* taxi = dir.createBusStation(taxiBuilder,1,1,1,1,0);

    cout << endl << "Автобусы:" << endl;
    bus->info();
    cout << endl << "Такси:" << endl;
    taxi->info();

    while ((!bus->cars.empty() && !bus->drivers.empty() 
            && (!bus->passengersAdult.empty() || !bus->passengersChild.empty() || !bus->passengersPreferential.empty()))
        || (!taxi->cars.empty() && !taxi->drivers.empty() 
            && (!taxi->passengersAdult.empty() || !taxi->passengersChild.empty()))) {

        if (!bus->cars.empty() && !bus->drivers.empty()
                && (!bus->passengersAdult.empty() || !bus->passengersChild.empty() || !bus->passengersPreferential.empty())) {
            bus->boardDriver(0, 0);

            for (int i = 0; i < 29; i++) {
                if (!bus->passengersAdult.empty()) {
                    bus->boardPassengerAdult(0, 0);
                    earningMoney += billBusAdult * cost;
                }
                else 
                    if (!bus->passengersChild.empty()) {
                        bus->boardPassengerChild(0, 0);
                        earningMoney += billBusChild * cost;
                    }
                    else
                        if (!bus->passengersPreferential.empty()) {
                            bus->boardPassengerPreferential(0, 0);
                            earningMoney += billBusPreferential * cost;
                        }
                        else break;
            }

            if (bus->carIsReady(bus->cars[0])) {
                bus->deleteCar(0);
            }
        }

        if (!taxi->cars.empty() && !taxi->drivers.empty()
            && (!taxi->passengersAdult.empty() || !taxi->passengersChild.empty())) {
            taxi->boardDriver(0, 0);

            for (int i = 0; i < 3; i++) {
                if (!taxi->passengersAdult.empty()) taxi->boardPassengerAdult(0, 0);
                else 
                    if (!taxi->passengersChild.empty()) taxi->boardPassengerChild(0, 0); 
                    else break;
            }

            if (taxi->carIsReady(taxi->cars[0])) {
                earningMoney += billTaxi * cost;
                taxi->deleteCar(0);
            }
        }
    }

    cout << endl << "Заработано денег: " << earningMoney << endl;

    cout << endl << "Автобусы:" << endl;
    bus->info();
    cout << endl << "Такси:" << endl;
    taxi->info();


    /*BusStation* busStation = new BusStation;
    TaxiFactory taxiFactory;
    BusFactory busFactory;

    int counter = 0;

    busStation->addPassengers(40);

    busStation->addBusDrivers(busFactory,1);
    busStation->addBusBoards(busFactory, 1);

    busStation->addTaxiDrivers(taxiFactory, 4);
    busStation->addTaxiBoards(taxiFactory, 4);

    cout << "\nВывод:\n";
    busStation->info();
    cout << "\n";

    while ((!busStation->boardBus.empty() && !busStation->driverBus.empty()) 
        || (!busStation->boardTaxi.empty() && !busStation->driverTaxi.empty())) {

        if (!busStation->boardBus.empty() && !busStation->driverBus.empty()) {
            busStation->boardDriverToBus(0,0);

            for (int i = 0; i < 29; i++) {
                if (!busStation->passengers.empty()) busStation->boardPassengerToBus(0, 0);
                else break;
            }

            if (busStation->carIsReady(busStation->boardBus[0])) {
                busStation->deleteBusBoard(0);
            }
        }

        if (!busStation->boardTaxi.empty() && !busStation->driverTaxi.empty()) {
            busStation->boardDriverToTaxi(0, 0);

            for (int i = 0; i < 3; i++) {
                if (!busStation->passengers.empty()) busStation->boardPassengerToTaxi(0, 0);
                else break;
            }

            if (busStation->carIsReady(busStation->boardTaxi[0])) {
                busStation->deleteTaxiBoard(0);
            }
        }
    }

    cout << "\nВывод:\n";
    busStation->info();
    cout << "\n";*/

    return 0;
}
