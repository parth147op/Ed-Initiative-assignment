#pragma once

#include "ChatRoom.h"
#include <map>
#include <string>
#include "../ChatException.h"
#include "../Logger.h"

using namespace std;

class ChatRoomManager {
private:
    map<string, ChatRoom> chatRooms;
    static ChatRoomManager* instance;

    // Private constructor to prevent instantiation
    ChatRoomManager() {}

public:
    // Public method to access the single instance
    static ChatRoomManager* getInstance() {
        if (!instance) {
            instance = new ChatRoomManager();
        }
        return instance;
    }

    ChatRoom& getChatRoom(const string& roomId) {
    if (chatRooms.find(roomId) == chatRooms.end()) {
        log(LogLevel::ERROR, "Room with ID: " + roomId + " does not exist.");
        throw ChatException("Room with ID: " + roomId + " does not exist.");
    }
    return chatRooms[roomId];
}


    void createChatRoom(const string& roomId) {
        if (chatRooms.find(roomId) == chatRooms.end()) {
            chatRooms[roomId] = ChatRoom();
        }
    }
};
