#include "calculate_and_display_total_tax.h"
void calculateAndDisplayTotalTax(const string& currentUser) {
    loadProperties(currentUser);
    if (propertyCount == 0) {
        cout << "You dont have any property to calculate tax for." << endl;
        return;
    }
    double totalTax = 0;
    for (int i = 0; i < propertyCount; i++) {
        totalTax += processCalculateTax(properties[i]);
    }
    cout << "Total tax for your properties is : " << totalTax << " BYN" << endl;
}