// Write a program to implement Checksum error detection technique
// Perumalla Dharan
// AP21110010201


#include <iostream>
using namespace std;

int sender(string input) {
    int checksum = 0;
    cout << "\n***SENDER SIDE***\n";

    for (char c : input) {
        checksum += int(c);
    }

    cout << "SUM IS: " << checksum;
    checksum = ~checksum;
    cout << "\nCHECKSUM IS: " << checksum;
    return checksum;
}

void receiver(string input, int s) {
    int checksum = 0;
    cout << "\n\n***RECEIVER SIDE***\n";

    for (char c : input) {
        checksum += int(c);
    }

    cout << "SUM IS: " << checksum;

    checksum += s;

    checksum = ~checksum;
    cout << "\nCHECKSUM IS: " << checksum;
    
    int expectedChecksum = ~checksum;

    cout << "\nCHECKSUM IS: " << expectedChecksum;

    if (checksum == expectedChecksum) {
        cout << "\nNo error detected. Data received successfully.\n";
    } else {
        cout << "\nError detected. Data is corrupt.\n";
    }
}
    


int main() {
    int f, b;
    cout << "Enter the number of frames: ";
    cin >> f;
    cout << "Enter the size of each frame: ";
    cin >> b;
    cin.ignore(); 
    string input;
    cout << "Enter the string: ";
    getline(cin, input);
    int s = sender(input);
    receiver(input, s);
    return 0;
}
