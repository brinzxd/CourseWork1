#include "hash_password.h"
using namespace std;
unsigned long long hashPassword(const string& password) {
    unsigned long long hash = 5381;
    for (char c : password) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}