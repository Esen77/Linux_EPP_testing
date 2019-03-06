//begin Person.h
#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person
{
    private:
        string lastName;
        string firstName;
        float payRate;
        float hoursWorked;
    public:
        Person();
        void setLastName(string lName);
        string getLastName();
        void setFirstName(string fName);
        string getFirstName();
        void setPayRate(float rate);
        float getPayRate();
        void setHoursWorked(float hours);
        float getHoursWorked();
        float totalPay();       // used by writeData function in main to copy "Total Pay" to output.txt
        string fullName();      // used by writeData function in main to copy "Full name" to output.txt


};
#endif // end person.h
