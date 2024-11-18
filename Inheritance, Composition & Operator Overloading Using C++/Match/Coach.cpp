#include "Coach.h"
#include "iomanip"
using namespace std;

Coach::Coach() {
    Person;
    coachTitle = "";
    hireDate = Date();
    annualSalary = 0;
    yearsCoached = 0;
}

Coach::Coach(string fName, string lName, Date bDate, string title, Date hDate, double salary, int years) {
    setPerson(fName, lName, bDate);
    coachTitle = title;
    hireDate = hDate;
    annualSalary = salary;
    yearsCoached = years;
}

Coach::~Coach() {}

string Coach::getTitle() const { return coachTitle; }
Date Coach::getHireDate() const { return hireDate; }
double Coach::getAnnualSalary() const { return annualSalary; }
int Coach::getYearsCoached() const { return yearsCoached; }

void Coach::setTitle(string t) { coachTitle = t; }
void Coach::setHireDate(Date hDate) { hireDate = hDate; }
void Coach::setAnnualSalary(double salary) { annualSalary = salary; }
void Coach::setYearsCoached(int years) { yearsCoached = years; }

void Coach::printInfo(ostream& out) const {
    cout << setw(40) << right << "Name - Title: " << firstName;
    cout << ", " << lastName << " - " << coachTitle << endl;
    cout << setw(40) << right << "Jersey #: " << "00" << endl;
    cout << setw(40) << right << "Birth Date: " << birthDate << endl;
    cout << setw(40) << right << "Years Coached: " << yearsCoached << endl;
    cout << setw(40) << right << "Hire Date: " << hireDate << endl;
    cout << setw(40) << right << "Annual Salary: " << annualSalary;
}

ostream& operator<<(ostream& out, const Coach& coach) {
    coach.printInfo(out);
    return out;
}
