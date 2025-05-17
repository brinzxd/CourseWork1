#include "show_properties.h"
void showProperties(const string& currentUser) {
    loadProperties(currentUser);
    if (propertyCount == 0) {
        return;
    }
    cout << "\nProperty list of user " << currentUser << ":\n";
    for (int i = 0; i < propertyCount; i++) {
        cout << "\n----------------------------\n";
        cout << "Name: " << properties[i].name << endl;
        cout << "Area: " << properties[i].area << " sq.m." << endl;
        cout << "Price of 1 sq.m.: " << properties[i].ratio << " BYN" << endl;
        cout << "Accommodation type: " << (properties[i].type == Residential ? "Residential" : "Non-residential") << endl;
        cout << "Tax: " << processCalculateTax(properties[i]) << " BYN" << endl;
        cout << "----------------------------\n";
    }
}