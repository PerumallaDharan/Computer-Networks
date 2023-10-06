// AP21110010201
// PERUMALLA DHARAN
// STOP AND WAIT
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // vector<int> data;
    int size;
    cout << "Enter the size of the data:" << endl;
    cin >> size;
    int data[size];
    cout << "Enter the data :" << endl;
    for (int i = 0; i < size; i++)
        cin >> data[i];
    int bit, n;
    cout << "Enter the window value:" << endl;
    cin >> n;
    int error[size] = {1};
    int m = 0, j = 0;
    int count = 0;
    while (true)
    {
    jump:
        j = m;
        for (int k = 0; k < n; k++)
        {
            cout << "sending the frame bit " << data[j] << " of position " << j + 1 << endl;
            cout << "Enter 2 to send noise \n0 for no noise:" << endl;
            cin >> bit;
            if (bit == 2)
                error[j] = 0;
            else
                error[j] = 1;
            count += 1;
            j++;
        }
    jump1:
        for (int k = 0; k < n; k++)
        {
            if (error[m] == 1)
            {

                cout << "Sending the ACK for bit " << data[m] << " of position " << m + 1 << endl;
                if (j < size)
                {
                    cout << "sending the frame bit " << data[j] << " of position " << j + 1 << endl;
                    cout << "Enter 2 to send noise \n0 for no noise : " << endl;
                    cin >> bit;
                    if (bit == 2)
                        error[j] = 0;
                    else
                        error[j] = 1;
                    j++;
                    count += 1;
                }
                if (m == size - 1)
                    break;
            }
            else
            {
                cout << "ACK not recieved for " << data[m] << " of position " << m + 1 << endl;
                goto jump;
            }
            m++;
        }
        for (int i = m; i < size; i++)
            cout << "Sending the ACK for bit " << data[m] << " of position " << m + 1 << endl;
        break;
    }
    cout << "Total number of frames transmitted: " << count << endl;
}