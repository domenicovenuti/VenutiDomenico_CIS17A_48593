#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Employee {
public:    
    Employee(string, string, float); //Constructor
    float CalculatePay(float, int); //Procedure
    float getGrossPay(float, int); //Procedure
    float getNetPay(float); //Procedure
    void toString(); //Procedure
    int setHoursWorked(int); //Procedure
    float setHourlyRate(float); //Procedure
    void setHours(int);
    void setHourly(float);
    void setGrossPay(float);
    void setNetPay(float);
private:
    double Tax(float); //Utility Procedure    
    string MyName; //Property
    string JobTitle; //Property
    float HourlyRate; //Property
    int HoursWorked; //Property
    float GrossPay; //Property
    float NetPay; //Property
};

Employee::Employee(string MyName1, string JobTitle1, float hr) {
    int size = 20;
    float hr1 = 0.00;
    int hw = 0;
    hr1 = 
    HourlyRate = setHourlyRate(hr);
    HoursWorked = 0;
    GrossPay = 0.00;
    NetPay = 0.00;
    MyName = MyName1;
    JobTitle = JobTitle1;
}
double Employee::Tax(float GrossPay) {
    double tax1 = 0.00;    
    double h2 = 0.00;

    if (GrossPay <= 500) {
        tax1 = 0.10 * GrossPay;
    }
    else if (GrossPay > 500 && GrossPay <= 1000) {
        h2 = GrossPay - 500;
        tax1 = 0.20 * h2 + 0.10 * h2;
    }
    else {
        h2 = GrossPay - 1000;        
        tax1 = 0.30 * h2 + 0.20 * 500 + 0.10 * 500;        
    }
    return tax1;
}
float Employee::CalculatePay(float a, int b) {    
    return getNetPay(getGrossPay(setHourlyRate(a), setHoursWorked(b)));;
}
float Employee::getGrossPay(float HourlyRate1, int HoursWorked1) {
    float gross1 = 0.00;
    if (HoursWorked1 <= 40) {
        gross1 = 1 * HourlyRate1 * HoursWorked1;
    }
    else if (HoursWorked1 > 40 && HoursWorked1 <= 50) {
        gross1 = 1.5 * HourlyRate1 * HoursWorked1;
    }
    else {
        gross1 = 2 * HourlyRate1 * HoursWorked1;
    }
    setGrossPay(gross1);
    return GrossPay;
}
float Employee::getNetPay(float gp) {
    float net1 = gp - Tax(gp);
    setNetPay(net1);
    return NetPay;
}
void Employee::setNetPay(float net1) {
    NetPay = net1;
}
void Employee::setGrossPay(float gross1) {
    GrossPay = gross1;
}
void Employee::toString() {
    cout << "Name = " << MyName << " Job Title = " << JobTitle << endl << " Hourly Rate = " << HourlyRate << " Hours Worked = " << HoursWorked << " Gross Pay = " << GrossPay << " Net Pay = " << NetPay << endl;
}
int Employee::setHoursWorked(int hw) {
    if (hw > 0 && hw <= 84) {
        setHours(hw);
    }
    else {
        setHours(0);
        cout << "Unacceptable Hours Worked" << endl;
    }
    return HoursWorked;
}
float Employee::setHourlyRate(float hr) {
    if (hr > 0 && hr <= 200) {
        setHourly(hr);
    }
    else {
        setHourly(0.00);
        cout << "Unacceptable Hourly Rate" << endl;
    }
    return HourlyRate;
}
void Employee::setHours(int hw) {
    HoursWorked = hw;
}

void Employee::setHourly(float hr) {
    HourlyRate = hr;
}

#endif /* EMPLOYEE_H */