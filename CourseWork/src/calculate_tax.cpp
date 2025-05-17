#include "calculate_tax.h"
void calculateTax(const string& currentUser) {
    loadProperties(currentUser);
    if (propertyCount == 0) {
        cout << "You dont have any property to calculate tax for." << endl;
        return;
    }
    string name;
    cout << "Enter the name of property: ";
    cin >> name;
    for (int i = 0; i < propertyCount; i++) {
        if (properties[i].name == name) {
            cout << "Tax for " << name << ": " << processCalculateTax(properties[i]) << " BYN" << endl;
            return;
        }
    }
    cout << "Property with this name wasn't found." << endl;
}



