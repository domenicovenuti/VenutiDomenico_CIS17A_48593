/* 
 * File: main.cpp
 * Author: Domenico Venuti 
 * Created on September 30, 2021, 8:26 PM
 */

#include <iostream>
#include <string>
#include<string.h>
#include <sstream>
#include <iomanip>

using namespace std;

int *getData(int &);         //Return the array size and the array
void prntDat(int *, int);    //Print the integer array
float *median(int *, int);  //Fill the median Array with the Float array size, the median, and the integer array data
void prntMed(float *);     //Print the median Array

int main(){
    
    //My Code    
    int *array = nullptr; //Pointer intiliaze as nullptr
    float *array2 = nullptr;
    int x = 0;        
    
    array = getData(x);    
    prntDat(array, x);//Print the Matrix    
    cout<<endl;
    array2 = median(array, x + 2);
    prntMed(array2);
    
    return 0;
}

int *getData(int &x){
    int *array = nullptr;
    int i = 0;
    
    std::stringstream str;
    string b = ""; 
           
    std::getline(std::cin,b);
    int z = 0;
    for(char & c : b){
        if(c == ' '){
            
        }
        else{
            if(z < 2){
                str << c;                
                str >> x;                
                str.str("");
                str.clear();
                str.seekg(0);    
            }
            z++;
        }
    }
    
    array = new int[x];        
    b = ""; 
    str.str("");
    str.clear();
    str.seekg(0);     
        
    std::getline(std::cin,b);
    i = 0;
    for(char & c : b){
        if(c == ' '){

        }
        else
        {     
            if(i < x){
                str << c;
                str >> array[i];
                str.str("");
                str.clear();
                str.seekg(0);   
                i++;
            }            
        }                               
    }                  
        
    return array;           
}

void prntDat(int * array, int x){    
    for(int z = 0; z < x; z++){        
        if(z == x-1){
            cout<<array[z];
        }
        else{
            cout<<array[z]<<" ";
        }                
    }    
}

float *median(int *array, int x){
    int sum = 0;
    float *par = new float[x];
    int z1 = 0;
    
    par[0] = x;
    
    for(z1 = 0; z1 < x - 2; z1++){
        sum = sum + array[z1];        
    }
    
    par[1] = (float)((float)sum / ((float)x - 2));
    
    for(z1 = 0; z1 < x - 2; z1++){        
        par[z1 + 2] = array[z1];
    }        
    
    return par;
}

void prntMed(float * array){
    
    cout<<array[0]<<" ";
    
    std::cout << std::setprecision(2) << std::fixed;
    
    for(int z = 1; z < array[0]; z++){        
        if(z == array[0]-1){
            cout<<array[z];
        }
        else{
            cout<<array[z]<<" ";
        }                
    }    
}

//Domenico Venuti 2
