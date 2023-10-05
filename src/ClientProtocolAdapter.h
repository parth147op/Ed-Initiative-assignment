#pragma once

using namespace std;

class ClientProtocolAdapter {
public:
    virtual void sendMessage(const string& message) = 0;
    virtual string receiveMessage() = 0;
};
