// Roll NO - AP21110010201
// Perumalla Dharan

#include <iostream>
using namespace std;

int main(){
    int n1;
    cout<<"Enter the no of digits in divisor"<<endl;
    cin>>n1;
    bool divisor[n1];
    cout<<"Enter the divisor"<<endl;
    for(int i=0;i<n1;i++){
        cin>>divisor[i];
    }
    int n2;
    cout<<"Enter the no of digits in message"<<endl;
    cin>>n2;
    bool message[n2+n1-1];
    cout<<"Enter the message"<<endl;
    for(int i=0;i<n2;i++){
        cin>>message[i];
    }
    for(int i=n2;i<n2+n1-1;i++){
        message[i]=0;
    }

    bool temp[n1];
    for(int i=0;i<n1;i++){
        temp[i]=message[i];
    }
    for(int i=0;i<n2;i++){
        if(temp[0]==1){
            for(int j=0;j<n1;j++){
                temp[j]=temp[j]^divisor[j];
            }
        }
        for(int j=0;j<n1-1;j++){
            temp[j]=temp[j+1];
        }
        temp[n1-1]=message[i+n1];
    }
    cout<<"The remainder is"<<endl;
    for(int i=0;i<n1-1;i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;
    cout<<"The transmitted message is"<<endl;
    for(int i=0;i<n2;i++){
        cout<<message[i]<<" ";
    }
    for(int i=0;i<n1-1;i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;
    cout<<"Message verification"<<endl;
    bool recieved_message[n2+n1-1];
    for (int i = 0; i < n2; i++)
    {
        recieved_message[i]=message[i];
    }
    for (int i = n2; i < n2+n1-1; i++)
    {
        recieved_message[i]=temp[i-n2];
    }
    for(int i=0;i<n2;i++){
        if(recieved_message[i]==1){
            for(int j=0;j<n1;j++){
                recieved_message[j+i]=recieved_message[j+i]^divisor[j];
            }
        }
    }
    int flag=0;
    for(int i=0;i<n1-1;i++){
        if(recieved_message[n2+i]!=0){
            flag=1;
            break;
        }
    }
    if(flag==0){
        cout<<"Message recieved correctly"<<endl;
    }
    else{
        cout<<"Message recieved incorrectly"<<endl;
    }   
    return 0;
}