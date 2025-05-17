#include "delete_user.h"

 using namespace std;

void deleteUser() {
    string userToDelete;
    cout << "Enter the name of the user,who you want to delete: ";
    cin >> userToDelete;
    ifstream file(USERS_FILE);
    if (!file) {
        cout << "Error: Failed to open property list file!" << endl;
        return;
    }
    ofstream tempFile("temp_users.txt");
    if (!tempFile) {
        cout << "Error: Failed to create temporary file!" << endl;
        file.close();
        return;
    }
    string username, password;
    bool found = false;

    while (file >> username >> password) {
        if (username != userToDelete) {
            tempFile << username << " " << password << endl;
        }
        else {
            found = true;
        }
    }
    file.close();
    tempFile.close();
    remove(USERS_FILE.c_str());
    rename("temp_users.txt", USERS_FILE.c_str());
    if (found) {
        cout << "User \"" << userToDelete << "\" was successfully deleted!" << endl;
        loadProperties(userToDelete);
        propertyCount = 0;
        ofstream propertyFile(PROPERTY_FILE);
        if (!propertyFile) {
            cout << "Error: Failed to open property list file!" << endl;
            return;
        }
        for (int i = 0; i < propertyCount; i++) {
            if (properties[i].owner != userToDelete) {
                /*propertyFile << properties[i].owner << " " << properties[i].name << " "
                    << properties[i].area << " " << properties[i].ratio << " " << properties[i].type << endl;*/
                ReadPropFile(i, propertyFile);
            }
        }
        propertyFile.close();
    }
    else {
        cout << "Error: User wasnt found!" << endl;
    }
}