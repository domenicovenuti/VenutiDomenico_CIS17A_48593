/*
 * File: main.cpp
 * Author: Domenico Venuti
 * Created on October 7, 2021 at 7:12 PM
 * Purpose: Chapter 11 Problem 9
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <stdlib.h>
#include<windows.h>
#include <sstream>

using namespace std;

const int MAX_SIZE = 10;

struct SpeakerBureau {
    string name;
    string telephone;
    string topic;
    float fee;
};

bool setName(SpeakerBureau[], string, int[]);
bool setTelephone(SpeakerBureau[], string, int[]);
bool setTopic(SpeakerBureau[], string, int[]);
bool setFee(SpeakerBureau[], string, int[]);
int showMainMenu(SpeakerBureau[], int[]);
void showSubMenu1(SpeakerBureau[], int[]);
void showSubMenu2(SpeakerBureau[], int[]);
void showSubMenu3(SpeakerBureau[], int[]);
void showSubMenu4(SpeakerBureau[], int[]);
void showSubMenu5(SpeakerBureau[], int[]);
int searchSpeaker(SpeakerBureau[], string);
void listSpeakers(SpeakerBureau[], int[]);
void deleteSpeaker(SpeakerBureau[], int[]);
void printSpeaker(SpeakerBureau[], int[], int);
void listFields(SpeakerBureau[], int[]);
void editSpeaker(SpeakerBureau[], int[], int);

int main(int argc, char** argv) {

    SpeakerBureau bureau[10];
    int position[] = { 0,0 };  //0 = CURRENT POSITION, 1 = LAST POSITION.
    int control1 = 0;

    while (control1 == 0) {
        control1 = showMainMenu(bureau, position);
    }

    return 0;
}

//PUT DATA
bool setName(SpeakerBureau bureau[], string data, int position[]) {
    bool result = true;    

    if (data.length() > 0) {
        bureau[position[0]].name = data;
    }
    else {
        result = false;
    }

    return result;
}

bool setTelephone(SpeakerBureau bureau[], string data, int position[]) {
    bool result = true;
    int phone;
    int control = 0;

    try {
        for (char c : data) {
            if (control == 0) {
                if (c == ' ') {

                }
                else {
                    phone = c;
                    if (phone >= 48 && phone <= 57) {

                    }
                    else {
                        control = 1;
                        result = false;
                    }
                }
            }
        }
    }
    catch (exception) {
        result = false;
    }

    if (data.length() > 0) {
        bureau[position[0]].telephone = data;
    }
    else {
        result = false;
    }

    return result;
}

bool setTopic(SpeakerBureau bureau[], string data, int position[]) {
    bool result = true;
    if (data.length() > 0) {
        bureau[position[0]].topic = data;
    }
    else {
        result = false;
    }

    return result;
}

bool setFee(SpeakerBureau bureau[], string data, int position[]) {
    std::stringstream ss;
    bool result = true;
    int control = 0;
    int phone = 0;
    int count = 0;
    int dotfound = 0;
    float value = 0.00;
    int len = data.length();
    int dotpos = 0;
    int x = 0;
    bool dot = true;

    if (len > 0) {

        try {

            for (char c : data) {
                if (control == 0) {
                    if (c == ' ') {

                    }
                    else {
                        phone = c;

                        if (phone == 46) {
                            dotfound++;
                            dotpos = x;
                        }

                        if ((phone >= 48 && phone <= 57) || phone == 46) {
                            x++;
                        }
                        else {
                            control = 1;
                            result = false;
                        }
                    }
                }
            }

            if (dotfound == 0) {
                //dotpos = 1;
                dot = true;
            }           
            else {
                if (dotfound < 2 && dotpos > 0 && dotpos < len) {
                    dot = true;
                }
                else {
                    dot = false;
                }
            }

            if (result == true && dot == true) {

                ss.str(data);

                ss >> value;

                if (value >= 0) {
                    bureau[position[0]].fee = value;
                }
                else {
                    result = false;
                }
            }
            else {
                result = false;
            }

        }
        catch (exception) {
            result = false;
        }
    }
    else {
        result = false;
    }

    return result;
}

//MAIN MENU
int showMainMenu(SpeakerBureau bureau[], int position[]) {
    int option = 0;
    string opttext = "";
    bool control = false;
    int control1 = 0;

    cout << "********************************************" << endl;
    cout << "*                Chapter 11                *" << endl;
    cout << "*                Problem 09                *" << endl;
    cout << "*             Speaker's Bureau             *" << endl;
    cout << "*            By: Domenico Venuti           *" << endl;
    cout << "********************************************" << endl;
    cout << endl;
    cout << endl;
    cout << "********************************************" << endl;
    cout << "* ------------- Menu Options ------------- *" << endl;
    cout << "********************************************" << endl;
    cout << endl;
    cout << "1. Add a New Speaker." << endl;
    cout << "2. Edit a Speaker." << endl;
    cout << "3. Delete a Speaker." << endl;
    cout << "4. Print all Info about a Speaker." << endl;
    cout << "5. Print only a Field from a Speaker." << endl;
    cout << "6. Exit Program." << endl;
    cout << endl;
    cout << "********************************************" << endl;

    while (!control) {
        try {
            cout << "-> ";
            control = true;
            getline(cin, opttext);
            option = stoi(opttext);
        }
        catch (exception) {
            control = false;
            cout << "Wrong Option... Please, Try Again.";
            cout << endl;
        }
    }

    switch (option) {
        case 1:
            cout << endl;
            cout << "******************" << endl;
            cout << "*  Add New Menu  *" << endl;
            showSubMenu1(bureau, position);
            break;
        case 2:            
            if (position[1] == 0) {
                cout << "--------------------------------------------" << endl;
                cout << "No Speaker were Added yet. Please, Wait..." << endl;
                cout << "--------------------------------------------" << endl;
                Sleep(2000);
                system("CLS");
                control = 0;
            }
            else {
                cout << endl;
                cout << "******************" << endl;
                cout << "*    Edit Menu   *" << endl;
                showSubMenu2(bureau, position);
            }
            break;
        case 3:
            if (position[1] == 0) {
                cout << "--------------------------------------------" << endl;
                cout << "No Speaker were Added yet. Please, Wait..." << endl;
                cout << "--------------------------------------------" << endl;                
                Sleep(2000);
                system("CLS");
                control = 0;
            }
            else{
                cout << endl;
                cout << "******************" << endl;
                cout << "*  Delete Menu   *" << endl;
                showSubMenu3(bureau, position);
            }
            break;
        case 4:
            cout << endl;
            cout << "**********************" << endl;
            cout << "* Print Speaker Menu *" << endl;
            showSubMenu4(bureau, position);
            break;
        case 5:
            cout << endl;
            cout << "*********************************" << endl;
            cout << "*  Print Speaker's Field Menu   *" << endl;
            showSubMenu5(bureau, position);
            break;
        case 0:
            cout << endl;
            cout << "--------------------------------------------" << endl;
            cout << "Bye Bye..." << endl;
            cout << "--------------------------------------------" << endl;
            control1 = 1;
            break;
        default:
            control1 = 0;
            cout << "Wrong Option... Try Again... Please, Wait...";
            Sleep(2000);
            system("CLS");
    }

    return control1;
}

//SUB-MENUS
void showSubMenu1(SpeakerBureau bureau[], int position[]) {
    string datatext = "";
    float datanumber = 0.00;
    bool control = false;
    int duplicate = 666;
    string errormessage;
    position[0] = position[1];

    while (!control) {
        cout << "********************************************" << endl;        
        cout << "Insert Speaker's Name: ";
        getline(cin, datatext);
        
        duplicate = searchSpeaker(bureau, datatext);
        
        if (duplicate == 666) {
            errormessage = "Error Inserting Name. Can't be Empty. Please, try again...";
            control = setName(bureau, datatext, position);
        }
        else {
            errormessage = "Error Inserting Name. Can't be a Duplicate. Please, try again...";
        }

        if (!control) {
            cout << "--------------------------------------------" << endl;
            cout << errormessage << endl;
            cout << "--------------------------------------------" << endl;
        }
    }

    control = false;

    while (!control) {
        cout << "--------------------------------------------" << endl;
        cout << "Insert Telephone Number (e.g. 9514076934):";
        getline(cin, datatext);
        control = setTelephone(bureau, datatext, position);
        if (!control) {
            cout << "--------------------------------------------" << endl;
            cout << "Error Inserting Telephone, Can't be Empty and Only Numbers are Allowed... Please, try again..." << endl;
            cout << "--------------------------------------------" << endl;
        }
    }

    control = false;

    while (!control) {
        cout << "--------------------------------------------" << endl;
        cout << "Insert Topic:";
        getline(cin, datatext);
        control = setTopic(bureau, datatext, position);
        if (!control) {
            cout << "--------------------------------------------" << endl;
            cout << "Error Inserting Topic, Please, try again..." << endl;
            cout << "--------------------------------------------" << endl;
        }
    }

    control = false;

    while (!control) {
        cout << "--------------------------------------------" << endl;
        cout << "Insert Fee Value(U$D):";
        getline(cin, datatext);
        control = setFee(bureau, datatext, position);
        if (!control) {
            cout << "--------------------------------------------" << endl;
            cout << "Fee Can't be Negative or Empty, only Numbers are Allowed, Please, try again..." << endl;
            cout << "--------------------------------------------" << endl;
        }
    }

    cout << endl;
    cout << "New Speaker Saved Successfully. Please, Wait...";
    Sleep(2000);
    system("CLS");

    position[1]++;
    position[0] = position[1];

}

void showSubMenu2(SpeakerBureau bureau[], int position[]) {
    string datatext = "";
    float datanumber = 0.00;
    int option, option2;
    bool control = false;
    int exit = 1;

    listSpeakers(bureau, position);

    while (!control) {
        try {
            cout << "-> ";
            control = true;
            getline(cin, datatext);
            option = stoi(datatext);
            if (option <= position[1]) {
                if (option == 0) {
                    exit = 0;
                }
            }
            else {
                control = false;
                cout << "--------------------------------------------" << endl;
                cout << "Wrong Option... Please, Try Again.";
                cout << "--------------------------------------------" << endl;
                cout << endl;
            }
        }
        catch (exception) {
            control = false;
            cout << "--------------------------------------------" << endl;
            cout << "Wrong Option... Please, Try Again.";
            cout << "--------------------------------------------" << endl;
            cout << endl;
        }
    }

    control = false;

    cout << endl;
    listFields(bureau, position);

    while (!control) {
        try {
            cout << "-> ";
            control = true;
            getline(cin, datatext);
            option2 = stoi(datatext);
            if (option2 <= 4) {
                if (option2 == 0) {
                    exit = 0;
                }
            }
            else {
                control = false;
                cout << "--------------------------------------------" << endl;
                cout << "Wrong Option... Please, Try Again.";
                cout << "--------------------------------------------" << endl;
                cout << endl;
            }
        }
        catch (exception) {
            control = false;
            cout << "--------------------------------------------" << endl;
            cout << "Wrong Option... Please, Try Again.";
            cout << "--------------------------------------------" << endl;
            cout << endl;
        }
    }

    if (exit == 1) {
        position[0] = option - 1;
        editSpeaker(bureau, position, option2);
    }
}

void showSubMenu3(SpeakerBureau bureau[], int position[]) {
    string datatext = "";
    float datanumber = 0.00;
    int option;
    bool control = false;
    int exit = 1;

    listSpeakers(bureau, position);

    while (!control) {
        try {
            cout << "-> ";
            control = true;
            getline(cin, datatext);
            option = stoi(datatext);
            if (option <= position[1]) {
                if (option == 0) {
                    exit = 0;
                }
            }
            else {
                control = false;
                cout << "--------------------------------------------" << endl;
                cout << "Wrong Option... Please, Try Again.";
                cout << "--------------------------------------------" << endl;
                cout << endl;
            }
        }
        catch (exception) {
            control = false;
            cout << "--------------------------------------------" << endl;
            cout << "Wrong Option... Please, Try Again.";
            cout << "--------------------------------------------" << endl;
            cout << endl;
        }
    }

    control = false;

    if (exit == 1) {

        cout << "--------------------------------------------" << endl;
        cout << "Are you Sure you want to Delete Speaker #" << option << "?...(Y/N)..." << endl;
        cout << "--------------------------------------------" << endl;

        while (!control) {
            try {
                cout << "-> ";
                getline(cin, datatext);
                if (datatext == "y" || datatext == "n" || datatext == "Y" || datatext == "N") {
                    control = true;
                    position[0] = option - 1;
                    deleteSpeaker(bureau, position);
                }
                else {
                    control = false;
                    cout << "--------------------------------------------" << endl;
                    cout << "Wrong Option... Please, use only Y or N... Try Again.";
                    cout << "--------------------------------------------" << endl;
                    cout << endl;
                }
            }
            catch (exception) {
                control = false;
                cout << "--------------------------------------------" << endl;
                cout << "Wrong Option... Please, use only Y or N... Try Again.";
                cout << "--------------------------------------------" << endl;
                cout << endl;
            }
        }
        
    }
    else {
        system("CLS");        
    }
            
}

void showSubMenu4(SpeakerBureau bureau[], int position[]) {
    string datatext = "";
    float datanumber = 0.00;
    int option;
    bool control = false;
    int exit = 1;

    listSpeakers(bureau, position);

    while (!control) {
        try {
            cout << "-> ";
            control = true;
            getline(cin, datatext);
            option = stoi(datatext);
            if (option <= position[1]) {
                if (option == 0) {
                    exit = 0;
                }
            }
            else {
                control = false;
                cout << "--------------------------------------------" << endl;
                cout << "Wrong Option... Please, Try Again.";
                cout << "--------------------------------------------" << endl;
                cout << endl;
            }
        }
        catch (exception) {
            control = false;
            cout << "--------------------------------------------" << endl;
            cout << "Wrong Option... Please, Try Again.";
            cout << "--------------------------------------------" << endl;
            cout << endl;
        }
    }

    control = false;        

    if (exit == 1) {
        position[0] = option - 1;
        printSpeaker(bureau, position, 0);
    }    

}

void showSubMenu5(SpeakerBureau bureau[], int position[]) {
    string datatext = "";
    float datanumber = 0.00;
    int option, option2;
    bool control = false;
    int exit = 1;

    listSpeakers(bureau, position);

    while (!control) {
        try {
            cout << "-> ";
            control = true;
            getline(cin, datatext);
            option = stoi(datatext);
            if (option <= position[1]) {
                if (option == 0) {
                    exit = 0;
                }
            }
            else {
                control = false;
                cout << "--------------------------------------------" << endl;
                cout << "Wrong Option... Please, Try Again.";
                cout << "--------------------------------------------" << endl;
                cout << endl;
            }
        }
        catch (exception) {
            control = false;
            cout << "--------------------------------------------" << endl;
            cout << "Wrong Option... Please, Try Again.";
            cout << "--------------------------------------------" << endl;
            cout << endl;
        }
    }

    control = false;

    cout << endl;
    listFields(bureau, position);

    while (!control) {
        try {
            cout << "-> ";
            control = true;
            getline(cin, datatext);
            option2 = stoi(datatext);
            if (option2 <= 4) {
                if (option2 == 0) {
                    exit = 0;
                }
            }
            else {
                control = false;
                cout << "--------------------------------------------" << endl;
                cout << "Wrong Option... Please, Try Again.";
                cout << "--------------------------------------------" << endl;
                cout << endl;
            }
        }
        catch (exception) {
            control = false;
            cout << "--------------------------------------------" << endl;
            cout << "Wrong Option... Please, Try Again.";
            cout << "--------------------------------------------" << endl;
            cout << endl;
        }
    }

    if (exit == 1) {
        position[0] = option - 1;
        printSpeaker(bureau, position, option2);
    }
}

int searchSpeaker(SpeakerBureau bureau[], string data) {
    int result = 666;

    if(data.length() > 0) {

        for (int x = 0; x < MAX_SIZE; x++) {
            if (bureau[x].name == data) {
                result = x;
            }
        }
    }

    return result;
}

void listSpeakers(SpeakerBureau bureau[], int position[]) {
    
    cout << "********************************************" << endl;
    cout << "* ----------- Choose a Speaker ----------- *" << endl;
    cout << "********************************************" << endl;
    cout << endl;
    for (int x = 0; x < position[1]; x++) {
        cout << "\t" << x + 1 << ". " << bureau[x].name << endl;
    }
    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << "\t" << "0" << ". " << "Back." << endl;
    cout << "********************************************" << endl;
}

void listFields(SpeakerBureau bureau[], int position[]) {

    cout << "********************************************" << endl;
    cout << "* ----------- Choose a Field   ----------- *" << endl;
    cout << "********************************************" << endl;
    cout << endl;
    cout << "1. Speaker's Name." << endl;
    cout << "2. Speaker's Telephone Number." << endl;
    cout << "3. Speaker's Topic." << endl;
    cout << "4. Speaker's Fee Value(U$D)." << endl;
    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << "\t" << "0" << ". " << "Back." << endl;    
    cout << "********************************************" << endl;
}

void deleteSpeaker(SpeakerBureau bureau[], int position[]) {
    
    int x = position[0];
    string name = bureau[position[0]].name;
    SpeakerBureau bureau2;

    bureau[position[0]].name = "";
    bureau[position[0]].telephone = "";
    bureau[position[0]].topic = "";
    bureau[position[0]].fee = 0.00;

    for (x = position[0]; x < position[1]; x++) {
        bureau2 = bureau[x + 1];
        bureau[x + 1] = bureau[x];
        bureau[x] = bureau2;
    }

    position[1]--;
    cout << endl;
    cout << "Speaker " << name << " was Deleted Successfully... Please, Wait..." << endl;    
    Sleep(2000);
    system("CLS");
}

void printSpeaker(SpeakerBureau bureau[], int position[], int field) {    
    cout << "********************************************" << endl;
    cout << endl;
    if (field == 0) {        
        cout << "            Name: " << bureau[position[0]].name << endl;
        cout << "Telephone Number: " << bureau[position[0]].telephone << endl;
        cout << "           Topic: " << bureau[position[0]].topic << endl;
        cout << "  Fee Value(U$D): " << bureau[position[0]].fee << endl;        
        cout << endl;
    }
    else {        
        switch (field)
        {
        case 1:
            cout << "Name: " << bureau[position[0]].name << endl;
            break;
        case 2:
            cout << "Telephone Number: " << bureau[position[0]].telephone << endl;
            break;
        case 3:
            cout << "Topic: " << bureau[position[0]].topic << endl;
            break;
        case 4:
            cout << "Fee Value(U$D): " << bureau[position[0]].fee << endl;
            break;
        default:
            break;
        }
        cout << endl;
    }
    cout << "********************************************" << endl;
    cout << "Press any Key to Continue..." << endl;
    cin.ignore();
    system("CLS");
}

void editSpeaker(SpeakerBureau bureau[], int position[], int field) {
    string datatext = "";
    float datanumber = 0.00;
    bool control = false;
    int duplicate = 666;
    string errormessage;

    if (field == 1) {
        while (!control) {
            cout << "********************************************" << endl;
            cout << "Current Speaker's Name: " << bureau[position[0]].name << ", Insert the New Name:";
            getline(cin, datatext);

            duplicate = searchSpeaker(bureau, datatext);

            if (duplicate == 666) {
                errormessage = "Error Updating Name. Can't be Empty. Please, try again...";
                control = setName(bureau, datatext, position);
            }
            else {
                errormessage = "Error Updating Name. Can't be a Duplicate. Please, try again...";
            }

            if (!control) {
                cout << "--------------------------------------------" << endl;
                cout << errormessage << endl;
                cout << "--------------------------------------------" << endl;
            }
        }
    }

    control = false;

    if (field == 2) {
        while (!control) {
            cout << "--------------------------------------------" << endl;
            cout << "Current Speaker's Telephone Number: " << bureau[position[0]].telephone << ", Insert the New Telephone Number (e.g. 9514076934):";
            getline(cin, datatext);
            control = setTelephone(bureau, datatext, position);
            if (!control) {
                cout << "--------------------------------------------" << endl;
                cout << "Error Updating Telephone, Can't be Empty and Only Numbers are Allowed... Please, try again..." << endl;
                cout << "--------------------------------------------" << endl;
            }
        }
    }

    control = false;

    if (field == 3) {
        while (!control) {
            cout << "--------------------------------------------" << endl;
            cout << "Current Speaker's Topic: " << bureau[position[0]].topic << ", Insert the New Topic:";
            getline(cin, datatext);
            control = setTopic(bureau, datatext, position);
            if (!control) {
                cout << "--------------------------------------------" << endl;
                cout << "Error Updating Topic, Please, try again..." << endl;
                cout << "--------------------------------------------" << endl;
            }
        }
    }

    control = false;

    if (field == 4) {
        while (!control) {
            cout << "--------------------------------------------" << endl;
            cout << "Current Speaker's Fee Value: " << bureau[position[0]].fee << ", Insert the New Fee Value(U$D):";
            getline(cin, datatext);
            control = setFee(bureau, datatext, position);
            if (!control) {
                cout << "--------------------------------------------" << endl;
                cout << "Fee Can't be Negative or Empty, only Numbers are Allowed, Please, try again..." << endl;
                cout << "--------------------------------------------" << endl;
            }
        }
    }

    cout << endl;
    cout << "Speaker Updated Successfully.Please, Wait...";
    Sleep(2000);
    system("CLS");    
 
}