#include "ReadPropFile.h"
void ReadPropFile(int i, ofstream& propertyFile) {
	propertyFile << properties[i].owner << " " << properties[i].name << " "
		<< properties[i].area << " " << properties[i].ratio << " " << properties[i].type << endl;
}
