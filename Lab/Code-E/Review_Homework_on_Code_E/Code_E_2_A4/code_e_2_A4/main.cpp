/* 
 * File:   main.cpp
 * Author: DOMENICO VENUTI
 * Created on 09/19/2021
 * Purpose:  Sorting a 2-D array of characters if row and columns match
 */

//COMMENTS: THIS WAS COMPILED AND TESTED IN NETBEANS, VISUAL STUDIO AND ECLIPSE AND WORKED PROPERLY, NEVER WORKED IN CODE-E

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int);//Sort by row
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    
    //Input the size of the array you are sorting
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size            
    if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    }else{
        if(rowDet!=rowIn)
        cout<<(rowDet<rowIn?"Row Input size less than specified.":
            "Row Input size greater than specified.")<<endl;
        if(colDet!=colIn)
        cout<<(colDet<colIn?"Column Input size less than specified.":
            "Column Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}
 
int read(char array[][COLMAX], int & rowDet){
    int size = 0;
    string readT = "";
    int y = 0;
    int x = 0;
    for(x = 0; x < rowDet; x++){
        y=0;
        readT = "";        
        cin>>readT;
        if(readT.length()>size){
           size = readT.length();
        }
        for(char & c : readT){
            array[x][y] = c;            
            y++;
        }
    }
    return size;
}

void sort(char array[][COLMAX], int rowIn, int colIn){
    int control = 0;
    char c;
    int x = 0;
    int y = 0;
    int z = 0;    
    while(control == 0){
        control = 1;
        int y = 0;
        for(x = 0;x < rowIn-1;x++){           
            if(strcmp(array[x],array[x+1])>0){
                for(z=0;z<colIn;z++){
                    c = array[x][z];
                    array[x][z]=array[x+1][z];
                    array[x+1][z]=c;                                                                        
                }
                control = 0;
            }                                        
        }        
    }
}

void print(const char array[][COLMAX], int rowIn, int colIn){
    char ar[colIn] = "";
    for(int x = 0; x < rowIn; x++){        
        strcpy(ar,array[x]);
        cout<<ar<<endl;
    }
}
