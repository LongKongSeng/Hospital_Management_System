#include "Registration.h"

Registration::Registration(Database* database) : db(database) {}

void Registration::showPreRegistrationMenu() {
    int choice;
    do {
        system("cls");
        displayTableHeader("PRE-REGISTRATION");
        cout << "\n╔════════════════════════════════════════╗" << endl;
        cout << "║  Select Role:                         ║" << endl;
        cout << "║  1. Doctor                            ║" << endl;
        cout << "║  2. Nurse                             ║" << endl;
        cout << "║  3. Admin                             ║" << endl;
        cout << "║  0. Back to Main Menu                 ║" << endl;
        cout << "╚════════════════════════════════════════╝" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            registerDoctor();
            break;
        case 2:
            registerNurse();
            break;
        case 3:
            registerAdmin();
            break;
        case 0:
            return;
        default:
            cout << "\n❌ Invalid choice! Please try again." << endl;
            pressEnterToContinue();
        }
    } while (choice != 0);
}

void Registration::registerDoctor() {
    system("cls");
    displayTableHeader("DOCTOR REGISTRATION");

    string fullName, gender, specialization, contactNumber, password1, password2, username;

    try {
        cout << "\nEnter Full Name: ";
        getline(cin, fullName);
        if (fullName.empty()) {
            cout << "\n❌ Full name cannot be empty!" << endl;
            pressEnterToContinue();
            return;
        }

        cout << "Enter Gender (Male/Female/Other): ";
        getline(cin, gender);
        if (gender.empty()) {
            cout << "\n❌ Gender cannot be empty!" << endl;
            pressEnterToContinue();
            return;
        }

        cout << "Enter Specialization: ";
        getline(cin, specialization);
        if (specialization.empty()) {
            cout << "\n❌ Specialization cannot be empty!" << endl;
            pressEnterToContinue();
            return;
        }

        cout << "Enter Contact Number: ";
        getline(cin, contactNumber);
        if (contactNumber.empty()) {
            cout << "\n❌ Contact number cannot be empty!" << endl;
            pressEnterToContinue();
            return;
        }

        cout << "Create Username: ";
        getline(cin, username);
        if (username.empty()) {
            cout << "\n❌ Username cannot be empty!" << endl;
            pressEnterToContinue();
            return;
        }

        // Check if username exists in login table
        string checkQuery = "SELECT COUNT(*) as count FROM login WHERE username = '" + username + "'";
        sql::ResultSet* checkRes = db->executeSelect(checkQuery);
        if (checkRes && checkRes->next() && checkRes->getInt("count") > 0) {
            cout << "\n❌ Username already exists! Please choose another." << endl;
            if (checkRes) delete checkRes;
            pressEnterToContinue();
            return;
        }
        if (checkRes) delete checkRes;

        cout << "Create Password: ";
        getline(cin, password1);
        if (password1.empty()) {
            cout << "\n❌ Password cannot be empty!" << endl;
            pressEnterToContinue();
            return;
        }

        cout << "Re-enter Password: ";
        getline(cin, password2);

        if (!validatePassword(password1, password2)) {
            cout << "\n❌ Passwords do not match! Please try again." << endl;
            pressEnterToContinue();
            return;
        }

        // Insert into doctor table
        string query = "INSERT INTO doctor (full_name, gender, specialization, contact_number, availability, status, role) "
            "VALUES ('" + fullName + "', '" + gender + "', '" + specialization + "', '" + contactNumber + "', 'Available', 'Active', 'Doctor')";

        if (db->executeUpdate(query)) {
            // Get the doctor_id that was just inserted
            string getIdQuery = "SELECT doctor_id FROM doctor WHERE full_name = '" + fullName + "' AND contact_number = '" + contactNumber + "' ORDER BY doctor_id DESC LIMIT 1";
            sql::ResultSet* idRes = db->executeSelect(getIdQuery);
            int doctorId = -1;
            if (idRes && idRes->next()) {
                doctorId = idRes->getInt("doctor_id");
            }
            if (idRes) delete idRes;

            if (doctorId > 0) {
                // Insert into login table
                string loginQuery = "INSERT INTO login (username, password, role, doctor_id) "
                    "VALUES ('" + username + "', '" + password1 + "', 'Doctor', " + to_string(doctorId) + ")";

                if (db->executeUpdate(loginQuery)) {
                    cout << "\n✅ Doctor registered successfully!" << endl;
                    
                    // Display registered doctor in table format
                    cout << "\n╔════════════════════════════════════════════════════════════════╗" << endl;
                    cout << "║                    REGISTERED DOCTOR DETAILS                  ║" << endl;
                    cout << "╠════════════════════════════════════════════════════════════════╣" << endl;
                    cout << "║ Username: " << left << setw(47) << username << "║" << endl;
                    cout << "║ Full Name: " << left << setw(46) << fullName << "║" << endl;
                    cout << "║ Specialization: " << left << setw(41) << specialization << "║" << endl;
                    cout << "║ Contact Number: " << left << setw(41) << contactNumber << "║" << endl;
                    cout << "╚════════════════════════════════════════════════════════════════╝" << endl;
                } else {
                    cout << "\n⚠️  Doctor created but login failed! Please contact admin." << endl;
                }
            } else {
                cout << "\n❌ Failed to retrieve doctor ID!" << endl;
            }
        } else {
            cout << "\n❌ Failed to register doctor!" << endl;
        }
    }
    catch (exception& e) {
        cout << "\n❌ Error: " << e.what() << endl;
    }

    pressEnterToContinue();
}

