#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int upperBound(vector<int> &arr, int x){
   int low = 0; int high = arr.size()-1;
   int ans = arr.size();

   while(low <= high){
    int mid = (low + high)/2;
     
    if(arr[mid] > x){
        ans = mid;
        high = mid -1;
    }
    else{
       low = mid + 1;
    }
   }

   return low;
}

int countSmallerEquals(vector<int> &arr, int x){
    return upperBound(arr,x);
}
int medianMatrix(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    int start = INT32_MAX,  end = INT32_MIN;
    
    for(int i = 0;i< n; i++){
        start = min(start,matrix[i][0]);
        end = max(end,matrix[i][m-1]);
    }

    int desired = (n*m)/2;
    while(start <= end){
        int mid = (start + end)/2;

        int count = 0;
        for(int i = 0;i<n;i++){
            count += countSmallerEquals(matrix[i],mid);
        }

        if(count <= desired){
           start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
     
    return start;
}

int main(){
    vector<vector<int>> matrix = {{1,5,7,9,11},{2,3,4,5,10},{9,10,12,14,16}};

    cout<<"The median of the matrix is: "<<medianMatrix(matrix);

    return 0;
}