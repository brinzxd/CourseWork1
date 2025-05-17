#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "structura.h"
inline Property* properties = nullptr;
inline int propertyCount = 0;
inline const string USERS_FILE = "users.txt";
inline const string PROPERTY_FILE = "properties.txt";
inline const string ADMIN_USERNAME = "admin";
inline const string ADMIN_PASSWORD = "admin123";
inline const double RATE_RES = 0.0001;
inline const double RATE_NON_RES = 0.0005;