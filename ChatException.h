#pragma once
#include <exception>
#include <string>

using namespace std;

class ChatException : public exception {
    string message;
public:
    ChatException(const string &msg) : message(msg) {}
    const char *what() const noexcept override {
        return message.c_str();
    }
};
