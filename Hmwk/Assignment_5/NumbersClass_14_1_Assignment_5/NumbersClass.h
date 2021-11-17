#include <iostream>
#include <string>

using namespace std;

class NumbersClass
{
private:
	int number;
	static string lessThan20[];	
	static string hundred;
	static string tenths[];
	static string thousand;

public:
	NumbersClass(int num1) {
		if (num1 >= 0 || num1 <= 9999)
		{
			number = num1;
		}
		else
		{
			cout << "Number can't be less than 0 or greater that 9999" << endl;

		}
	}
	void print() {
		bool control1;
		int h;
		int l;
		int m;
		int l2;
		int tenth[] = { 20, 30, 40, 50, 60, 70, 80, 90, 100 };
		int hundreth[] = { 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000 };
		int i = 0;
		int i2 = 0;
		int i3 = 0;
		int thousands[] = { 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000 };
		if (number < 20)
		{
			cout << "The Number Translated is: " << lessThan20[number] << endl;
		}
		else if (number >= 20 && number < 100)
		{						
			do
			{
				control1 = false;
				if (number >= tenth[i])
				{
					h = tenth[i];
					control1 = true;
					i++;
				}
			} while (control1);
			l = number - h;
			cout << "The number Translated is: " << tenths[i - 1] << " " << (l > 0 ? lessThan20[l] : "") << endl;
		}
		else if (number >= 100 && number < 1000)
		{
			h = 0;
			l = 0;
			m = 0;
			i = 0;
			i2 = 0;			
			do
			{
				control1 = false;
				if (number >= hundreth[i])
				{
					h = hundreth[i];
					control1 = true;
					i++;
				}
			} while (control1);
			m = number - h;
			if (m != 0)
			{
				do
				{
					control1 = false;
					if (m >= tenth[i2])
					{
						l = tenth[i2];
						control1 = true;
						i2++;
					}
				} while (control1);

				l = number - h - l;
			}
			cout << "The number Translated is: " << lessThan20[i] << " " << hundred << " " << (m > 0 ? tenths[i2 - 1] : "") << " " << (l > 0 ? lessThan20[l] : "") << endl;
		}
		else if (number >= 1000 && number <= 9999)
		{			
			h = 0;
			l = 0;
			m = 0;
			i = 0;
			i2 = 0;
			i3 = 0;
			l2 = 0;
			do
			{
				control1 = false;

				if (number >= thousands[i])
				{
					h = thousands[i];
					control1 = true;
					i++;
				}
			} while (control1);
			m = number - h;
			if (m != 0)
			{
				do
				{
					control1 = false;
					if (m >= hundreth[i2])
					{
						l = hundreth[i2];
						control1 = true;
						i2++;
					}
				} while (control1);
				m = l;
				l = number - (h + l);
				if (l != 0)
				{
					do
					{
						control1 = false;

						if (l >= tenth[i3])
						{
							l2 = tenth[i3];
							control1 = true;
							i3++;
						}


					} while (control1);
					l2 = number - (h + m + l2);
				}
			}
			cout << "The number Translate is: " << lessThan20[i] << " " << thousand << " " << (m > 0 ? lessThan20[i2] : "") << " " << (m > 0 ? hundred : "") << " " << (l > 0 ? tenths[i3 - 1] : "") << " " << (l2 > 0 ? lessThan20[l2] : "") << endl;
		}
	}

};

string NumbersClass::lessThan20[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
string NumbersClass::tenths[] = { "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
string NumbersClass::hundred = "hundred";
string NumbersClass::thousand = "thousand";