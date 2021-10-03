/* 
 * File: main.cpp
 * Author: Domenico Venuti 
 * Created on September 29, 2021, 8:43 PM
 */

#include <iostream>
#include <string>
#include<string.h>
#include <sstream>

using namespace std;

int *getData(int &);//Get the Matrix Data
void printAry(const int *, int);//Print the Matrix
int *sumAry(const int *,int);//Return the array with successive sums

int main(){
    
    //My Code    
    int *array = nullptr; //Pointer intiliaze as nullptr
    int *array2 = nullptr;
    int x = 0;        
    
    array = getData(x);    
    printAry(array, x);//Print the Matrix    
    cout<<endl;
    array2 = sumAry(array, x);
    printAry(array2, x);
    
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

void printAry(const int * array, int x){    
    for(int z = 0; z < x; z++){        
        if(z == x-1){
            cout<<array[z];
        }
        else{
            cout<<array[z]<<" ";
        }                
    }    
}

int *sumAry(const int *array, int x){
    int sum = 0;
    int *par = new int[x];
    
    for(int z1 = 0; z1 < x; z1++){
        sum = sum + array[z1];
        par[z1] = sum;
    }        
    
    return par;
}
//Domenico Venuti 4