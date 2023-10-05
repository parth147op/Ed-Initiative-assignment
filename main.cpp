#include "ChatApp.h"
#include "src/WebSocketAdapter.h"
#include "src/HttpAdapter.h"
#include <bits/stdc++.h>
#include "Logger.h"
#include "ChatException.h"

using namespace std;

int main() {
    try{    
    // Using WebSocket for communication
    auto webSocketAdapter = std::make_shared<WebSocketAdapter>();

    // Alice joins and sends messages
    ChatApp aliceApp("Alice", webSocketAdapter);
    aliceApp.joinRoom("Room123");
    aliceApp.sendMessageToRoom("Room123", "Hello, everyone!");
    // Bob joins and sends a message
    ChatApp bobApp("Bob", webSocketAdapter);
    bobApp.joinRoom("Room123");
    bobApp.sendMessageToRoom("Room123", "How's it going?");

    // Charlie joins and sends a message
    ChatApp charlieApp("Charlie", webSocketAdapter);
    charlieApp.joinRoom("Room123");
    charlieApp.sendMessageToRoom("Room123", "Goodbye!");
    charlieApp.sendMessageToRoom("Room123", "Goodbye Again!");

    // Display received messages (this is mocked for demonstration purposes)
    cout << aliceApp.receiveMessage() << endl;
    cout << bobApp.receiveMessage() << endl;
    cout << charlieApp.receiveMessage() << endl;

    // Displaying active users in "Room123"
    set<string> activeUsers = aliceApp.getActiveUsers("Room123");
    cout << "Active Users in Room123: ";
    for (const auto& user : activeUsers) {
        cout << user << " ";
    }
    cout << endl;

    // Sending a private message
    aliceApp.sendPrivateMessage("Bob", "Hey Bob, are you there?");
    
    //Viewing message history
    vector<Message> messageHistory = aliceApp.getMessageHistory("Room123");
    cout << "Message History in Room123: " << endl;
    for (const auto& message : messageHistory) {
        cout << message.getSender().getName() << ": " << message.getContent() << endl;
    }
    }
     catch (const ChatException &e) {
        cerr << "Caught chat exception: " << e.what() << endl;
    } catch (const exception &e) {
        cerr << "Caught general exception: " << e.what() << endl;
    }
    return 0;
}
