/* 
 * File: main.cpp
 * Author: Domenico Venuti
 * Created on October 3, 2021 at 7:17AM
 * Purpose: Ga9EdC11P3 Exercise 1 - Homework 3 Structures
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include<iomanip>

//Define Structures
struct CompanyDivision{
    string name;
    float firstQSales;
    float secondQSales;
    float thirdQSales;
    float fourthQSales;
    float annualSales;
};

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
float annualSales(float, float, float, float);
float averageQSales(float);
void printSales(CompanyDivision, float);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    CompanyDivision north;
    CompanyDivision south;
    CompanyDivision east;
    CompanyDivision west;
    
    //Initialize Variables
    north = {"North", 0.00, 0.00, 0.00, 0.00, 0.00};
    south = {"South", 0.00, 0.00, 0.00, 0.00, 0.00};
    east = {"East", 0.00, 0.00, 0.00, 0.00, 0.00};
    west = {"West", 0.00, 0.00, 0.00, 0.00, 0.00};
    
    //Process or map Inputs to Outputs
    
    cin>>north.firstQSales>>north.secondQSales>>north.thirdQSales>>north.fourthQSales;    
    cin>>west.firstQSales>>west.secondQSales>>west.thirdQSales>>west.fourthQSales;
    cin>>east.firstQSales>>east.secondQSales>>east.thirdQSales>>east.fourthQSales;
    cin>>south.firstQSales>>south.secondQSales>>south.thirdQSales>>south.fourthQSales;    
    
    north.annualSales = annualSales(north.firstQSales, north.secondQSales, north.thirdQSales, north.fourthQSales);
    south.annualSales = annualSales(south.firstQSales, south.secondQSales, south.thirdQSales, south.fourthQSales);
    east.annualSales = annualSales(east.firstQSales, east.secondQSales, east.thirdQSales, east.fourthQSales);
    west.annualSales = annualSales(west.firstQSales, west.secondQSales, west.thirdQSales, west.fourthQSales);
        
    cout<<north.name<<endl;
    cout<<"Enter first-quarter sales:"<<endl;
    cout<<"Enter second-quarter sales:"<<endl;
    cout<<"Enter third-quarter sales:"<<endl;
    cout<<"Enter fourth-quarter sales:"<<endl;
    printSales(north, averageQSales(north.annualSales));
    cout<<endl;
    cout<<west.name<<endl;
    cout<<"Enter first-quarter sales:"<<endl;
    cout<<"Enter second-quarter sales:"<<endl;
    cout<<"Enter third-quarter sales:"<<endl;
    cout<<"Enter fourth-quarter sales:"<<endl;
    printSales(west,averageQSales(west.annualSales));
    cout<<endl;
    cout<<east.name<<endl;
    cout<<"Enter first-quarter sales:"<<endl;
    cout<<"Enter second-quarter sales:"<<endl;
    cout<<"Enter third-quarter sales:"<<endl;
    cout<<"Enter fourth-quarter sales:"<<endl;
    printSales(east,averageQSales(east.annualSales));
    cout<<endl;
    cout<<south.name<<endl;
    cout<<"Enter first-quarter sales:"<<endl;
    cout<<"Enter second-quarter sales:"<<endl;
    cout<<"Enter third-quarter sales:"<<endl;
    cout<<"Enter fourth-quarter sales:"<<endl;
    printSales(south,averageQSales(south.annualSales));
   
    //Display Outputs
    
    
    //Exit stage right!
    return 0;
}

float annualSales(float q1, float q2, float q3, float q4){
    float annual;
    
    annual = q1 + q2 + q3 + q4;
    
    return annual;
}

float averageQSales(float annualSales){
    float average;
    
    average = annualSales / 4;
    
    return average;
}

void printSales(CompanyDivision company, float average){   
    cout<<fixed<<setprecision(2);
    cout<<"Total Annual sales:$"<<company.annualSales<<endl;
    cout<<"Average Quarterly Sales:$"<<average;    
}