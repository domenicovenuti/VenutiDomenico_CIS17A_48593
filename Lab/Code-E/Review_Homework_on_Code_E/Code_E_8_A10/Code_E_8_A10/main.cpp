/* 
 * File:   main.cpp
 * Author: DOMENICO VENUTI
 * Created on 09/20/2021
 * Note:  This time you create the strcmp() function that takes into
 * account the new sort order.
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
#include <string>
#include <algorithm>
using namespace std;

//COMMENTS: THIS WAS COMPILED AND TESTED IN NETBEANS, VISUAL STUDIO AND ECLIPSE AND WORKED PROPERLY, NEVER WORKED IN CODE-E

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int,const char[],const char[]);//Sort by row using strcmp();
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array
//int strcmp(char a[],char b[],char replace[],char with[]){
int strcmp(char [], char [], const char [], const char []);//Replace sort order

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    char replace[COLMAX],with[COLMAX];//New sort order
    
    //Input the new sort order then sort
    cout<<"Modify the sort order by swapping these characters."<<endl;
    cin>>replace;
    cout<<"With the following characters"<<endl;
    cin>>with;
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
    //if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn,replace,with);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    
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

void sort(char array[][COLMAX], int rowIn, int colIn, const char replace[], const char with[]){
    int control = 0;
    char c;
    int x = 0;
    int y = 0;
    int z = 0;    
    int strcmpn = 0;
    char a[colIn] = "";
    char b[colIn] = "";    
    while(control == 0){
        control = 1;
        int y = 0;
        for(x = 0;x < rowIn-1;x++){           
            strcpy(a,array[x]);
            strcpy(b,array[x+1]);
            strcmpn = strcmp(a,b,replace,with);
            if(strcmpn>0){
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

int strcmp(char a[], char b[], const char replace[], const char with[]){
    int compare = 0;
    string aa = a;
    string bb = b;
    string rp = replace;
    string wp = with;
    
    string aas = aa;
    string bbs = bb;
    
    const int y = rp.length();
    const int aay = bb.length();
    
    char aaa[aay];
    char bbb[aay];
    
    strcpy(aaa,aas.c_str());
    strcpy(bbb,bbs.c_str());        
    
    int o1 = 0;
    int o2 = 0;
    
    for(int x = 0; x < aay; x++){
        for(int g = 0; g < y; g++){
            if(aaa[x]!=replace[g] ){
                
            }
            else{
                if(o1==0){
                    aaa[x] = with[g];
                    o1=1;
                }
            }
            if(bbb[x]!=replace[g] ){
                
            }
            else{
                if(o2==0){
                    bbb[x] = with[g];
                    o2=1;
                }
            }
        }
        o1=0;
        o2=0;
    }
    
    for(int z = 0; z < aay; z++){
        if(compare == 0){
            if(aaa[z]>bbb[z]){
                compare = 1;
            }
            else if(aaa[z]<bbb[z]){
                compare = -1;
            }
            else{
                compare = 0;
            }
        }
    }
            
    return compare;
}