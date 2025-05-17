#include "register_user.h"
using namespace std;
bool registerUser() {
    string username, password, existingUser;
    unsigned long long existingPassHash;
    cout << "Enter your login: ";
    cin >> username;
    if (username == ADMIN_USERNAME) {
        cout << "Error: You can't create user with login 'admin'!" << endl;
        return false;
    }
    ifstream file(USERS_FILE);
    if (file) {
        while (file >> existingUser >> existingPassHash) {
            if (existingUser == username) {
                cout << "Error: user already exists!" << endl;
                file.close();
                return false;
            }
        }
        file.close();
    }
    cout << "Enter password: ";
    cin >> password;
    unsigned long long passwordHash = hashPassword(password); 
    ofstream outFile(USERS_FILE, ios::app);
    if (!outFile) {
        cout << "Error: Failed to open the file!" << endl;
        return false;
    }
    outFile << username << " " << passwordHash << endl;
    outFile.close();
    cout << "Registration succeeded!" << endl;
    return true;
}