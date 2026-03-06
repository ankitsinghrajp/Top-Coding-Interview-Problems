#include<iostream>
using namespace std;
double pow(int x, int n){
    bool negative = false;
    if(n < 0){
       negative = true;
       n = -1 * n;
    }
    
    double ans = 1;
    while(n!=0){
        if(n%2 == 0) {
            x = x*x;
            n = n/2;
        }
        else if(n%2 == 1){
            ans = ans * x;
            n = n - 1;
        }
    }
    if(negative){
        ans = 1/ans;
    }
   return ans;
}
int main(){
    int x = 2;
    int n = 10;

    cout<<"The "<<x<<" to the power "<<n<<" is: "<<pow(x,n);
    return 0;
}