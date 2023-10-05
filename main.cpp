#include "ChatApp.h"
#include "src/WebSocketAdapter.h"
#include <bits/stdc++.h>
#include "Logger.h"
#include "ChatException.h"

using namespace std;

int main()
{
    try
    {
        // Using WebSocket for communication
        auto webSocketAdapter = std::make_shared<WebSocketAdapter>();

        string roomId;
        vector<ChatApp> activeUsers;

        // Get room ID
        cout << "Enter chat room ID to create: ";
        cin >> roomId;

        cout << "Enter number of active users: ";
        int userCount;
        cin >> userCount;

        for (int i = 0; i < userCount; ++i)
        {
            string username;
            cout << "Enter username for user " << i + 1 << ": ";
            cin >> username;
            activeUsers.emplace_back(username, webSocketAdapter);
            activeUsers.back().joinRoom(roomId);
        }

        // Loop to send messages
        while (true)
        {
            cout << "\nOptions:\n";
            cout << "1. Send message\n";
            cout << "2. View message history\n";
            cout << "3. Exit\n";
            cout << "Choose an option (1-3): ";

            int choice;
            cin >> choice;

            switch (choice)
            {
            case 1:
            {
                string senderName;
                cout << "Enter sender's username: ";
                cin >> senderName;
                ChatApp *senderApp = nullptr;
                for (auto &app : activeUsers)
                {
                    if (app.getCurrentUser().getName() == senderName)
                    {
                        senderApp = &app;
                        break;
                    }
                }
                if (!senderApp)
                {
                    cout << "Username not found!" << endl;
                    break;
                }
                string messageContent;
                cout << "Enter message content: ";
                cin.ignore(); // Clear newline from input buffer
                getline(cin, messageContent);
                senderApp->sendMessageToRoom(roomId, messageContent);

                // Displaying active users after sending a message
                set<string> currentActiveUsers = senderApp->getActiveUsers(roomId);
                cout << "\nActive Users in " << roomId << ": ";
                for (const string &user : currentActiveUsers)
                {
                    cout << user << " ";
                }
                cout << endl;

                break;
            }
            case 2:
            {
                vector<Message> messageHistory = activeUsers[0].getMessageHistory(roomId); // Assuming all users have the same message history
                cout << "Message History in " << roomId << ": " << endl;
                for (const auto &message : messageHistory)
                {
                    cout << message.getSender().getName() << ": " << message.getContent() << endl;
                }
                break;
            }
            case 3:
                return 0;
            default:
                cout << "Invalid option. Please choose between 1-3." << endl;
            }
        }
    }
    catch (const ChatException &e)
    {
        cerr << "Caught chat exception: " << e.what() << endl;
    }
    catch (const exception &e)
    {
        cerr << "Caught general exception: " << e.what() << endl;
    }
    return 0;
}
