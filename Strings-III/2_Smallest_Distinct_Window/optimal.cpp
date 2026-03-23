#include<iostream>
#include<vector>
using namespace std;
int smallestDistinctWindow(string &str){
    vector<int> count(256,0);
    int diff = 0;
    // Count the distinct elements
    for(int i = 0;i<str.size();i++){
        if(count[str[i]] == 0){
            diff ++;
        }

        count[str[i]] ++;
    }

    // Clear the frequency array
    for(int i = 0;i<256;i++){
        count[i] = 0;
    }

    int first = 0;
    int second = 0;
    int len = str.size();

    while(second < str.size()){
         
        // increase the window till diff not equal to zero
        while(diff && second < str.size()){
            if(count[str[second]] == 0){
                diff --;
            }

            count[str[second]]++;
            second++;
        }
        len = min(len,second - first);

        while(diff == 0){
            len = min(len, second - first);
            count[str[first]] --;
            if(count[str[first]] == 0) diff ++;
            first ++;
        }
    }
    return len;
}
int main(){
    string str = "aabcbcdbca";

    cout<<"The smallest distinct window of the given string is: "<<smallestDistinctWindow(str)<<endl;

    return 0;
}