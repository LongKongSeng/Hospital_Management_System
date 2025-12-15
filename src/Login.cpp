#include "Login.h"

Login::Login(Database* database) : db(database), currentUserId(-1), currentUserType(""), currentUsername(""), currentRole("") {}

bool Login::authenticate(const string& username, const string& password) {
    try {
        // Query the login table which has username, password, and role
        string query = "SELECT login_id, username, role, doctor_id, nurse_id, admin_id FROM login "
                      "WHERE username = '" + username + "' AND password = '" + password + "'";
        
        sql::ResultSet* res = db->executeSelect(query);
        
        if (res && res->next()) {
            currentUsername = res->getString("username");
            currentRole = res->getString("role");
            
            // Determine user type and ID based on role
            if (currentRole == "Doctor") {
                currentUserType = "doctor";
                currentUserId = res->getInt("doctor_id");
            } else if (currentRole == "Nurse") {
                currentUserType = "nurse";
                currentUserId = res->getInt("nurse_id");
            } else if (currentRole == "Admin") {
                currentUserType = "admin";
                currentUserId = res->getInt("admin_id");
            }
            
            delete res;
            return currentUserId > 0;
        }
        
        if (res) delete res;
        return false;
    }
    catch (exception& e) {
        cout << "\n❌ Authentication Error: " << e.what() << endl;
        return false;
    }
}

void Login::showLoginMenu() {
    system("cls");
    displayTableHeader("LOGIN");
    
    string username, password;

    cout << "\nEnter Username: ";
    getline(cin, username);
    
    if (username.empty()) {
        cout << "\n❌ Username cannot be empty!" << endl;
        cout << "Press Enter to continue...";
        cin.get();
        return;
    }

    cout << "Enter Password: ";
    getline(cin, password);
    
    if (password.empty()) {
        cout << "\n❌ Password cannot be empty!" << endl;
        cout << "Press Enter to continue...";
        cin.get();
        return;
    }

    if (authenticate(username, password)) {
        cout << "\n✅ Login successful! Welcome, " << currentUsername << "!" << endl;
        cout << "Role: " << currentRole << endl;
        cout << "Press Enter to continue...";
        cin.get();
    } else {
        cout << "\n❌ Invalid username or password!" << endl;
        cout << "Press Enter to continue...";
        cin.get();
    }
}

int Login::getCurrentUserId() {
    return currentUserId;
}

string Login::getCurrentUserType() {
    return currentUserType;
}

string Login::getCurrentUsername() {
    return currentUsername;
}

string Login::getCurrentRole() {
    return currentRole;
}

void Login::logout() {
    currentUserId = -1;
    currentUserType = "";
    currentUsername = "";
    currentRole = "";
}

void Login::displayTableHeader(const string& title) {
    cout << "\n╔════════════════════════════════════════════════════════════════╗" << endl;
    cout << "║" << setw(60) << "" << "║" << endl;
    cout << "║" << setw((60 - title.length()) / 2 + title.length()) << right << title 
         << setw((60 - title.length()) / 2) << "" << "║" << endl;
    cout << "║" << setw(60) << "" << "║" << endl;
    cout << "╚════════════════════════════════════════════════════════════════╝" << endl;
}
