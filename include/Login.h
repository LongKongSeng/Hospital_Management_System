#ifndef LOGIN_H
#define LOGIN_H

#include "Database.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Login {
private:
    Database* db;
    int currentUserId;
    string currentUserType;
    string currentUsername;
    string currentRole; // Doctor, Nurse, or Admin

public:
    Login(Database* database);
    bool authenticate(const string& username, const string& password);
    void showLoginMenu();
    int getCurrentUserId();
    string getCurrentUserType();
    string getCurrentUsername();
    string getCurrentRole();
    void logout();
    void displayTableHeader(const string& title);
};

#endif
