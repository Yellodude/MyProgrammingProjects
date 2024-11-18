#include "Person.h"
using namespace std;

Person::Person() {
    firstName = "";
    lastName = "";
    birthDate = Date();
}

Person::~Person() {}

std::string Person::getFirstName() const { return firstName; }
std::string Person::getLastName() const { return lastName; }
Date Person::getBirthDate() const { return birthDate; }

void Person::setFirstName(std::string fName) { firstName = fName; }
void Person::setLastName(std::string lName) { lastName = lName; }
void Person::setBirthDate(Date bDate) { birthDate = bDate; }
void Person::setPerson(string fName, string lName, Date bDate) {
    firstName = fName;
    lastName = lName;
    birthDate = bDate;
}
