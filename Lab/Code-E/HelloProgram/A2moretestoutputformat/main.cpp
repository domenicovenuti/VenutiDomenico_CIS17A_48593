/* 
 * File: Code-E Compiler
 * Author: DOMENICO VENUTI
 * Date: 09/13/2021
 * Purpose: CODE-E (A2 MORE TEST OUTPUT FORMAT)
 * Version: 1.20
 */

//System Libraries - Post Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here when needed
    
    //Declare variables or constants here
    //7 characters or less
    int n1;
    int n2;
    int n3;
    int n4;
    //Initialize or input data here
    n1 = 0;
    n2 = 0;
    n3 = 0;
    n4 = 0;
    //Display initial conditions, headings here
    
    //Process inputs  - map to outputs here
    cin>>n1;
    cin>>n2;
    cin>>n3;
    cin>>n4;
    //Format and display outputs here
    cout<<"        "<<n1<<"       "<<setprecision(2)<<showpoint<<(float)n1<<"      "<<setprecision(3)<<showpoint<<(float)n1<<"\n";
    cout<<"        "<<n2<<"       "<<setprecision(2)<<showpoint<<(float)n2<<"      "<<setprecision(3)<<showpoint<<(float)n2<<"\n";
    cout<<"        "<<n3<<"       "<<setprecision(2)<<showpoint<<(float)n3<<"      "<<setprecision(3)<<showpoint<<(float)n3<<"\n";
    cout<<"        "<<n4<<"       "<<setprecision(2)<<showpoint<<(float)n4<<"      "<<setprecision(3)<<showpoint<<(float)n4;
    //Clean up allocated memory here
    
    //Exit stage left
    return 0;
}