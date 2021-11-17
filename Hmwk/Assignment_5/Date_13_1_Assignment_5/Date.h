#include <string>

using namespace std;

class Date {
private:
	int month;
	int day;
	int year;		
public:
	void setMonth(int);
	void setDay(int);
	void setYear(int);
	int getDay() const;
	int getYear() const;
	int getMonthN() const;
	string getMonthT() const;
	string getDateN() const;
	string getDateT1() const;
	string getDateT2() const;
	Date();	
};

Date::Date() {	//CONSTRUCTOR
	month = 1;
	day = 1;
	year = 1900;
}

//SET DATA FUNCTIONS
void Date::setMonth(int month1) {
	month = month1;
}

void Date::setDay(int day1) {
	day = day1;
}

void Date::setYear(int year1) {
	year = year1;
}

//GET DATA FUNCTIONS
int Date::getDay() const {
	return day;
}

int Date::getYear() const {
	return year;
}

int Date::getMonthN() const {
	return month;
}

string Date::getMonthT() const {
	string montht = "";
	switch (month)
	{
	case 2:
		montht = "February";
		break;
	case 3:
		montht = "March";
		break;
	case 4:
		montht = "April";
		break;
	case 5:
		montht = "May";
		break;
	case 6:
		montht = "June";
		break;
	case 7:
		montht = "July";
		break;
	case 8:
		montht = "August";
		break;
	case 9:
		montht = "September";
		break;
	case 10:
		montht = "October";
		break;
	case 11:
		montht = "November";
		break;
	default:
		montht = "January";
		break;
	}
	return montht;
}

string Date::getDateN() const {
	string date1 = to_string(month) + "/" + to_string(day) + "/" + to_string(year);
	return date1;
}

string Date::getDateT1() const {
	string date1 = getMonthT() + " " + to_string(day) + ", " + to_string(year);
	return date1;
}

string Date::getDateT2() const {
	string date1 = to_string(day) + " " + getMonthT() + " " + to_string(year);
	return date1;
}