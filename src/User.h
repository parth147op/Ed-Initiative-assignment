#pragma once

#include <string>

using namespace std;

class User {
private:
    string username;

public:
    User(const string& name) : username(name) {}

    string getName() const { return username; }
};
