#pragma once

#include "ClientProtocolAdapter.h"
#include <string>

using namespace std;

class HttpAdapter : public ClientProtocolAdapter {
public:
    void sendMessage(const string& message) override {
        // Mock HTTP send logic
        // In a real scenario, this would make an HTTP POST request to send the message
    }

    std::string receiveMessage() override {
        // Mock HTTP receive logic
        // In a real scenario, this would make an HTTP GET request to fetch a new message
        return "Mock HTTP Message";
    }
};
