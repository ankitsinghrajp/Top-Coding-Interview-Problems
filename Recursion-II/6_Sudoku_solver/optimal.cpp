#include<iostream>
#include<vector>
using namespace std;

bool check(int num, vector<vector<char>> & board, int i, int j){
   char c = '0' + num;

   // Check the row
   for(int col = 0;col < 9; col ++){
       if(board[i][col] == c) return 0;
   }

   // Check the col

   for(int row = 0; row < 9; row ++){
       if(board[row][j] == c) return 0;
   }

   // Check the block

   int row = (i/3) *3;
   int col = (j/3) *3;

   for(int a = row; a< row + 3;a ++){
    for(int b = col; b < col + 3;b ++){
        if(board[a][b] == c) return 0;
    }
   }
   return 1;
}

bool find(int i, int j, vector<vector<char>> &board){
    // Base Case
    if(i == 9){
        return 1;
    }

    if(j == 9){
        return find(i+1,0,board);
    }

    if(board[i][j] != '.'){
        return find(i,j+1,board);
    }
    
    // Fill the value from 1 to 9
    for(int num = 1; num <= 9; num ++){
       
        if(check(num,board,i,j)){
           board[i][j] = '0' + num;

           if(find(i,j+1,board)){
                return 1;
           }
           else{
              board[i][j] = '.';
           }
        }
    }

    return 0;
}

void sudokuSolver(vector<vector<char>> &board){
    find(0,0,board);
}

void printBoard(vector<vector<char>> &board){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){

    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    cout << "Original Sudoku: "<<endl;
    printBoard(board);

    sudokuSolver(board);

    cout <<"Solved Sudoku"<<endl;
    printBoard(board);

    return 0;
}