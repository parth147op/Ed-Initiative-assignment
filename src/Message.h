#pragma once

#include <string>
#include "User.h"

using namespace std;

class Message {
private:
    User sender;
    string content;

public:
    Message(const User& sender, const string& content) : sender(sender), content(content) {}

    string getContent() const { return content; }
    User getSender() const { return sender; }
};
