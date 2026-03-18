#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int medianMatrix(vector<vector<int>> &matrix){
    vector<int> temp;
    for(int i = 0;i<matrix.size();i++){
        for(int j = 0;j<matrix[i].size();j++){
            temp.push_back(matrix[i][j]);
        }
    }

    sort(temp.begin(),temp.end());
 
    int middleIndex = temp.size()/2;

    return temp[middleIndex];
}
int main(){
    vector<vector<int>> matrix = {{1,5,7,9,11},{2,3,4,5,10},{9,10,12,14,16}};

    cout<<"The median of the matrix is: "<<medianMatrix(matrix);

    return 0;
}