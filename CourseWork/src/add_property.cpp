#include "add_property.h"
void addProperty(const string& currentUser) {
    Property newProperty;
    newProperty.owner = currentUser;
    cout << "Enter property name: ";
    cin >> newProperty.name;
    cout << "Enter area (sq.m.): ";
    cin >> newProperty.area;
    cout << "Enter price for one sq.m.(BYN) ";
    cin >> newProperty.ratio;
    int typeChoice;
    cout << "Choose type (0 - Residential, 1 - Non-residential): ";
    cin >> typeChoice;
    if (typeChoice != 0 && typeChoice != 1) {
        cout << "Error: invalid type of accommodation!" << endl;
        return;
    }
    newProperty.type = static_cast<TypeOfAcom>(typeChoice);
    ofstream file(PROPERTY_FILE, ios::app);
    if (!file) {
        cout << "Error: Failed to open property list file!" << endl;
        return;
    }
    file << newProperty.owner << " " << newProperty.name << " "
        << newProperty.area << " " << newProperty.ratio << " " << newProperty.type << endl;
    file.close();
    Property* newProperties = new Property[propertyCount + 1];
    for (int i = 0; i < propertyCount; i++) {
        newProperties[i] = properties[i];
    }
    newProperties[propertyCount] = newProperty;
    delete[] properties;
    properties = newProperties;
    propertyCount++;
    cout << "Property successfully added!" << endl;
}