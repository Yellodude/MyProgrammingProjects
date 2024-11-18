#pragma once
//Include statements
#include "Person.h"

// the purpose of this class is to create player objects
// without needing to access implementation. It contains most
// relevant variables for player identification.
class Player : public Person {
private:
    // Variable declarations
    std::string jerseyNumber;
    std::string position;
    double averagePoints;
    std::string skillLevel;
    Date graduationDate;
    int yearsPlayed;

public:
    // Constructors
    Player();
    Player(std::string, std::string, Date, Date, int, std::string, std::string, double, std::string);
    // Destructors
    ~Player();

    // Getters
    std::string getJerseyNumber() const;
    std::string getPosition() const;
    double getAveragePoints() const;
    std::string getSkillLevel() const;
    // Setters
    void setJerseyNumber(std::string);
    void setPosition(std::string);
    void setAveragePoints(double);
    void setSkillLevel(std::string);

    // Following function displays  match info on console
    // Overrides the printInfo function
    void printInfo(std::ostream& out) const override;

    // Operator overloading for printing player information
    friend std::ostream& operator<<(std::ostream&, const Player&);
};
