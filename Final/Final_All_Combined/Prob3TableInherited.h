#ifndef Prob3TableInherited_H
#define Prob3TableInherited_H

using namespace std;

template<class T>
class Prob3TableInherited :public Prob3Table<T> {
protected:
	T* augTable; //Augmented Table with sums	
public:
	Prob3TableInherited(char*, int, int); //Constructor
	~Prob3TableInherited() { delete[] augTable; }; //Destructor
	const T* getAugTable(void) { return augTable; };
};

template<class T>
Prob3TableInherited<T>::Prob3TableInherited(char* filename, int rows, int cols):Prob3Table<T>(filename, rows, cols) {	
	const int* naugT = this->getTable();
	int r1 = rows + 1;
	int c1 = cols + 1;
	int x = 0;
	int y = 0;
	int z = 0;	
	int h1 = 0;

	augTable = new T[r1 * c1];	
	for (x = 0; x < rows; x++) {		
		for (y = 0; y < cols; y++) {			
			augTable[x * cols + y] = this->table[x * cols + y];
			augTable[x * cols + y] = this->table[x * cols + y];									
		}
		h1 = this->rowSum[x];
                y = 6;
		augTable[x * cols + y] = 0;
	}
	x = rows;
	for (y = 0; y < cols; y++) {
		h1 = this->colSum[y];
		augTable[x * cols + y] = this->colSum[y];
	}
	augTable[rows * cols + cols] = this->grandTotal;
        x = 0;
        y = 6;
        //cout << endl << augTable[x * cols + y];
}

#endif