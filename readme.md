# Real-time Chat Application

## Description
This project is a simple real-time chat application where users can join or create chat rooms. The core functionalities include creating/joining chat rooms, sending/receiving messages, and listing active users. The program also supports optional features like private messaging and message history.

## Features
- **Join/Create Chat Rooms:** Users can join existing chat rooms or create new ones by providing a unique room ID.
- **Send/Receive Messages:** Users can send and receive messages in real-time within a chat room.
- **Active Users List:** The application can display a list of active users in a chat room.
- **Private Messaging:** Users can send private messages to other users (currently mocked).
- **Message History:** Users can view message history for a chat room.

## Design Patterns & Principles
The application is designed using several design patterns and principles:
- **Singleton Pattern:** Used for managing the state of chat rooms via `ChatRoomManager`.
- **Observer Pattern:** Used to notify clients of new messages or user activities with `Subject` and `Observer`.
- **Adapter Pattern:** The system can work with different types of client communication protocols (like WebSocket, HTTP) using adapters.
- **SOLID Principles:** The application strives to adhere to the SOLID principles for OOP design.

## Directory Structure
- **Root:** Contains main application logic, logger, and exception handling.
  - `.vscode`: Configuration for VSCode (if used).
  - `src`: Contains core source files related to chat functionalities.
  
## Dependencies
- Standard C++ libraries.
- (Any other dependencies if added in the future.)

## Getting Started
1. Compile the application using a C++ compiler.
2. Run the executable.
3. Follow on-screen prompts to interact with the chat application.

## Compilation

To compile the project, use the following command:

```bash
g++ main.cpp src/ChatRoomManager.cpp -o a.exe
```
- Do not use the g++ main.cpp command alone to compile the project. The reason is that our chat application's source code is spread across multiple files. The main.cpp file has dependencies on other source files like src/ChatRoomManager.cpp. By specifying each required source file in the compilation command, we ensure that all the necessary code gets compiled and linked together. If you only compile main.cpp, you will miss the implementations in other files, leading to linker errors.

## Limitations
- Real-time communication is mocked for the purpose of this assignment. In a real-world application, actual sockets or web services would be required.

## Error Handling
The application makes use of a custom `ChatException` for handling chat-specific exceptions. General exceptions are also caught to ensure smooth user experience.

## Logging
A simple logging mechanism is provided to log informational, warning, and error messages. The current implementation displays logs in the console, but this can be extended to write logs to files.

## Future Enhancements
- Implement actual real-time communication using WebSockets or another suitable protocol.
- Enhance error handling with more specific exception types.
- Implement a user authentication system for enhanced security.
- Provide message encryption to secure user messages.