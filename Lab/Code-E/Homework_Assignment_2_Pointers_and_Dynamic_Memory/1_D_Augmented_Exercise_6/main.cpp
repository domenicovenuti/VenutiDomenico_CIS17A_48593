/* 
 * File: main.cpp
 * Author: Domenico Venuti 
 * Created on September 29, 2021, 2:43 PM
 */

#include <iostream>
#include <string>
#include<string.h>
#include <sstream>

using namespace std;

int *getData(int &);//Get the Matrix Data
void printDat(const int *, int);//Print the Matrix
int *augment(const int *, int);//Augment the original array

int main(){
    
    //My Code    
    int *array = nullptr; //Pointer intiliaze as nullptr
    int *array2 = nullptr;
    int x = 0;        
    
    array = getData(x);    
    printDat(array, x);//Print the Matrix    
    cout<<endl;    
    array2 = augment(array, x + 1);//Augment the original array                
    printDat(array2, x + 1);//Print the Matrix        
    
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

void printDat(const int * array, int x){    
    for(int z = 0; z < x; z++){        
        if(z == x-1){
            cout<<array[z];
        }
        else{
            cout<<array[z]<<" ";
        }                
    }
    
}

int *augment(const int *array, int x){
    
    int *temp = nullptr;
    temp = new int[x];
    for(int z = 0; z < x; z++){
        if(z == 0){
                temp[z] = 0;
            }
            else{
                temp[z] = array[z-1];
            }
    }                    
    
    return temp;
}
//Domenico Venuti 6