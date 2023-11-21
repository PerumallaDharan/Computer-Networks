// Program 1: Write a program to display the class of IP address, 
// network mask and generate the subnet IP address based on the subnet bits entered from the keyboard. 

#include <iostream>
#include <bitset>
#include <sstream>
#include <vector>

using namespace std;

// Function to get the class of IP address
string getIPClass(const string& ipAddress) {
    int firstOctet = stoi(ipAddress.substr(0, ipAddress.find('.')));

    if (firstOctet >= 1 && firstOctet <= 126) {
        return "Class A";
    } else if (firstOctet >= 128 && firstOctet <= 191) {
        return "Class B";
    } else if (firstOctet >= 192 && firstOctet <= 223) {
        return "Class C";
    } else if (firstOctet >= 224 && firstOctet <= 239) {
        return "Class D (Multicast)";
    } else if (firstOctet >= 240 && firstOctet <= 255) {
        return "Class E (Reserved)";
    } else {
        return "Invalid IP Address";
    }
}

// Function to calculate network mask
vector<int> calculateNetworkMask(int subnetBits) {
    bitset<32> subnetMask(0xFFFFFFFF);
    subnetMask <<= (32 - subnetBits);

    vector<int> maskParts;
    for (int i = 0; i < 32; i += 8) {
        maskParts.push_back((subnetMask >> i).to_ulong());
    }

    return maskParts;
}

// Function to generate subnet IP address
string generateSubnetIP(const string& ipAddress, int subnetBits) {
    vector<int> ipParts;
    istringstream iss(ipAddress);
    string part;
    while (getline(iss, part, '.')) {
        ipParts.push_back(stoi(part));
    }

    vector<int> subnetMask = calculateNetworkMask(subnetBits);
    for (size_t i = 0; i < ipParts.size(); ++i) {
        ipParts[i] &= subnetMask[i];
    }

    ostringstream subnetIP;
    subnetIP << ipParts[0] << '.' << ipParts[1] << '.' << ipParts[2] << '.' << ipParts[3];
    return subnetIP.str();
}

int main() {
    // Get input from the user
    string ipAddress;
    cout << "Enter the IP address: ";
    cin >> ipAddress;

    int subnetBits;
    cout << "Enter the number of subnet bits: ";
    cin >> subnetBits;

    // Display IP class
    string ipClass = getIPClass(ipAddress);
    cout << "IP Address Class: " << ipClass << endl;

    // Display network mask
    vector<int> subnetMask = calculateNetworkMask(subnetBits);
    cout << "Network Mask: ";
    for (size_t i = 0; i < subnetMask.size(); ++i) {
        cout << subnetMask[i];
        if (i < subnetMask.size() - 1) {
            cout << '.';
        }
    }
    cout << endl;

    // Generate and display subnet IP address
    string subnetIP = generateSubnetIP(ipAddress, subnetBits);
    cout << "Subnet IP Address: " << subnetIP << endl;

    return 0;
}
