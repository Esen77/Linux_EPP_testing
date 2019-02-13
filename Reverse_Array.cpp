#include <iostream>
using namespace std;

void Reverse_Array(int MyArray[], int a_size) //Arrays are passed by Reference by default
{
                               
    for (int i = 0; i < a_size; i++)         
    {            
        int Swap = MyArray[i];          
        MyArray[i] = MyArray[a_size];
        MyArray[a_size] = Swap;
        a_size--;
    }
}

void Myprint (int MyArray[], int a_size)
{
    for (int i = 0; i < a_size; i++)
    {
        cout << MyArray[i] << endl;
    }


}

int main()
{
    int MyArray[] = {1, 2, 3, 4 };
    cout << "The array is: " << endl;
    Myprint(MyArray, 4);
    cout << "Reversed Array is now: "<< endl;
    Reverse_Array(MyArray, 4);
    cout << endl;
    return 0;



}