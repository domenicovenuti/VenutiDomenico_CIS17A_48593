/* 
 * File: main.cpp
 * Author: Domenico Venuti
 * Created on October 4, 2021 at 7:12 PM
 * Purpose: Ga9EdC11P11 Exercise 3 - Code-E
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include <iomanip>

//Global Constants - No Global Variables
//float budgetC = {500.00, 150.00, 65.00, 50.00, 250.00, 30.00, 100.00, 150.00, 75.00, 50.00};

//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Structures
struct MonthlyBudget{    
    float housing;
    float utilities;
    float householdexpenses;
    float transportation;
    float food;
    float medical;
    float insurance;
    float entertainment;
    float clothing;
    float miscellaneous;
};

//Function Prototypes
void getData(MonthlyBudget[]);
float report(MonthlyBudget[]);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    MonthlyBudget monthlyBudget2[2] = {{500.00, 150.00, 65.00, 50.00, 250.00, 30.00, 100.00, 150.00, 75.00, 50.00}, {0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00}};        
    
    //Initialize Variables
    
    //Process or map Inputs to Outputs
    cin>>monthlyBudget2[1].housing>>monthlyBudget2[1].utilities>>monthlyBudget2[1].householdexpenses>>monthlyBudget2[1].transportation>>monthlyBudget2[1].food>>monthlyBudget2[1].medical>>monthlyBudget2[1].insurance>>monthlyBudget2[1].entertainment>>monthlyBudget2[1].clothing>>monthlyBudget2[1].miscellaneous;
    
    //Display Outputs
    getData(monthlyBudget2);
    
    //Exit stage right!
    return 0;
}

void getData(MonthlyBudget budget[]){
    float total;
    string uo;
    cout<<"Enter housing cost for the month:$"<<endl;
    cout<<"Enter utilities cost for the month:$"<<endl;
    cout<<"Enter household expenses cost for the month:$"<<endl;
    cout<<"Enter transportation cost for the month:$"<<endl;
    cout<<"Enter food cost for the month:$"<<endl;
    cout<<"Enter medical cost for the month:$"<<endl;
    cout<<"Enter insurance cost for the month:$"<<endl;
    cout<<"Enter entertainment cost for the month:$"<<endl;
    cout<<"Enter clothing cost for the month:$"<<endl;
    cout<<"Enter miscellaneous cost for the month:$"<<endl;    
    
    total = report(budget);
    
    if(total>0){
        uo = " under budget";
    }
    else if(total<0){
        uo = " over budget";
    }
    else{
        uo = " Even budget";
    }
    
    total = abs(total);
    
    cout<<fixed<<setprecision(2);
    cout<<"You were $"<<total<<uo;
    
}

float report(MonthlyBudget budget[]){
    
    float totalConstant = budget[0].housing + budget[0].utilities + budget[0].householdexpenses + budget[0].transportation + budget[0].food + budget[0].medical + budget[0].insurance + budget[0].entertainment + budget[0].clothing + budget[0].miscellaneous;
    float totalExpended = budget[1].housing + budget[1].utilities + budget[1].householdexpenses + budget[1].transportation + budget[1].food + budget[1].medical + budget[1].insurance + budget[1].entertainment + budget[1].clothing + budget[1].miscellaneous;
    float result = totalConstant - totalExpended;
    
    //housing
    if((budget[0].housing - budget[1].housing)>0){
        cout<<"Housing Under"<<endl;
    }
    else if(budget[0].housing == budget[1].housing){
        cout<<"Housing Even"<<endl;
    }
    else{
        cout<<"Housing Over"<<endl;
    }
    
    //Utilities                       
    if((budget[0].utilities - budget[1].utilities)>0){
        cout<<"Utilities Under"<<endl;
    }
    else if(budget[0].utilities == budget[1].utilities){
        cout<<"Utilities Even"<<endl;
    }
    else{
        cout<<"Utilities Over"<<endl;
    }
    
    //householdexpenses
    if((budget[0].householdexpenses - budget[1].householdexpenses)>0){
        cout<<"Household Expenses Under"<<endl;
    }
    else if(budget[0].householdexpenses == budget[1].householdexpenses){
        cout<<"Household Expenses Even"<<endl;
    }
    else{
        cout<<"Household Expenses Over"<<endl;
    }
    
    //transportation
    if((budget[0].transportation - budget[1].transportation)>0){
        cout<<"Transportation Under"<<endl;
    }
    else if(budget[0].transportation == budget[1].transportation){
        cout<<"Transportation Even"<<endl;
    }
    else{
        cout<<"Transportation Over"<<endl;
    }
    
    //food
    if((budget[0].food - budget[1].food)>0){
        cout<<"Food Under"<<endl;
    }
    else if(budget[0].food == budget[1].food){
        cout<<"Food Even"<<endl;
    }
    else{
        cout<<"Food Over"<<endl;
    }
    
    //medical
    if((budget[0].medical - budget[1].medical)>0){
        cout<<"Medical Under"<<endl;
    }
    else if(budget[0].medical == budget[1].medical){
        cout<<"Medical Even"<<endl;
    }
    else{
        cout<<"Medical Over"<<endl;
    }
    
    //insurance
    if((budget[0].insurance - budget[1].insurance)>0){
        cout<<"Insurance Under"<<endl;
    }
    else if(budget[0].insurance == budget[1].insurance){
        cout<<"Insurance Even"<<endl;
    }
    else{
        cout<<"Insurance Over"<<endl;
    }
    
    //entertainment
    if((budget[0].entertainment - budget[1].entertainment)>0){
        cout<<"Entertainment Under"<<endl;
    }
    else if(budget[0].entertainment == budget[1].entertainment){
        cout<<"Entertainment Even"<<endl;
    }
    else{
        cout<<"Entertainment Over"<<endl;
    }
    
    //clothing
    if((budget[0].clothing - budget[1].clothing)>0){
        cout<<"Clothing Under"<<endl;
    }
    else if(budget[0].clothing == budget[1].clothing){
        cout<<"Clothing Even"<<endl;
    }
    else{
        cout<<"Clothing Over"<<endl;
    }
    
    //miscellaneous
    if((budget[0].miscellaneous - budget[1].miscellaneous)>0){
        cout<<"Miscellaneous Under"<<endl;
    }
    else if(budget[0].miscellaneous == budget[1].miscellaneous){
        cout<<"Miscellaneous Even"<<endl;
    }
    else{
        cout<<"Miscellaneous Over"<<endl;
    }        
    
    return result;
}