#pragma once
#include <iostream>
#include <string>

using namespace std;
enum class LogLevel {
    INFO, WARN, ERROR
};

inline void log(LogLevel level, const string &message) {
    switch(level) {
        case LogLevel::INFO:
            cout << "[INFO]: " << message << endl;
            break;
        case LogLevel::WARN:
            cout << "[WARN]: " << message << endl;
            break;
        case LogLevel::ERROR:
            cerr << "[ERROR]: " << message << endl;
            break;
    }
}
