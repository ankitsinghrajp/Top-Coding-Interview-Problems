#include<iostream>
#include<vector>
using namespace std;
void printArray(vector<int> arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> FindRepeatingMissing(vector<int> arr){
    vector<int> ans;
    int n = arr.size();
    long long sn = (long long)n* (n+1)/2;
    long long s2n = (long long)n* (n+1) * (2*n+1)/6;

    long long s = 0, s2 = 0;
    for(int i = 0;i<arr.size();i++){
        s += arr[i];
        s2 += (long long)arr[i] * (long long)arr[i];
    }

    long long val1 = s - sn;
    long long val2 = s2 - s2n;
    val2 = val2/val1;

    long long x = (val1 + val2)/2;
    long long y = x - val1;

    ans.push_back((int)x);
    ans.push_back((int)y);

    return ans;
}

int main(){
    vector<int> arr = {4,3,6,2,1,1};

    cout<<"The repeating and missing value is: "<<endl;
    vector<int> ans = FindRepeatingMissing(arr);
    printArray(ans);
    return 0;
}