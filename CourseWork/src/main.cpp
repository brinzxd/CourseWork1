#include "general.h"
using namespace std;
int main() {
    ensureAdminExists();
    string currentUser;
    int choice;
    do {
        cout << "\n1. sign up\n2. sign in\n3. Exit\nChoose option: ";
        cin >> choice;
        switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            if (loginUser(currentUser)) {
                if (currentUser == ADMIN_USERNAME) {
                    int adminChoice;
                    do {
                        cout << "\n*** Administrator menu ***\n"
                            << "1) Show all users\n"
                            << "2) Delete user's property\n"
                            << "3) Delete user\n"
                            << "4) Back to menu\n"
                            << "Choose action: ";
                        cin >> adminChoice;
                        switch (adminChoice) {
                        case 1: showAllUsers(); break;
                        case 2: adminDeleteProperty(); break;
                        case 3: deleteUser(); break;
                        case 4: cout << "Back to menu." << endl; break;
                        default: cout << "Error: Invalid input!" << endl;
                        }
                    } while (adminChoice != 4);
                }
                else {
                    int action;
                    do {
                        cout << "\n1) Add property\n2) Show property list\n"
                            << "3) Calculate tax for all property\n4) Calculate tax for one property\n"
                            << "5) Delete one property\n6) Exit\nChoose action: ";
                        cin >> action;
                        switch (action) {
                        case 1: addProperty(currentUser); break;
                        case 2: showProperties(currentUser); break;
                        case 3: calculateAndDisplayTotalTax(currentUser); break;
                        case 4: calculateTax(currentUser); break;
                        case 5: deleteProperty(currentUser); break;
                        case 6: cout << "Back to menu." << endl; break;
                        default: cout << "Error: Invalid input!" << endl;
                        }
                    } while (action != 6);
                }
            }
            break;
        case 3:
            cout << "Exit." << endl;
            break;
        default:
            cout << "Error: Invalid input!" << endl;
            break;
        }
    } while (choice != 3);

    delete[] properties;
    return 0;
}