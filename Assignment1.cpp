#include <iostream>
#include <string>
#include <cstring> //needed to use .c_str()
#include <fstream>
using namespace std;

inline void keep_window_open() {char ch; cin >> ch;} //inline function to keep window open until character is entered

struct PERSON
{
    char Name[20];
    float Balance;
};

int RecordCount()
{
    string source;
    int count = 0;

    ifstream in;
    in.open("dataVS");                     //put data in same folder as program 

    while(!in.eof())
    {
        getline (in, source);
        count ++;

    }

    in.close(); //always close files!
    return count;
}

int LoadMyStruct(struct PERSON P[], int Rcount) //The purpose of this function is to manipulate strings to avoid having to parse strings
{
    string Fullname;
    string Fname;
    string Lname;
    char Cname [20];    
    float bank = 0.0; // include iomanip to fix decimals
    
    ifstream in;
    
    in.open("dataVS");

    for(int i = 0; i < Rcount; i++)       //We will take advantage of the fact that we know how the text file is formatted 
    {
        in >> Fname >> Lname >> bank;     // read in each variable
        Fullname = Fname + " " + Lname;   // must concatenate strings
        strcpy(Cname, Fullname.c_str());  // Change Fullname into old C-style string and copy to Cname
        strcpy(P[i].Name,  Cname);        // Finally, strcpy Cname into our Struct
        P[i].Balance = bank;
    }
    in.close();
    return 0;
}

void Display(struct PERSON P[], int Rcount)
{
    cout << "Current Bank Accounts: " << endl;
    for(int i = 0; i < Rcount; i++)
    {
        cout << P[i].Name << " " << P[i].Balance << endl;
    }

}

void FindRichest(struct PERSON P[], int Rcount)
{
    float Largest = 0;
    int Richest = 0;

    for(int i = 0; i < Rcount; i++)
    {
        if(P[i].Balance > Largest)
        {
            Largest = P[i].Balance;
            Richest = i;
        }
    }
    cout << "The Customer with maximum balance is " << P[Richest].Name << endl;
}

void Deposit(string CustName, struct PERSON P[], int Rcount)
{
    float Deposit = 0;
    int MyCust = 0;
    char dCustName[20];
    strcpy(dCustName, CustName.c_str());

    for(int i = 0; i < Rcount; i++)
    {
        if(strcmp(dCustName, P[i].Name)== 0)
        {
            MyCust = i;
        }
    }

    cout << CustName << ", how much would you like to deposit? ";
    cin >> Deposit;

    P[MyCust].Balance = P[MyCust].Balance + Deposit;

    cout << "Now your new balance is " << P[MyCust].Balance << endl << endl;

}

void NewCopy(string File, struct PERSON P[], int Rcount)
{
    ofstream out;

    out.open("dataVS");

    for(int i = 0; i < Rcount; i++)
    {
        out << P[i].Name << " " << P[i].Balance << endl;
    }
    out.close();


}

int main()
{
    string Filename;
    string CustName;
    int Rcount = 0;                       //record count to assigned by function 
    Rcount = RecordCount();               // we can assaign Rcount the value returned from the void function.
    cout << " Record Count: " << Rcount << endl; 
    PERSON P[Rcount];                   //Create array of Structs. 
    LoadMyStruct(P, Rcount);
    Display(P, Rcount);
    FindRichest(P, Rcount);
    cout << "Enter your fullname to deposit money" << endl;
    getline(cin, CustName);
    Deposit(CustName, P, Rcount);
    NewCopy(Filename = "dataVS", P, Rcount); //need s = dataVS
    keep_window_open();                   // no need for system PAUSE
    return 0;

}

//ctrl + c to kill programs DO not just x out of Terminal Window. 
//ps aux, ps x, ps aux | grep <name>