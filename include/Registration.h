#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "Database.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <ctime>

using namespace std;

class Registration {
private:
    Database* db;

public:
    Registration(Database* database);
    void showPreRegistrationMenu(); // Pre-registration menu from flowchart
    void registerDoctor();
    void registerNurse();
    void registerAdmin();
    bool validatePassword(const string& password1, const string& password2);
    void displayTableHeader(const string& title);
    void pressEnterToContinue();
    string getStringInput(const string& prompt);
};

#endif
