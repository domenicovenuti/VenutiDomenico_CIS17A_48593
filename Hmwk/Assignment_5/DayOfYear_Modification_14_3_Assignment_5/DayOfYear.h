#include <iostream>
#include <string>
using namespace std;

class DayOfYear
{
private:
	int day;
	static string months[];
	static int monthInt[];
	static int days[];

public:
	DayOfYear(int);
	DayOfYear(string, int);
	void print();
};

string DayOfYear::months[] = { "January", "February", "March", "April", "May", "June", "July", "August","September","October", "November", "December" };
int DayOfYear::monthInt[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
int DayOfYear::days[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,	11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
							21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 };

DayOfYear::DayOfYear(int date)
{
	if (date < 0 || date > 365)
	{
		cout << "Wrong Input..." << endl;
	}
	else
	{
		day = date;
	}
}
DayOfYear::DayOfYear(string monthName, int date)
{

	day = date;
}

void DayOfYear::print()
{
	if (day >= 1 && day <= 31)
	{
		cout << months[0] << " " << day << endl; 
	}
	else if (day >= 32 && day <= 60)
	{
		cout << months[1] << " " << day - 31 << endl;
	}
	else if (day >= 61 && day <= 82)
	{
		cout << months[2] << " " << day - 60 << endl;
	}
	else if (day >= 83 && day <= 113)
	{
		cout << months[3] << " " << day - 82 << endl; 
	}
	else if (day >= 114 && day <= 145)
	{
		cout << months[4] << " " << day - 113 << endl;
	}
	else if (day >= 146 && day <= 176)
	{
		cout << months[5] << " " << day - 145 << endl;
	}
	else if (day >= 177 && day <= 208)
	{
		cout << months[6] << " " << day - 176 << endl;
	}
	else if (day >= 209 && day <= 240)
	{
		cout << months[7] << " " << day - 208 << endl;
	}
	else if (day >= 241 && day <= 271)
	{
		cout << months[8] << " " << day - 240 << endl; 
	}
	else if (day >= 271 && day <= 302)
	{
		cout << months[9] << " " << day - 270 << endl;
	}
	else if (day >= 303 && day <= 333)
	{
		cout << months[10] << " " << day - 302 << endl;
	}
	else if (day >= 334 && day <= 365)
	{
		cout << months[11] << " " << (day == 365 ? day - 334 : day - 333) << endl;
	}
}