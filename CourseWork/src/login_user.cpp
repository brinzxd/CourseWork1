#include "login_user.h"
using namespace std;
bool loginUser(string& currentUser) {
    string username, storedUser;
    string password;
    unsigned long long storedPasswordHash;
    cout << "Enter user's login: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    unsigned long long passwordHash = hashPassword(password);
    ifstream file(USERS_FILE);
    if (!file) {
        cout << "Error: Failed to open user's list file " << endl;
        return false;
    }
    while (file >> storedUser >> storedPasswordHash) {
        if (storedUser == username && storedPasswordHash == passwordHash) {
            currentUser = username;
            cout << "Authorization !" << endl;
            file.close();
            return true;
        }
    }
    cout << "Error: invalid credentials!" << endl;
    file.close();
    return false;
}