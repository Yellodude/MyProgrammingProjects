/*
* Date.cpp
*
* Purpose:
* To provide the ability to work with dates in C++.
*/

#include "Date.h"
using namespace std;

ostream& operator<<(ostream& output, Date d)
/*
* This function is used to give the user the date
* in a formatted structure that can be used in
 * a cout statement.
 * See the Date.h file for an example.
 */
{
    output << d.month << "/" << d.day << "/" << d.year;
    return output;
}

Date::Date()
{
    setDate(1, 1, 1980);
}

Date::Date(int d, int m, int yyyy)
{
    setDate(d, m, yyyy);
}

Date::~Date() {}

void Date::setDate(int d, int m, int yyyy)
{
    day = d;
    month = m;
    year = yyyy;
}
