/* 
 * File: main.cpp
 * Author: Domenico Venuti
 * Created on November 16, 2021 at 7:12 PM
 * Purpose: Personal Information Class - Exercise 13.4 - Assignment 5
 */

#include <iostream>
#include <string>

using namespace std;

class PersonData {
private:
    string name;
    string address;
    int age;
    string phone;
public:
    PersonData();
    void setName(string);
    void setAddress(string);
    void setAge(int);
    void setPhone(string);
    string getName() const;
    string getAddress() const;
    string getPhone() const;
    int getAge() const;
};
PersonData::PersonData() {
    name = "";
    address = "";
    age = 0;
    phone = "";
}

void PersonData::setName(string name1) {
    name = name1;
}

void PersonData::setAddress(string address1) {
    address = address1;
}

void PersonData::setAge(int age1) {
    age = age1;
}

void PersonData::setPhone(string phone1) {
    phone = phone1;
}

string PersonData::getName() const {
    return name;
}

string PersonData::getAddress() const {
    return address;
}

string PersonData::getPhone() const {
    return phone;
}

int PersonData::getAge() const {
    return age;
}

int main(int argc, char** argv) {
    string line = "";
    int howmany = 0;
    int familys = 0;
    PersonData me;
    PersonData *friends;
    PersonData *family;

    cout << "Insert Your Info Please:" << endl;
    cout << "Name -> ";
    getline(cin, line);
    me.setName(line);    
    cin.clear();
    line = "";
    cout << "Address -> ";
    getline(cin, line);
    me.setAddress(line);
    cin.clear();
    line = "";
    cout << "Age -> ";
    getline(cin, line);
    me.setAge(stoi(line));
    cin.clear();
    line = "";
    cout << "Phone Number -> ";
    getline(cin, line);
    me.setPhone(line);
    cin.clear();
    line = "";
    cout << endl << "How Many Friends Do you want to Save?: ";
    getline(cin, line);
    howmany = stoi(line);
    friends = new PersonData[howmany];
    cin.clear();
    line = "";    
    for (int x = 0; x < howmany; x++) {
        cout << endl << "Insert your Friend#" << x + 1 << " Info:" << endl;
        cout << "Name -> ";
        getline(cin, line);
        friends[x].setName(line);
        cin.clear();
        line = "";
        cout << "Address -> ";
        getline(cin, line);
        friends[x].setAddress(line);
        cin.clear();
        line = "";
        cout << "Age -> ";
        getline(cin, line);
        friends[x].setAge(stoi(line));
        cin.clear();
        line = "";
        cout << "Phone Number -> ";
        getline(cin, line);
        friends[x].setPhone(line);
        cin.clear();
        line = "";        
    }
    cout << endl << "How Many Family Members Do you want to Save?: ";
    getline(cin, line);
    familys = stoi(line);
    family = new PersonData[familys];
    cin.clear();
    line = "";
    for (int x = 0; x < familys; x++) {
        cout << endl << "Insert your Family Member#" << x + 1 << " Info:" << endl;
        cout << "Name -> ";
        getline(cin, line);
        family[x].setName(line);
        cin.clear();
        line = "";
        cout << "Address -> ";
        getline(cin, line);
        family[x].setAddress(line);
        cin.clear();
        line = "";
        cout << "Age -> ";
        getline(cin, line);
        family[x].setAge(stoi(line));
        cin.clear();
        line = "";
        cout << "Phone Number -> ";
        getline(cin, line);
        family[x].setPhone(line);
        cin.clear();
        line = "";
    }
    cout << endl << "Printing all Info Inserted...." << endl;
    cout << endl << "My Info:" << endl;
    cout << "Name: " << me.getName() << endl;
    cout << "Address: " << me.getAddress() << endl;
    cout << "Age: " << me.getAge() << endl;
    cout << "Phone: " << me.getPhone() << endl;
    cout << endl;
    for (int x = 0; x < howmany; x++) {
        cout << endl << "Friends Info:" << endl;
        cout << "Name: " << friends[x].getName() << endl;
        cout << "Address: " << friends[x].getAddress() << endl;
        cout << "Age: " << friends[x].getAge() << endl;
        cout << "Phone: " << friends[x].getPhone() << endl;
    }
    cout << endl;
    for (int x = 0; x < familys; x++) {
        cout << endl << "Family Info:" << endl;
        cout << "Name: " << family[x].getName() << endl;
        cout << "Address: " << family[x].getAddress() << endl;
        cout << "Age: " << family[x].getAge() << endl;
        cout << "Phone: " << family[x].getPhone() << endl;
    }    
    return 0;
}

