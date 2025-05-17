#pragma once
#include <string>
using namespace std;
enum TypeOfAcom {
    Residential,
    NonResidential
};
struct Property {
    string owner;
    string name;
    double area;
    double ratio;
    TypeOfAcom type;
};