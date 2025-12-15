#ifndef ADMIN_MODULE_H
#define ADMIN_MODULE_H

#include "Database.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class AdminModule {
private:
    Database* db;

public:
    AdminModule(Database* database);
    void showMenu(); // Main admin menu from flowchart
    
    // Admin Module Functions (from flowchart)
    void viewPharmacy();
    void generateHospitalReport();
    void addPatient();
    void patientReceipt();
    
    // Pharmacy View Functions
    void displayPharmacyList();
    void filterPharmacyByCategory();
    void displayPharmacyGraphical();
    
    // Report Generation Functions
    void generateMonthlyReport();
    void generateYearlyReport();
    void displayGraphicalReport();
    
    // Patient Receipt Functions
    void calculatePatientReceipt(int patientId);
    void displayReceipt(int patientId, double totalAmount);
    
    // Helper Functions
    void displayTableHeader(const string& title);
    void pressEnterToContinue();
    int getIntInput(const string& prompt);
    string getStringInput(const string& prompt);
    void displayPharmacyTable(sql::ResultSet* res);
};

#endif
