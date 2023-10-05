#pragma once
#include "src/User.h"
#include "src/ChatRoomManager.h"
#include "src/ClientProtocolAdapter.h"
#include <memory>
#include <bits/stdc++.h>
#include "Logger.h"
#include "ChatException.h"

using namespace std;

class ChatApp {
private:
    User currentUser;
    ChatRoomManager* roomManager;
    shared_ptr<ClientProtocolAdapter> clientAdapter;

public:
    ChatApp(const string& username, shared_ptr<ClientProtocolAdapter> adapter) 
        : currentUser(username), clientAdapter(adapter) {
        roomManager = ChatRoomManager::getInstance();
    }

    void joinRoom(const string& roomId) {
    log(LogLevel::INFO, currentUser.getName() + " is trying to join room: " + roomId);
    roomManager->createChatRoom(roomId);
    roomManager->getChatRoom(roomId).addUser(currentUser.getName());
    log(LogLevel::INFO, currentUser.getName() + " joined room: " + roomId);
    }



    void sendMessageToRoom(const string& roomId, const string& content) {
        Message message(currentUser, content);
        roomManager->getChatRoom(roomId).addMessage(message);

        // Using the adapter to send the message
        clientAdapter->sendMessage(content);
    }

    string receiveMessage() {
        return clientAdapter->receiveMessage();
    }
    vector<Message> getMessageHistory(const string& roomId) {
        return roomManager->getChatRoom(roomId).getMessages();
    }

    const User& getCurrentUser() const {
        return currentUser;
    }
    
    set<string> getActiveUsers(const string& roomId) {
        return roomManager->getChatRoom(roomId).getActiveUsers();
    }
    void sendPrivateMessage(const string& toUsername, const string& content) {
        // In a real-world scenario, this would send a private message to the specific user.
        // Here, we're just mocking this feature.
        cout << "Private message to " << toUsername << ": " << content << endl;
    }
};