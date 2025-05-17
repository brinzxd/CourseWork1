#include "ensureAdminExists.h"
using namespace std;
void ensureAdminExists() {
    ifstream file(USERS_FILE);
    string username;
    unsigned long long passwordHash;
    bool adminExists = false;
    if (file) {
        while (file >> username >> passwordHash) {
            if (username == ADMIN_USERNAME) {
                adminExists = true;
                break;
            }
        }
        file.close();
    }
    if (!adminExists) {
        unsigned long long adminHash = hashPassword(ADMIN_PASSWORD);
        ofstream outFile(USERS_FILE, ios::app);
        if (outFile) {
            outFile << ADMIN_USERNAME << " " << adminHash << endl;
            outFile.close();
            cout << "Administrator account with login " << ADMIN_USERNAME << " was created." << endl;
        }
        else {
            cout << "Error: Failed to create administrator account!" << endl;
        }
    }
}