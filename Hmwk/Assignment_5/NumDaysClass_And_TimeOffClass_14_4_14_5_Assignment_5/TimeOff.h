#include<iostream>
#include<string>

using namespace std;

class TimeOff
{
	string name;
	int id;
	NumDays maxSickDays;
	NumDays sickTaken;
	NumDays maxVacation;
	NumDays	vacTaken;
	NumDays maxUnpaid;
	NumDays	unpaidTaken;
public:
	TimeOff()
	{
		this->name = "\0";
		this->id = 0;
	}
	TimeOff(double months, string name, int id, double sickTaken1, double vacTaken1, double maxUnpaid1, double unpaidTaken1)
	{
		this->name = name;
		this->id = id;
		maxSickDays.setWorkHours(months * 8);
		maxVacation.setWorkHours(months * 12);
		setSickTaken(sickTaken1);
		setVacTaken(vacTaken1);
		setMaxUnpaid(maxUnpaid1);
		setUnpaidTaken(unpaidTaken1);

	}	
	TimeOff(string empName, int id, double maxSickDays1, double sickTaken1, double maxVacation1, double vacTaken1, double maxUnpaid1, double unpaidTaken1)
	{
		this->name = empName;
		this->id = id;
		this->maxSickDays.setDays(maxSickDays1);
		this->sickTaken.setDays(sickTaken1);
		setMaxVacation(maxVacation1);
		vacTaken.setDays(vacTaken1);
		maxUnpaid.setDays(maxUnpaid1);
		unpaidTaken.setDays(unpaidTaken1);
	}	
	void setName(string name) { this->name = name; }	
	string getName()const { return name; }	
	void setID(int id) { this->id = id; }	
	int getID()const { return id; }	
	void setMaxSickDays(double maxSickDays) { this->maxSickDays.setDays(maxSickDays); }	
	void setSickTaken(double sickTaken) { this->sickTaken.setDays(sickTaken); }	
	void setMaxVacation(double maxVacation)
	{
		(maxVacation > 30) ? this->maxVacation.setDays(30) : this->maxVacation.setDays(maxVacation);
	}	
	void setVacTaken(double vacTaken) { this->vacTaken.setDays(vacTaken); }	
	void setMaxUnpaid(double maxUnpaid) { this->maxUnpaid.setDays(maxUnpaid); }	
	void setUnpaidTaken(double unpaidTaken) { this->unpaidTaken.setDays(unpaidTaken); }	
	NumDays getMaxSickDays()const { return maxSickDays; }	
	NumDays getSickTaken()const { return sickTaken; }	
	NumDays getMaxVacation()const { return maxVacation; }	
	NumDays getVacTaken()const { return vacTaken; }	
	NumDays getMaxUnpaid()const { return maxUnpaid; }	
	NumDays getUnpaidTaken()const { return unpaidTaken; }	
	void display()
	{
		cout << "Enployee Full Name: " << name;
		cout << " \t Employee #: " << id << endl;
		cout << "Maximum Days of Sick Leave: " << maxSickDays.getNumofDays() << endl;
		cout << "Number of Sick Leave Days Already Taken: " << sickTaken.getNumofDays() << endl;
		cout << "Maximum Days of Paid Vacation: " << maxVacation.getNumofDays() << endl;
		cout << "Number of Paid Vacation Days Already Taken: " << vacTaken.getNumofDays() << endl;
		cout << "Maximum Days of Unpaid Vacation: " << maxUnpaid.getNumofDays() << endl;
		cout << "The Unpaid Leave Days Already taken: " << unpaidTaken.getNumofDays() << endl;

	}
};

