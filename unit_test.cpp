#include "movAvgFilter.h"
#include <iostream>
using namespace std;

int main()
{
    MovingAverageFilter<double, 2> mov; //Initialize Filter to take average of last 2 elements and return average as double
    cout << "Enter in Number to be Added to Filter (Enter -1 to quit program): "<<endl;
    double input;
    cin >> input;

    while (!cin)
    {
        cout << "Please Enter Valid Number (Enter -1 to quit program): "<<endl;
        cin.clear();
        cin.ignore();
        cin >> input;
    }

    while(input != -1)
    {
        cout<< "The Current Step Average is: " << mov.Step(input) <<endl <<endl;
        cout << "Enter in Number to be Added to Filter (Enter -1 to quit program): "<<endl;
        cin >> input;
        while (!cin)
        {
            cout << "Please Enter Valid Number (Enter -1 to quit program): "<<endl;
            cin.clear();
            cin.ignore();
            cin >> input;
        }
    }
}