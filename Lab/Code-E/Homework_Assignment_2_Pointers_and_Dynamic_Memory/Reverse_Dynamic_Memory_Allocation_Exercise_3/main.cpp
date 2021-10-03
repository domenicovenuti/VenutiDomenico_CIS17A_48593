/* 
 * File: main.cpp
 * Author: Domenico Venuti 
 * Created on October 1, 2021, 8:49 PM
 */

#include <iostream>
#include <string>
#include<string.h>
#include <sstream>
#include <algorithm>

using namespace std;

int *getData(int &);//Get the Matrix Data
void prntDat(const int *, int);//Print the Matrix
int *sort(const int *,int);         //Sort smallest to largest
int *reverse(const int *,int);  //Sort in reverse order

int main(){
    
    //My Code    
    int *array = nullptr; //Pointer intiliaze as nullptr    
    int x = 0;        
    
    array = getData(x);           
    array = sort(array, x);
    prntDat(array, x);
    array = reverse(array, x);
    cout<<endl;
    prntDat(array, x);
    
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
    for(char & d : b){
        if(d == ' '){

        }
        else
        {     
            if(i < x){
                str << d;
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

void prntDat(const int * array, int x){    
    for(int z = 0; z < x; z++){        
        if(z == x-1){
            cout<<array[z];
        }
        else{
            cout<<array[z]<<" ";
        }                
    }    
}

int *sort(const int * array, int size){
    int *array2 = new int[size];
    
    for(int y = 0; y < size; y++){
        array2[y] = array[y];
    }
    
    int control = 0;
    int save = 0;        
    int x = 0;
    
    while(control == 0){
        control = 1;
        save = 0;
        for(x = 0; x < size - 1; x++){            
            if(array2[x+1]<array2[x]){
                save = array2[x];
                array2[x] = array2[x+1];
                array2[x+1] = save;
                control = 0;
            }
        }
    }
    return array2;
}

int *reverse(const int * array, int size){
    int *arraya = new int[size];
    int *array2 = new int[size];    
    for(int y = 0; y < size; y++){
        arraya[y] = array[y];
    }
    int z = size-1;
        
    for(int x = 0; x < size; x++){
        array2[x] = arraya[z];
        z--;
    }
        
    return array2;
}

//Domenico Venuti 3