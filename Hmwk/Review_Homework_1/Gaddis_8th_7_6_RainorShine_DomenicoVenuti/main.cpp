/* 
 * Project: Chapter 7, Exercise 6 - CIS-17A
 * Author: Domenico Venuti
 * Created on September 12, 2021, 10:53 AM
 */

#include <iostream>
#include <fstream>
using namespace std;

const int columns = 30;
const int rows = 3; 

string months[rows]         = {"June", "July", "August"};
string weather_types[rows]  = {"Rainy", "Cloudy", "Sunny"};
char weather_day_names[rows]= {'R', 'C', 'S'};

//void readFile(char[][columns], string);
//void months(const char[][columns], int);
//void days(const char[][columns], int);
//void BiggestValue(const char[][columns]);


void readFile(char array[][columns], string file1)
{
    ifstream inputFile;

    inputFile.open(file1);

    for(int row = 0; row < rows; row++)
    {
        for(int col = 0; col < columns; col++)
            inputFile >> array[row][col];
    }

    inputFile.close();
}

void days(const char array[][columns], int i)
{
    int total;
    for (int row = 0; row < rows; row++)
    { 
        total = 0;
        for (int col = 0; col < columns; col++)
            if (array[row][col] == weather_day_names[i]) { total++; }

        cout << weather_types[i] << " days for " << months[row] << " = " << total << "\n";
    }
    cout << "----------------------------------------------------\n";
}

void biggest(const char array[][columns])
{
    int sum;
    int total_rainy_days[rows];
    
    for (int row = 0; row < rows; row++)
    {
        sum = 0;
        for (int col = 0; col < columns; col++)
            if (array[row][col] == 'R') { sum++; }
            
        total_rainy_days[row] = sum;
    }

    cout << "----------------------------------------------------\n";


    int highest_rainy_day = total_rainy_days[0];
    string highest_rainy_day_name = months[0];

    for(int i = 1; i < rows; i++)
    {
        if(total_rainy_days[i] > highest_rainy_day)
        {
            highest_rainy_day = total_rainy_days[i];
            highest_rainy_day_name = months[i];
        } 
        else if(total_rainy_days[i] == highest_rainy_day)
        {
            highest_rainy_day = total_rainy_days[i];
            highest_rainy_day_name += ", ";
            highest_rainy_day_name += months[i];
        }
            
    }

    cout << highest_rainy_day_name << " had the Highest Number of Rainy days, " << "with " << highest_rainy_day << " days.\n";
}

void monthsd(const char array[][columns], int i)
{
    int total = 0;
    for(int row = 0; row < rows; row++)
    {
        for(int col = 0; col < columns; col++)
            if(array[row][col] == weather_day_names[i]) { total++; }
    }

    cout << weather_types[i] << " days for all months = " << total << "\n";

}

int main()
{
    char weather_conditions[rows][columns];

    readFile(weather_conditions, "RainOrShine.txt");
    
    cout << "--- Weather Report for June, July and August --- \n";
    cout << "----------------------------------------------------\n";
    
    for (int letter = 0; letter < rows; letter++)
        days(weather_conditions, letter);
    
    for (int i = 0; i < rows; i++)
        monthsd(weather_conditions, i);

    biggest(weather_conditions);

    cout << "----------------------------------------------------\n";

    return 0;
}


