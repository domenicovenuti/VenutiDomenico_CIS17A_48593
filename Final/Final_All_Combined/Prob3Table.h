#ifndef Prob3Table_H
#define Prob3Table_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

template<class T>
class Prob3Table {
protected:
	int rows; //Number of rows in the table
	int cols; //Number of cols in the table
	T* rowSum; //RowSum array
	T* colSum; //ColSum array
	T* table; //Table array
	T grandTotal; //Grand total
	void calcTable(void); //Calculate all the sums
public:
	Prob3Table(char*, int, int); //Constructor then Destructor
	~Prob3Table() { delete[] table; delete[] rowSum; delete[] colSum; };
	const T* getTable(void) { return table; };
	const T* getRowSum(void) { return rowSum; };
	const T* getColSum(void) { return colSum; };
	T getGrandTotal(void) { return grandTotal; };
};

template <class T>
Prob3Table<T>::Prob3Table(char* filename, int rows, int cols) {
    vector<int> pos;
    int x = 0;
    int y = 0;
    string line;
    ifstream infile;
    stringstream ss;
    int control = 0;
    int value = 0;
    int size = 0;
    this->rows = rows;
    this->cols = cols;
    rowSum = new T[rows];
    colSum = new T[cols];    
    int row1 = 0;
    int cols1 = 0;

    infile.open(filename, ios::in);

    if (infile.is_open()) {
        while (getline(infile, line)) {
            y = 0;
            row1 = 0;
            for (char& c : line) {

                if (c >= 48 && c <= 57) {
                    ss << c;
                    control = 1;
                }
                else if (control == 1 && c == ' ') {
                    ss >> value;
                    pos.push_back(value);
                    grandTotal = grandTotal + value;
                    row1 = row1 + value;
                    ss.str("");
                    ss.clear();
                    ss.seekg(0);
                    control = 0;
                    y++;
                }
                else if (c == '\n') {
                    ss.str("");
                    ss.clear();
                    ss.seekg(0);
                    control = 0;
                }
                else {

                }
            }
            ss >> value;
            pos.push_back(value);
            grandTotal = grandTotal + value;
            row1 = row1 + value;
            rowSum[x] = row1;
            ss.str("");
            ss.clear();
            ss.seekg(0);
            control = 0;
            x++;
        }        
        table = new T[rows * cols];        
        for (int i = 0; i < rows; i++) {            
            for (int z = 0; z < cols; z++) {              
                table[i * cols + z] = pos.at(size);                
                size++;
            }            
        }      
    }        
    for (int y = 0; y < cols; y++) {     
        for (int x = 0; x < rows; x++) {                                 
            cols1 = cols1 + table[x * cols + y];
        }
        colSum[y] = cols1;        
        cols1 = 0;
    }
}

#endif