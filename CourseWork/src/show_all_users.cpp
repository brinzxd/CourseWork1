#include "show_all_users.h"
void showAllUsers() {
    ifstream file(USERS_FILE);
    if (!file) {
        cout << "Error: Failed to open user's list file!" << endl;
        return;
    }
    string username, password;
    cout << "\nList of users:\n";
    while (file >> username >> password) {
        cout << "- " << username << endl;
    }
    file.close();
}