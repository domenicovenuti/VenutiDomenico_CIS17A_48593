#include <string>

#ifndef HEADER_H
#define HEADER_H

using namespace std;

class Employee {
protected:
	string employeeName;
	int employeeNumber;
	string hireDate;
public:
	void setEmployeeName(string);
	void setEmployeeNumber(int);
	void setHireDate(string);
	string getEmployeeName();
	int getEmployeeNumber() const;
	string getEmployeeHireDate();
	Employee() {
		employeeName = "";
		employeeNumber = 0;
		hireDate = "";
	}
};

void Employee::setEmployeeName(string employeeName) {
	this->employeeName = employeeName;
}
void Employee::setEmployeeNumber(int employeeNumber) {
	this->employeeNumber = employeeNumber;
}
void Employee::setHireDate(string hireDate) {
	this->hireDate = hireDate;
}
string Employee::getEmployeeName() {
	return employeeName;
}
int Employee::getEmployeeNumber() const{
	return employeeNumber;
}
string Employee::getEmployeeHireDate() {
	return hireDate;
}

#endif