void Registration::registerNurse() {
    system("cls");
    displayTableHeader("NURSE REGISTRATION");

    string fullName, gender, contactNumber, password1, password2, username;

    try {
        cout << "\nEnter Full Name: ";
        getline(cin, fullName);
        if (fullName.empty()) {
            cout << "\n❌ Full name cannot be empty!" << endl;
            pressEnterToContinue();
            return;
        }

        cout << "Enter Gender (Male/Female/Other): ";
        getline(cin, gender);
        if (gender.empty()) {
            cout << "\n❌ Gender cannot be empty!" << endl;
            pressEnterToContinue();
            return;
        }

        cout << "Enter Contact Number: ";
        getline(cin, contactNumber);
        if (contactNumber.empty()) {
            cout << "\n❌ Contact number cannot be empty!" << endl;
            pressEnterToContinue();
            return;
        }

        cout << "Create Username: ";
        getline(cin, username);
        if (username.empty()) {
            cout << "\n❌ Username cannot be empty!" << endl;
            pressEnterToContinue();
            return;
        }

        // Check if username exists
        string checkQuery = "SELECT COUNT(*) as count FROM login WHERE username = '" + username + "'";
        sql::ResultSet* checkRes = db->executeSelect(checkQuery);
        if (checkRes && checkRes->next() && checkRes->getInt("count") > 0) {
            cout << "\n❌ Username already exists! Please choose another." << endl;
            if (checkRes) delete checkRes;
            pressEnterToContinue();
            return;
        }
        if (checkRes) delete checkRes;

        cout << "Create Password: ";
        getline(cin, password1);
        if (password1.empty()) {
            cout << "\n❌ Password cannot be empty!" << endl;
            pressEnterToContinue();
            return;
        }

        cout << "Re-enter Password: ";
        getline(cin, password2);

        if (!validatePassword(password1, password2)) {
            cout << "\n❌ Passwords do not match! Please try again." << endl;
            pressEnterToContinue();
            return;
        }

        // Insert into nurse table
        string query = "INSERT INTO nurse (full_name, gender, contact_number, status, role) "
            "VALUES ('" + fullName + "', '" + gender + "', '" + contactNumber + "', 'Active', 'Nurse')";

        if (db->executeUpdate(query)) {
            // Get the nurse_id
            string getIdQuery = "SELECT nurse_id FROM nurse WHERE full_name = '" + fullName + "' AND contact_number = '" + contactNumber + "' ORDER BY nurse_id DESC LIMIT 1";
            sql::ResultSet* idRes = db->executeSelect(getIdQuery);
            int nurseId = -1;
            if (idRes && idRes->next()) {
                nurseId = idRes->getInt("nurse_id");
            }
            if (idRes) delete idRes;

            if (nurseId > 0) {
                // Insert into login table
                string loginQuery = "INSERT INTO login (username, password, role, nurse_id) "
                    "VALUES ('" + username + "', '" + password1 + "', 'Nurse', " + to_string(nurseId) + ")";

                if (db->executeUpdate(loginQuery)) {
                    cout << "\n✅ Nurse registered successfully!" << endl;
                    
                    cout << "\n╔════════════════════════════════════════════════════════════════╗" << endl;
                    cout << "║                    REGISTERED NURSE DETAILS                   ║" << endl;
                    cout << "╠════════════════════════════════════════════════════════════════╣" << endl;
                    cout << "║ Username: " << left << setw(47) << username << "║" << endl;
                    cout << "║ Full Name: " << left << setw(46) << fullName << "║" << endl;
                    cout << "║ Contact Number: " << left << setw(41) << contactNumber << "║" << endl;
                    cout << "╚════════════════════════════════════════════════════════════════╝" << endl;
                } else {
                    cout << "\n⚠️  Nurse created but login failed! Please contact admin." << endl;
                }
            } else {
                cout << "\n❌ Failed to retrieve nurse ID!" << endl;
            }
        } else {
            cout << "\n❌ Failed to register nurse!" << endl;
        }
    }
    catch (exception& e) {
        cout << "\n❌ Error: " << e.what() << endl;
    }

    pressEnterToContinue();
}

