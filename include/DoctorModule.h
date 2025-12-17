#ifndef DOCTOR_MODULE_H
#define DOCTOR_MODULE_H

#include "Database.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class DoctorModule {
private:
    Database* db;
    int currentDoctorId;

public:
    DoctorModule(Database* database, int doctorId);
    void showMenu(); // Main doctor menu from flowchart
    
    // Doctor Module Functions (from flowchart)
    void viewPatientRecord();
    void generateNextAppointment();
    void makeDiagnosis();
    void editPatientMedicalRecord();
    
    // Helper Functions
    void displayTableHeader(const string& title);
    void pressEnterToContinue();
    int getIntInput(const string& prompt);
    string getStringInput(const string& prompt);
    void displayPatientRecordTable(sql::ResultSet* res);
    void displayMedicalRecordTable(sql::ResultSet* res);
};

#endif



