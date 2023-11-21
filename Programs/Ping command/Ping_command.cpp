// AP21110010201
// Perumalla Dharan

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <memory>

using namespace std;

string runPingCommand(const string& host) {
    string command;
    char buffer[128];
    string result = "";

#ifdef _WIN32
    // Windows
    command = "ping -n 4 " + host;
#else
    // Unix-like (Linux)
    command = "ping -c 4 " + host;
#endif

    unique_ptr<FILE, decltype(&pclose)> pipe(popen(command.c_str(), "r"), pclose);
    if (!pipe) {
        return "Error executing ping command.";
    }

    while (!feof(pipe.get())) {
        if (fgets(buffer, sizeof(buffer), pipe.get()) != nullptr) {
            result += buffer;
        }
    }

    return result;
}

int main() {
    string host;
    cout << "Enter the host to ping: ";
    cin >> host;

    string response = runPingCommand(host);
    cout << response;

    return 0;
}
