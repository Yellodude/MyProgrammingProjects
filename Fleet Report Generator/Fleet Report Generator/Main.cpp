// Brief Description: 
// A program that collects and reports information on a user's vehicle collection.
// However, the number of taillights for each car is randomized.

// Include Statements
#include "Vehicle.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// The purpose of this project is to demostrate utilizing dynamic memory 
// allocation and deallocation to display the user's car collection 
// after prompting the user to enter info on all their cars.
int main() {
    cout << "\nPersonal Fleet Report Generator\n" << endl;

    // Followng line seeds the random number generator function i.e. rand()
    // However, since the limit is set to 100, rand() generates 
    // the same sequence in every execution.
    srand(100);

    // Following loops prompts user for the number of vehicles owned
    // and error-checks the user's responses
    int numVehicles;
    do {
        cout << "Number of vehicles you have owned (2 - 10): ";
        cin >> numVehicles;

        if (cin.fail() || numVehicles < 2 || numVehicles > 10) {
            cin.clear(); cin.ignore();
            cout << "Try again. Please enter a number between 2 and 10." << endl;
        }
    } while (cin.fail() || numVehicles < 2 || numVehicles > 10);

    // FOllowing line clears the newline character left by cin
    // to prevent conflict with getline()
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    // Following line dynamically allocates an array of pointers to 
    // Vehicle objects using the user-specified number of vehicles
    Vehicle** vehicleArray = new Vehicle * [numVehicles];

    // Following loop collects information on each vehicle based on the count
    // specified by the user
    for (int i = 0; i < numVehicles; ++i) {
        // following line dynamically creates new vehicle objects up to the user-specified limit
        // i.e. the maximum number of vehicles owned
        vehicleArray[i] = new Vehicle();

        string manufacture;
        string model;
        string color;

        // Following loop allows user input and error-checks manufacturer name
        do {
            cout << "\nVehicle #" << (i + 1) << endl << endl;
            cout << "Vehicle Manufacture" << ": ";
            getline(cin, manufacture);
        } while (manufacture.empty());

        // Following loop allows user input and error-checks vehicle model name
        do {
            cout << "Model of " << manufacture << " vehicle" << " (Escape, F-150, etc.): ";
            getline(cin, model);
        } while (model.empty());

        // Following loop allows user input and error-checks vehicle color name
        do {
            cout << "Color of the " << model << " (White, Blue, etc.): ";
            getline(cin, color);
        } while (color.empty());

        // Following line generates a random number of tail lights that is never zero
        int numTailLights = (rand() % 5) + 1;

        // Following 4 lines update the Vehicle object's members with user entries 
        vehicleArray[i]->setManufactureName(manufacture);
        vehicleArray[i]->setModelName(model);
        vehicleArray[i]->setVehicleColor(color);
        vehicleArray[i]->setNumberOfTailLights(numTailLights);

        cout << "Creating new Vehicle." << endl;
    }

    // Following loop displays report on all owned vehicles
    for (int i = 0; i < numVehicles; ++i) {
        cout << setw(40) << right << "\nThese are the vehicles you own:\n";
        cout << setw(40) << right << "Vehicle Manufacture: " << vehicleArray[i]->getManufactureName() << endl;
        cout << setw(40) << right << "Vehicle Model: " << vehicleArray[i]->getModelName() << endl;
        cout << setw(40) << right << "Vehicle Color: " << vehicleArray[i]->getVehicleColor() << endl;
        cout << setw(40) << right << "Number of Tail Lights per side (1-5): " << vehicleArray[i]->getNumberOfTailLights() << endl;
        cout << endl;
    }


    // Following loop deallocates memory used by the Vehicle objects and
    // the array of vehicles itself
    for (int i = 0; i < numVehicles; ++i) {
        delete vehicleArray[i];
        vehicleArray[i] = nullptr;
    }
    delete[] vehicleArray;
    vehicleArray = nullptr;

    cout << "\n"; // an empty line
    system("pause");
    return 0;
}
