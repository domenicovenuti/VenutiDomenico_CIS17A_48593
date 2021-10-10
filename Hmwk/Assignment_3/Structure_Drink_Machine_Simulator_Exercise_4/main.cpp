/* 
 * File: main.cpp
 * Author: Domenico Venuti
 * Created on October 4, 2021 at 7:46 PM
 * Purpose: Structure Drink Machine Simulator - Exercise 4 - Code-E
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
struct SoftDrink{    
    string name;
    int cost;
    int units;    
};

//Function Prototypes
void getData(SoftDrink[]);
void displayDrinks(SoftDrink[]);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    SoftDrink drink[5] = {{"Cola",75,20},{"Root Beer",75,20},{"Lemon-Lime",75,20},{"Grape Soda",80,20},{"Cream Soda",80,20}};            
    
    //Process or map Inputs to Outputs    
    getData(drink);            
    
    //Exit stage right!
    return 0;
}

void displayDrinks(SoftDrink drink[]){
    for(int x = 0; x < 5; x++){
        if(x == 0){
            cout<<drink[x].name<<"       "<<drink[x].cost<<"  "<<drink[x].units<<endl;
        }
        else if(x == 1){
            cout<<drink[x].name<<"  "<<drink[x].cost<<"  "<<drink[x].units<<endl;
        }
        else{
            cout<<drink[x].name<<" "<<drink[x].cost<<"  "<<drink[x].units<<endl;            
        }
    }    
    cout<<"Quit"<<endl;
}

void getData(SoftDrink drink[]){
    string option = "";
    int pay = 0;
    int disc = 0;
    int gain = 0;
    while(option != "Quit"){
        displayDrinks(drink);             
        getline(cin, option);        
        if(option == drink[0].name){
            cin>>pay;
            cin.ignore();
            if(pay<0){
                cout<<"Amount can't be negative. Try again."<<endl;
            }
            else if(pay<drink[0].cost){
                cout<<"Insert More Money. Try Again"<<endl;
            }
            else if(pay>100){
                cout<<"Amount can't be greater than $1.00 Dollar. Try again."<<endl;
            }
            else{
                if(drink[0].units < 1){
                    cout<<"This Option is Sold Out. Choose another one or Quit."<<endl;
                }
                else{
                    disc = pay - drink[0].cost;
                    gain = gain + drink[0].cost;
                    drink[0].units = drink[0].units - 1;
                    cout<<disc<<endl;
                }
            }
        }
        else if(option == drink[1].name){
            cin>>pay;
            cin.ignore();
            if(pay<0){
                cout<<"Amount can't be negative. Try again."<<endl;
            }
            else if(pay<drink[1].cost){
                cout<<"Insert More Money. Try Again"<<endl;
            }
            else if(pay>100){
                cout<<"Amount can't be greater than $1.00 Dollar. Try again."<<endl;
            }
            else{
                if(drink[1].units < 1){
                    cout<<"This Option is Sold Out. Choose another one or Quit."<<endl;
                }
                else{
                    disc = pay - drink[1].cost;
                    gain = gain + drink[1].cost;
                    drink[1].units = drink[1].units - 1;
                    cout<<disc<<endl;
                }
            }
        }
        else if(option == drink[2].name){
            cin>>pay;
            cin.ignore();
            if(pay<0){
                cout<<"Amount can't be negative. Try again."<<endl;
            }
            else if(pay<drink[2].cost){
                cout<<"Insert More Money. Try Again"<<endl;
            }
            else if(pay>100){
                cout<<"Amount can't be greater than $1.00 Dollar. Try again."<<endl;
            }
            else{
                if(drink[2].units < 1){
                    cout<<"This Option is Sold Out. Choose another one or Quit."<<endl;
                }
                else{
                    disc = pay - drink[2].cost;
                    gain = gain + drink[2].cost;
                    drink[2].units = drink[2].units - 1;
                    cout<<disc<<endl;
                }
            }
        }
        else if(option == drink[3].name){
            cin>>pay;
            cin.ignore();
            if(pay<0){
                cout<<"Amount can't be negative. Try again."<<endl;
            }
            else if(pay<drink[3].cost){
                cout<<"Insert More Money. Try Again"<<endl;
            }
            else if(pay>100){
                cout<<"Amount can't be greater than $1.00 Dollar. Try again."<<endl;
            }
            else{
                if(drink[3].units < 1){
                    cout<<"This Option is Sold Out. Choose another one or Quit."<<endl;
                }
                else{
                    disc = pay - drink[3].cost;
                    gain = gain + drink[3].cost;
                    drink[3].units = drink[3].units - 1;
                    cout<<disc<<endl;
                }
            }
            
        }        
        else if(option == drink[4].name){       
            cin>>pay;    
            cin.ignore();
            if(pay<0){
                cout<<"Amount can't be negative. Try again."<<endl;
            }
            else if(pay<drink[4].cost){
                cout<<"Insert More Money. Try Again"<<endl;
            }
            else if(pay>100){
                cout<<"Amount can't be greater than $1.00 Dollar. Try again."<<endl;
            }
            else{
                if(drink[4].units < 1){
                    cout<<"This Option is Sold Out. Choose another one or Quit."<<endl;
                }
                else{
                    disc = pay - drink[4].cost;
                    gain = gain + drink[4].cost;
                    drink[4].units = drink[4].units - 1;
                    cout<<disc<<endl;
                }
            }
        }
        else{
        }                
    }   
    if(option == "Quit"){
        if(gain == 0){
            cout<<"No money earned."<<endl;
        }
        else{
            cout<<gain<<endl;
        }
    }
}