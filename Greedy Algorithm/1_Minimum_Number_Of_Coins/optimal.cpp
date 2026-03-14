#include<iostream>
#include<vector>
using namespace std;
int minimumCoins(int n){
    vector<int> currency = {10,5,2,1};  // given in question
    int notes = 0;
    int i = 0;
    int minCount = 0;

    while(n != 0){
        notes = n/currency[i];
        while(notes--){
            minCount ++;
        }
        n = n%currency[i];
        if(i<currency.size()) i++;
    }
    return minCount;
}
int main(){
    int n = 121;

    cout<<"The minimum numbers of coins needed is: "<<minimumCoins(n);
    return 0;
}