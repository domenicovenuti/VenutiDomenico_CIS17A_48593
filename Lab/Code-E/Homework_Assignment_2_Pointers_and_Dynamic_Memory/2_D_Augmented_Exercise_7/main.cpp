/* 
 * File: main.cpp
 * Author: Domenico Venuti 
 * Created on September 29, 2021, 1:43 PM
 */

#include <iostream>
#include <string>
#include<string.h>
#include <sstream>

using namespace std;

int **getData(int &,int &);//Get the Matrix Data
void printDat(const int * const *,int,int);//Print the Matrix
int **augment(const int * const *,int,int);//Augment the original array
void destroy(int **,int);//Destroy the Matrix, i.e., reallocate memory

int main(){
    
    //My Code    
    int **array = nullptr; //Pointer intiliaze as nullptr
    int **array2 = nullptr;
    int x = 0;
    int y = 0;           
    
    array = getData(x, y);
    
    printDat(array, x, y);//Print the Matrix
    
    cout<<endl;
    
    array2 = augment(array, x + 1, y + 1);//Augment the original array    
    
    destroy(array, x);
    
    printDat(array2, x + 1, y + 1);//Print the Matrix
    
    destroy(array2, x + 1);
    
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

int **augment(const int * const * array, int x, int y){
    
    int **temp = nullptr;
    temp = new int*[x];
    for(int xx = 0; xx < x; xx++){
        temp[xx] = new int[y];
    }
    
    for(int z = 0; z < x; z++){
        for(int zz = 0; zz < y; zz++){
            if(z == 0 || zz == 0){
                temp[z][zz] = 0;
            }
            else{
                temp[z][zz] = array[z-1][zz-1];
            }
        }
    }            
    
    return temp;
}

void destroy(int **array, int x){
    for(int z=0; z < x; z++){
        delete []array[z];
    }
    delete []array;
}
//Domenico Venuti