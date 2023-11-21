// AP21110010201
// Perumalla Dharan
// Stop and Wait

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> data;
    cout << "Enter the data to be send one by one (0 or 1) and -1 to stop : " << endl;
    int bit;
    while (true)
    {
        cin >> bit;
        if (bit == -1)
            break;
        data.push_back(bit);
    }
    vector<int> error;
    auto i = data.begin();
    int j;
    j = data.size();
    int r[j] = {0};
    j = 0;
    while (i != data.end())
    {
    jump:
        cout << "Sending the bit " << *i << endl;
        cout << "Enter 2 to send noise \n0 for no noise:" << endl;
        cin >> bit;
        if (bit == 2)
        {
            error.push_back(2);
            goto jump;
        }
        if (r[j] == 0)
        {
            error.push_back(*i);
            r[j] += 1;
        }
        cout << "Sending the ACK for " << *i << endl;
        cout << "Enter 3 to halt the ACK \n0 for no halt:" << endl;
        cin >> bit;
        if (bit == 3)
        {
            error.push_back(3);
            error.push_back(*i);
            r[j] += 1;
            goto jump;
        }
        ++i;
        j += 1;
    }
    cout << "\nTotal bits transformation : " << endl;
    auto k = data.begin();
    i = error.begin();
    j = 0;
    while (i != error.end())
    {
        if (*i == 2)
            cout << "Frame bit " << *k << " does not recieved at reciever side " << endl;
        else if (*i == 3)
        {
            --k;
            cout << "ACK of " << *k << " not received at sender side" << endl;
            ++k;
        }
        else
        {
            cout << "Frame bit " << *i << " sent successfully" << endl;
            ++k;
        }
        ++i;
    }
    k = data.begin();
    cout << endl;
    while (k != data.end())
    {
        cout << "Frame bit " << *k << " recieved " << r[j] << " times" << endl;
        ++k;
        j++;
    }
}