void Registration::registerAdmin() {
    system("cls");
    displayTableHeader("ADMIN REGISTRATION");

    string fullName, email, contactNumber, password1, password2, username;

    try {
        cout << "\nEnter Full Name: ";
        getline(cin, fullName);
        if (fullName.empty()) {
            cout << "\n❌ Full name cannot be empty!" << endl;
            pressEnterToContinue();
            return;
        }

        cout << "Enter Email: ";
        getline(cin, email);
        if (email.empty() || email.find('@') == string::npos) {
            cout << "\n❌ Invalid email format!" << endl;
            pressEnterToContinue();
            return;
        }

        cout << "Enter Contact Number: ";
        getline(cin, contactNumber);
        if (contactNumber.empty()) {
            cout << "\n❌ Contact number cannot be empty!" << endl;
            pressEnterToContinue();
            return;
        }

        cout << "Create Username: ";
        getline(cin, username);
        if (username.empty()) {
            cout << "\n❌ Username cannot be empty!" << endl;
            pressEnterToContinue();
            return;
        }

        // Check if username exists
        string checkQuery = "SELECT COUNT(*) as count FROM login WHERE username = '" + username + "'";
        sql::ResultSet* checkRes = db->executeSelect(checkQuery);
        if (checkRes && checkRes->next() && checkRes->getInt("count") > 0) {
            cout << "\n❌ Username already exists! Please choose another." << endl;
            if (checkRes) delete checkRes;
            pressEnterToContinue();
            return;
        }
        if (checkRes) delete checkRes;

        cout << "Create Password: ";
        getline(cin, password1);
        if (password1.empty()) {
            cout << "\n❌ Password cannot be empty!" << endl;
            pressEnterToContinue();
            return;
        }

        cout << "Re-enter Password: ";
        getline(cin, password2);

        if (!validatePassword(password1, password2)) {
            cout << "\n❌ Passwords do not match! Please try again." << endl;
            pressEnterToContinue();
            return;
        }

        // Insert into admin table
        string query = "INSERT INTO admin (full_name, email, contact_number, status, role) "
            "VALUES ('" + fullName + "', '" + email + "', '" + contactNumber + "', 'Active', 'Admin')";

        if (db->executeUpdate(query)) {
            // Get the admin_id
            string getIdQuery = "SELECT admin_id FROM admin WHERE email = '" + email + "' ORDER BY admin_id DESC LIMIT 1";
            sql::ResultSet* idRes = db->executeSelect(getIdQuery);
            int adminId = -1;
            if (idRes && idRes->next()) {
                adminId = idRes->getInt("admin_id");
            }
            if (idRes) delete idRes;

            if (adminId > 0) {
                // Insert into login table
                string loginQuery = "INSERT INTO login (username, password, role, admin_id) "
                    "VALUES ('" + username + "', '" + password1 + "', 'Admin', " + to_string(adminId) + ")";

                if (db->executeUpdate(loginQuery)) {
                    cout << "\n✅ Admin registered successfully!" << endl;
                    
                    cout << "\n╔════════════════════════════════════════════════════════════════╗" << endl;
                    cout << "║                    REGISTERED ADMIN DETAILS                     ║" << endl;
                    cout << "╠════════════════════════════════════════════════════════════════╣" << endl;
                    cout << "║ Username: " << left << setw(47) << username << "║" << endl;
                    cout << "║ Full Name: " << left << setw(46) << fullName << "║" << endl;
                    cout << "║ Email: " << left << setw(50) << email << "║" << endl;
                    cout << "╚════════════════════════════════════════════════════════════════╝" << endl;
                } else {
                    cout << "\n⚠️  Admin created but login failed! Please contact system administrator." << endl;
                }
            } else {
                cout << "\n❌ Failed to retrieve admin ID!" << endl;
            }
        } else {
            cout << "\n❌ Failed to register admin!" << endl;
        }
    }
    catch (exception& e) {
        cout << "\n❌ Error: " << e.what() << endl;
    }

    pressEnterToContinue();
}

bool Registration::validatePassword(const string& password1, const string& password2) {
    return password1 == password2;
}

void Registration::displayTableHeader(const string& title) {
    cout << "\n╔════════════════════════════════════════════════════════════════╗" << endl;
    cout << "║" << setw(60) << "" << "║" << endl;
    cout << "║" << setw((60 - title.length()) / 2 + title.length()) << right << title 
         << setw((60 - title.length()) / 2) << "" << "║" << endl;
    cout << "║" << setw(60) << "" << "║" << endl;
    cout << "╚════════════════════════════════════════════════════════════════╝" << endl;
}

void Registration::pressEnterToContinue() {
    cout << "\nPress Enter to continue...";
    cin.get();
}

string Registration::getStringInput(const string& prompt) {
    cout << prompt;
    string input;
    getline(cin, input);
    return input;
}
