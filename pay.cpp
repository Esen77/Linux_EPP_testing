#include "person.cpp"
#include <string>
#include <iomanip>      //setprecision()
#include <iostream>
#include <fstream>
using namespace std;
// g++ -o pay pay.cpp person.cpp person.h gives access to private variables!
//
// g++ -o pay pay.cpp

int readData(class Person employee[], int size, int lineCount) 
{                                                 
    string fName;
    string lName;
    float rate;
    float hours;
    int count = 0;

    ifstream inFile;
    inFile.open("input.txt");

    while(!inFile.eof())
    {
        
        inFile >> fName >> lName >> hours >> rate; //we take advantage of the file format.
        employee[count].setFirstName(fName);       //The loop should count through the number of lines in the file.
        employee[count].setLastName(lName);
        employee[count].setHoursWorked(hours);
        employee[count].setPayRate(rate);
        count++; 
    }
    
    return lineCount = count;                      // we now have the new size, but the array is still of size 20.


    inFile.close();

}

void writeData(class Person employee[], int size, int lineCount)   
{                                                  
    ofstream outFile;
    outFile.open("output.txt");

    for(int i = 0; i < lineCount; i++)
    {
        outFile << employee[i].fullName() << " " << setprecision(2) << fixed <<  employee[i].totalPay() << endl;
    }
    outFile.close();

    return;
    
}

int main()
{
    int size = 20;
    int lineCount = 0;        
    Person employee[size];                              //Note: employee array is size 20 throughout runtime. 
    lineCount = readData(employee, size, lineCount);    //set lineCountto number of lines read.                                   
    writeData(employee, size, lineCount);

return 0;

}