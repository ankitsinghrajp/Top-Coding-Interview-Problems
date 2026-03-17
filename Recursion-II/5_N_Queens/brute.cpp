#include<iostream>
#include<vector>
using namespace std;
void printArray(vector<vector<string>> &arr){
    for(int i = 0;i<arr.size();i++){
        for(int j = 0;j<arr[i].size();j++){
            cout<<arr[i][j]<<endl;
        }
        cout<<endl;
    }
}

bool checkDiagonal(int i, int j, int n, vector<string> &Board){
    int row = i;
    int col = j;
    // Checking left diagonal
    while(row > -1 && col>-1){
       if(Board[row][col] == 'Q'){
           return 0;
       }
       row --;
       col --;
    }

    // Checking right diagonal
    row = i;
    col = j;
    while(row > -1 && col < n){
        if(Board[row][col] == 'Q'){
            return 0;
        }
        row --;
        col ++;
    }
    return 1;
}

void find(int row,int n, vector<string> &Board, vector<vector<string>> &ans, vector<bool> &col){
    // Base Condition
    if(row == n){
        ans.push_back(Board);
        return;
    }

    // Fill Q i
    for(int j = 0;j<n;j++){
        
        if(col[j] == 0 && checkDiagonal(row,j,n,Board)){
            col[j] = 1;
            Board[row][j] = 'Q';
            find(row+1,n,Board,ans,col);
            col[j] = 0;
            Board[row][j] = '.';
        }
    }
}

vector<vector<string>> nQueens(int n){
    vector<vector<string>> ans;
    vector<string> Board(n);

    for(int i = 0;i<n;i++)
    for(int j = 0;j<n;j++)
    Board[i].push_back('.');
    
    vector<bool> col(n,0);
    find(0,n,Board,ans,col);
    return ans;
}
int main(){
    
    int n = 4;

    vector<vector<string>> ans = nQueens(n);
    
    printArray(ans);

    return 0;
}