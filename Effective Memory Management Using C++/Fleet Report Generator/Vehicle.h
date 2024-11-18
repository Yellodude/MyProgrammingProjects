#pragma once
#ifndef VEHICLE_H
#define VEHICLE_H

// Include statements
#include <iostream>
#include <string>
using namespace std;

// The pupose of this class is to create a report on all information about
// the user's vehicle collection. Information about vehicles must
// first be given by the user for each object created. It also demostrates
// the use of destructors.
class Vehicle {
private:
    // variable declarations
    string manufactureName;
    string modelName;
    string vehicleColor;
    int numberOfTailLights;

public:
    // Constructors
    Vehicle();

    // Destructors
    ~Vehicle();

    // Setters
    void setManufactureName(const string& name);
    void setModelName(const string& model);
    void setVehicleColor(const string& color);
    void setNumberOfTailLights(int num);

    // Getters
    string getManufactureName() const;
    string getModelName() const;
    string getVehicleColor() const;
    int getNumberOfTailLights() const;
};
#endif

