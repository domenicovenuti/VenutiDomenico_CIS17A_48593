/* 
 * File: main.cpp
 * Author: Domenico Venuti 
 * Created on September 29, 2021, 9:20 PM
 */

#include <iostream>
#include <string>
#include<string.h>
#include <sstream>

using namespace std;

int **getData(int &,int &);//Get the Matrix Data
void printDat(const int * const *,int,int);//Print the Matrix
void destroy(int **,int);//Destroy the Matrix, i.e., reallocate memory
int sum(const int * const *, int,int);    //Return the Sum

int main(){
    
    //My Code    
    int **array = nullptr; //Pointer intiliaze as nullptr    
    int x = 0;
    int y = 0;
    int sum1 = 0;
    
    array = getData(x, y);    
    printDat(array, x, y);//Print the Matrix    
    cout<<endl;                        
    sum1 = sum(array, x, y);    
    cout<<sum1;    
    destroy(array, x);    
    
    return 0;
}

int **getData(int &x, int &y){
    int **array = nullptr;
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
                if(z == 0){
                    str >> x;
                }
                else{
                    str >> y;
                }
                str.str("");
                str.clear();
                str.seekg(0);    
            }
            z++;
        }
    }
    
    array = new int*[x];
    for(int xx = 0; xx < x; xx++){
        array[xx] = new int[y];
    }
    
    b = ""; 
    str.str("");
    str.clear();
    str.seekg(0);     
    
    for(int z = 0; z < x; z++){                
        std::getline(std::cin,b);
        i = 0;
        for(char & c : b){
            if(c == ' '){

            }
            else
            {
                if(i < y){
                    str << c;
                    str >> array[z][i];
                    str.str("");
                    str.clear();
                    str.seekg(0);   
                    i++;
                }
            }                               
        }
    }        
    
    return array;           
}

void printDat(const int * const * array, int x, int y){    
    for(int z = 0; z < x; z++){
        for(int zz = 0; zz < y; zz++){   
            if(zz == y-1){
                cout<<array[z][zz];            
            }
            else{
                cout<<array[z][zz]<<" ";            
            }
        }
        if(z == x-1){            
        }
        else{
            cout<<endl;
        }
    }
    
}

void destroy(int **array, int x){
    for(int z=0; z < x; z++){
        delete []array[z];
    }
    delete []array;
}

int sum(const int * const * array, int x, int y){    //Return the Sum
    
    int sum1 = 0;    
    for(int z = 0; z < x; z++){
        for(int zz = 0; zz < y; zz++){
            sum1 = sum1 + array[z][zz];
        }
    }
    
    return sum1;
}
//Domenico Venuti 5