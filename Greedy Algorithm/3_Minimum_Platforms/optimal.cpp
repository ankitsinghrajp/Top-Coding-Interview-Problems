#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int minimumPlatforms(vector<int> arr, vector<int> dep){
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());

    int i = 1;
    int j = 0;
    int platforms = 1;
    int maxPlatforms = 0;

    while(i<arr.size() && j<dep.size()){
        if(arr[i] <= dep[j]){
            platforms ++;
            i++;
        }
        else{
            platforms --;
            j++;
        }

        maxPlatforms = max(maxPlatforms,platforms);
    }
    return maxPlatforms;
}
int main(){
    vector<int> arr = {900,940,950,1100,1500,1800};
    vector<int> dep = {910,1200,1120,1130,1900,2000};

    cout<<"The number of platforms required are: "<<minimumPlatforms(arr,dep);

    return 0;
}