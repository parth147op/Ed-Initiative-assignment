#pragma once

#include "ClientProtocolAdapter.h"

using namespace std;

class WebSocketAdapter : public ClientProtocolAdapter {
public:
    void sendMessage(const std::string& message) override {
        // Mock WebSocket send logic
        // In a real scenario, this would use a WebSocket library to send the message
    }

    string receiveMessage() override {
        // Mock WebSocket receive logic
        // In a real scenario, this would wait for a message from the WebSocket connection
        return "Mock WebSocket Message";
    }
};
