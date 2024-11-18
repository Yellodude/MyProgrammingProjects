// Include statements
#include "Vehicle.h"
#include <iostream>
#include <cstdlib>
using namespace std;

// Constructor implementation
Vehicle::Vehicle() {
    manufactureName = "";
    modelName = "";
    vehicleColor = "";
    numberOfTailLights = 0;
}

// Destructor implementation
Vehicle::~Vehicle() {
    cout << "Object resources freed..." << endl;
}

// Setters implementation
void Vehicle::setManufactureName(const string& name) {
    manufactureName = name;
}
void Vehicle::setModelName(const string& model) {
    modelName = model;
}
void Vehicle::setVehicleColor(const string& color) {
    vehicleColor = color;
}
void Vehicle::setNumberOfTailLights(int num) {
    numberOfTailLights = num;
}

// Getters implementation
string Vehicle::getManufactureName() const {
    return manufactureName;
}
string Vehicle::getModelName() const {
    return modelName;
}
string Vehicle::getVehicleColor() const {
    return vehicleColor;
}
int Vehicle::getNumberOfTailLights() const {
    return numberOfTailLights;
}
