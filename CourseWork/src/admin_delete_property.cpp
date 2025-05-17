#include "admin_delete_property.h"
void adminDeleteProperty() {
    string userToDelete;
    cout << "Enter the name of the user, whose property you want to delete: ";
    cin >> userToDelete;
    loadProperties(userToDelete);
    if (propertyCount == 0) {
        cout << "This user dont have any property to delete." << endl;
        return;
    }
    string name;
    cout << "Enter name of the property you want to delete: ";
    cin >> name;
    int indexToDelete = -1;
    for (int i = 0; i < propertyCount; i++) {
        if (properties[i].name == name) {
            indexToDelete = i;
            break;
        }
    }
    if (indexToDelete == -1) {
        cout << "Error: Property with such name wasnt found!" << endl;
        return;
    }
    Property* newProperties = new Property[propertyCount - 1];
    for (int i = 0, j = 0; i < propertyCount; i++) {
        if (i != indexToDelete) {
            newProperties[j++] = properties[i];
        }
    }
    delete[] properties;
    properties = newProperties;
    propertyCount--;
    ofstream propertyFile(PROPERTY_FILE);
    if (!propertyFile) {
        cout << "Error: Failed to open property list file!" << endl;
        return;
    }
    for (int i = 0; i < propertyCount; i++) {
        //file << properties[i].owner << " " << properties[i].name << " "
        //    << properties[i].area << " " << properties[i].ratio << " " << properties[i].type << endl;
        ReadPropFile(i, propertyFile);
    }
    propertyFile.close();
    cout << "The property of user \"" << userToDelete << "\" was successfully deleted!" << endl;
}