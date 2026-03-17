#include <iostream>
#include <vector>
using namespace std;
void printArray(vector<vector<string>> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << endl;
        }
        cout << endl;
    }
}

void find(int row, int n, vector<string> &Board, vector<vector<string>> &ans, vector<bool> &col, vector<bool> &leftDiagonal, vector<bool> &rightDiagonal)
{
    if (row == n)
    {
        ans.push_back(Board);
        return;
    }

    // Placing Queen
    for (int j = 0; j < n; j++)
    {

        if (col[j] == 0 && leftDiagonal[j + row] == 0 && rightDiagonal[(n - 1) + (j - row)] == 0)
        {
            col[j] = 1;
            leftDiagonal[j + row] = 1;
            rightDiagonal[(n - 1) + (j - row)] = 1;
            Board[row][j] = 'Q';
            find(row + 1, n, Board, ans, col, leftDiagonal, rightDiagonal);
            col[j] = 0;
            leftDiagonal[j + row] = 0;
            rightDiagonal[(n - 1) + (j - row)] = 0;
            Board[row][j] = '.';
        }
    }
}

vector<vector<string>> nQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> Board(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Board[i].push_back('.');
        }
    }

    vector<bool> col(n, 0);
    vector<bool> leftDiagonal(2 * n - 1, 0);
    vector<bool> rightDiagonal(2 * n - 1, 0);

    find(0, n, Board, ans, col, leftDiagonal, rightDiagonal);
    return ans;
}
int main()
{

    int n = 4;

    vector<vector<string>> ans = nQueens(n);

    printArray(ans);

    return 0;
}