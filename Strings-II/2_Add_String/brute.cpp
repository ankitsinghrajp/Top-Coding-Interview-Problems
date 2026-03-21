#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
string addition(string &num1, string &num2){
    int first = num1.size()-1;
    int second = num2.size()-1;
    string result;
    int carry = 0;
    while(first >= 0 || second >= 0){
        int sum = 0;
        if(first >= 0){
           sum += num1[first] - '0';
           first --;
        }
        
        if(second >= 0){
            sum += num2[second] - '0';
            second --;
        }

        sum += carry;
        carry = sum/10;

        result.push_back((sum%10) + '0');
    }

    if(carry) result.push_back(carry + '0');
    reverse(result.begin(),result.end());
    return result;
}
int main()
{
    string num1 = "26583";
    string num2 = "698";
    string result = addition(num1, num2);
    cout << "The sum of two string is: " << result << endl;
    return 0;
}