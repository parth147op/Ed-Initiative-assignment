#pragma once

#include "Subject.h"
#include "Message.h"
#include <vector>
#include <set>  // This was missing

using namespace std;

class ChatRoom : public Subject {
private:
    vector<Message> messages;
    set<string> activeUsers;

public:
    void addMessage(const Message& message) {
        messages.push_back(message);
        notify(); // Notify observers about the new message
    }

    vector<Message> getMessages() const {
        return messages;
    }
    void addUser(const string& username) {
        activeUsers.insert(username);
    }

    void removeUser(const string& username) {
        activeUsers.erase(username);
    }

    set<string> getActiveUsers() const {
        return activeUsers;
    }
};
