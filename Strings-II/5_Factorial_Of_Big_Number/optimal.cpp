#include<iostream>
#include<vector>
using namespace std;
void printArray(vector<int> arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
string factorial(int N){
    vector<int> ans(1,1);
    while(N > 1){
        int carry = 0;
        
        for(int i = 0;i<ans.size();i++){
            int res = ans[i] * N + carry;
            carry = res / 10;
            ans[i] = res % 10;
        }
        while(carry){
            ans.push_back(carry%10);
            carry = carry/10;
        }
        N--;
    }
    string temp;
    for(int i = ans.size()-1;i >= 0;i--){
           temp += ans[i] + '0';
    }
    return temp;
}
int main(){
    int x = 1000;
    cout<<"The factorial of x is: "<<factorial(x)<<endl;

    return 0;
}