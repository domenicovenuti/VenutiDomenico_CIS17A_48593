/* 
 * File: main.cpp
 * Author: Domenico Venuti
 * Created on October 5, 2021 at 7:03 PM
 * Purpose: Structure Movie Data - Exercise 6 - Code-E
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include <iomanip>
#include <vector>

//Global Constants - No Global Variables

//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Structures
struct MovieData{    
    string title;
    string director;
    int yearreleased;
    int runningtime;
};

//Function Prototypes
void getData(MovieData[], int);
void displayMovies(MovieData[], int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    int how;          
    
    //Process or map Inputs to Outputs  
    cout<<"This program reviews structures"<<endl;
    cout<<"Input how many movies, the Title of the Movie, Director, Year Released, and the Running Time in (minutes)."<<endl;
    
    cin>>how;
    MovieData movies[how];
    getData(movies, how);
        
    displayMovies(movies, how);
    
    //Exit stage right!
    return 0;
}

void displayMovies(MovieData movie[], int x){
    for(int y = 0; y < x; y++){
        cout<<endl;
        cout<<"Title:     "<<movie[y].title<<endl;
        cout<<"Director:  "<<movie[y].director<<endl;
        cout<<"Year:      "<<movie[y].yearreleased<<endl;
        cout<<"Length:    "<<movie[y].runningtime<<endl;
    }
}

void getData(MovieData movie[], int x){
    string text1;
    int numbers1;  
    cin.ignore();
        
    for(int i = 0; i< x; i++){                        
        getline(cin,text1);        
        movie[i].title = text1;        
        getline(cin,text1);
        movie[i].director = text1;        
        cin>>numbers1;
        movie[i].yearreleased = numbers1;        
        cin>>numbers1;
        movie[i].runningtime = numbers1;
        cin.ignore();                
    }
}

