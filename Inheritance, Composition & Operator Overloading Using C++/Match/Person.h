#pragma once
#include "Date.h"
#include <string>

// the purpose of this abstract class is to create
// derived classes without needing to access implementation.
// It allows overriding of the console display function.
class Person {
protected:
    // Variable declarations
    std::string firstName;
    std::string lastName;
    Date birthDate;

public:
    // Constructors
    Person();
   
    // Destructors
    virtual ~Person();

    // Getters
    std::string getFirstName() const;
    std::string getLastName() const;
    Date getBirthDate() const;
    // Setters
    void setFirstName(std::string);
    void setLastName(std::string);
    void setBirthDate(Date);
    void setPerson(std::string, std::string, Date);

    // Following function is to be overridden by 
    // print functions in derived classes
    virtual void printInfo(std::ostream& out) const = 0;
};
