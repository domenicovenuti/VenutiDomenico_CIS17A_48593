#include <string>
#ifndef READFKEYBOARD_H
#define READFKEYBOARD_H

//TEMPLATE CLASS
template <class T>
class ReadFromKeyboard {
private:
	string data1;	//ANY TYPE OF DATA
	int data2;	//ANY TYPE OF DATA
	int control;
public:
	class ThrowExceptionDouble{
	public:
		ThrowExceptionDouble() {

		}
	};
	ReadFromKeyboard(string);
	ReadFromKeyboard(int);
	void setInt(int);
	void setString(string);
	void setDouble(double);
	string getString();
	int getInt();
};

//METHODS
template <class T>
ReadFromKeyboard<T>::ReadFromKeyboard(string data) {
	data1 = data;
	data2 = 0;
	control = 0;
}
template <class T>
ReadFromKeyboard<T>::ReadFromKeyboard(int data) {
	data2 = data;
	data1 = "";
	control = 1;
}
template <class T>
void ReadFromKeyboard<T>::setInt(int data) {
	data2 = data;
	control = 1;
}
template <class T>
void ReadFromKeyboard<T>::setString(string data) {
	data1 = data;
	control = 0;
}
template <class T>
void ReadFromKeyboard<T>::setDouble(double data) {
	control = 3;
	//throw ThrowExceptionDouble();
}
template <class T>
string ReadFromKeyboard<T>::getString() {
	if (control == 0) {
		return data1;
	}
	else {
		throw ThrowExceptionDouble();
		return "";
	}
}
template <class T>
int ReadFromKeyboard<T>::getInt() {
	if (control == 1) {
		return data2;
	}
	else {
		throw ThrowExceptionDouble();
		return 0;
	}
}
#endif // !READFKEYBOARD_H