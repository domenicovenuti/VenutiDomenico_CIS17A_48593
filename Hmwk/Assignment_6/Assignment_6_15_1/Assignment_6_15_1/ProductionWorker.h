#include <string>
#include "Employee.h"

using namespace std;

class ProductionWorker:public Employee {
private:
	int shift;
	double hourlyPayRate;
public:
	void setShift(int shift);
	void setHourlyPayRate(double hourlyPayRate);
	int getShift() const;
	double getHourlyPayRate() const;
	ProductionWorker() {
		employeeName = "";
		employeeNumber = 0;
		hireDate = "";
		shift = 1;
		hourlyPayRate = 0.00;
	}
};

void ProductionWorker::setShift(int shift) {
	this->shift = shift;
}
void ProductionWorker::setHourlyPayRate(double hourlyPayRate) {
	this->hourlyPayRate = hourlyPayRate;
}
int ProductionWorker::getShift() const {
	return shift;
}
double ProductionWorker::getHourlyPayRate() const {
	return hourlyPayRate;
}


