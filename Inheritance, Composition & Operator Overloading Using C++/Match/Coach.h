#pragma once
//Include statements
#include "Person.h"

// the purpose of this class is to create coach
// objects without needing to access implementation
class Coach : public Person {
private:
    // Variable declarations
    std::string coachTitle;
    Date hireDate;
    double annualSalary;
    int yearsCoached;

public:
    // Constructors
    Coach();
    Coach(std::string, std::string, Date, std::string, Date, double, int);
    // Destructors
    ~Coach();

    // Getters
    std::string getTitle() const;
    Date getHireDate() const;
    double getAnnualSalary() const;
    int getYearsCoached() const;
    // Setters
    void setTitle(std::string);
    void setHireDate(Date);
    void setAnnualSalary(double);
    void setYearsCoached(int);

    // Following function displays  match info on console
    // Overrides the  PersonprintInfo function
    void printInfo(std::ostream& out) const override;

    // Operator overloading for printing coach information
    friend std::ostream& operator<<(std::ostream&, const Coach&);
};
