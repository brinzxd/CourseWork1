#include "load_properties.h"
void loadProperties(const string& currentUser) {
    ifstream file(PROPERTY_FILE);
    if (!file) {
        cout << "Error: Failed to open property list file!" << endl;
        return;
    }
    propertyCount = 0;
    delete[] properties;
    properties = nullptr;
    Property temp;
    int typeValue;
    while (file >> temp.owner >> temp.name >> temp.area >> temp.ratio >> typeValue) {
        temp.type = static_cast<TypeOfAcom>(typeValue);
        if (temp.owner == currentUser) {
            Property* newProperties = new Property[propertyCount + 1];
            for (int i = 0; i < propertyCount; i++) {
                newProperties[i] = properties[i];
            }
            newProperties[propertyCount] = temp;
            delete[] properties;
            properties = newProperties;
            propertyCount++;
        }
    }
    file.close();
}