#include<iostream>
#include<vector>
using namespace std;
string defengeIpAddr(string address){
    string temp;
    for(int i = 0;i<address.size();i++){
        if(address[i] == '.'){
            temp += "[.]";
        }
        else{
            temp += address[i];
        }
    }

    return temp;
}
int main(){
    string address = "1.1.1.1";
    // Answer should be this --> 1[.]1[.]1[.]1
    
    cout<<"The original Ip address is: "<<endl<<address<<endl;
    cout<<"The defenged ip address is: "<<endl<<defengeIpAddr(address);
    return 0;
}