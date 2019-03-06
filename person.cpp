#include "person.h"
//define member functions of class Person


Person::Person()
{
    payRate = 0;
    hoursWorked = 0;
    firstName = "Empty";
    lastName = "Empty";
};
// inline definitions of functions
inline void Person::setFirstName(string fName){firstName = fName;}
inline string Person::getFirstName(){return firstName;}
inline void Person::setLastName(string lName){lastName = lName;}
inline string Person::getLastName(){return lastName;}
inline void Person::setPayRate(float rate){payRate = rate;}
inline float Person::getPayRate(){return payRate;}
inline void Person::setHoursWorked(float hours){hoursWorked = hours;}
inline float Person::getHoursWorked(){return hoursWorked;}
inline float Person::totalPay(){return hoursWorked * payRate;}
inline string Person::fullName(){return firstName + " " + lastName;}

/* BEGIN normal definitions of functions

void Person::setFirstName(string fName)
{
    firstName = fName;

} 

string Person::getFirstName()
{
    return firstName;
}

void Person::setLastName(string lName)
{
  
    lastName = lName;

}

string Person::getLastName()
{
    return lastName;
} 

void Person::setPayRate(float rate)
{
    payRate = rate;
}

float Person::getPayRate()
{
    return payRate;
}

void Person::setHoursWorked(float hours)
{
    hoursWorked = hours;
}

float Person::getHoursWorked()
{
    return hoursWorked;
} 

float Person::totalPay()
{
    return hoursWorked * payRate;
}

string Person::fullName()
{
    return firstName + " " + lastName;
} 
END normal definition of functions*/