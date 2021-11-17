#include<iostream>
#include<string>

using namespace std;

class NumDays
{
	double workhours;
	double days;
public:
	void setWorkHours(double workhours)
	{
		this->workhours = workhours;
		if (this->workhours >= 8)
			this->days = this->workhours / 8.0;
	}	
	void setDays(double days) { this->setWorkHours(days * 8); }	
	double getHours() const { return workhours; }	
	double getNumofDays() const { return days; }	
	NumDays(int workhours) { setWorkHours(workhours); }
	NumDays() { setWorkHours(0); }	
	NumDays(const NumDays& obj)
	{
		setWorkHours(obj.getHours());
		setDays(obj.getHours());
	}	
	~NumDays() {}	
	double operator + (const NumDays& obj) const
	{
		return this->getHours() + (this->getNumofDays() * 8) + (obj.getNumofDays() * 8) + obj.getHours();
	}	
	double operator - (const NumDays& obj) const
	{
		double hours;
		hours = this->getHours() + (this->getNumofDays() * 8) - (obj.getNumofDays() * 8) + obj.getHours();
		return hours < 0 ? hours * -1 : hours;
	}	
	NumDays operator ++ ()
	{
		this->setWorkHours(this->getHours() + 1);
		return *this;
	}	
	NumDays operator ++ (int)
	{
		NumDays temp(*this);
		this->setWorkHours(this->getHours() + 1);
		return temp;
	}	
	NumDays operator -- ()
	{
		this->setWorkHours(this->getHours() - 1);
		return *this;
	}	
	NumDays operator -- (int)
	{
		NumDays temp(*this);
		this->setWorkHours(this->getHours() - 1);
		return temp;
	}
};
