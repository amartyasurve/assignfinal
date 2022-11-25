#include <iostream>
#include <vector>

using namespace std;

bool valid(vector<string> &board, int row, int col)
{
    // checking col
    for(int i=row; i>=0; i--) {
        if(board[i][col] == 'Q') return false;
    }

    // check left diagonal
    for(int i=row, j=col; i>=0 && j>=0; i--, j--) {
        if(board[i][j] == 'Q') return false;
    }

    // check right daigonal
    for(int i=row, j=col; i>=0 && j<board.size(); i--, j++) {
        if(board[i][j] == 'Q') return false;
    }

    return true;
}

void solve(vector<string> &board, vector<vector<string>> &ans, int row)
{
    if(row == board.size()) {
        ans.push_back(board);
        return;
    }

    for(int i=0; i<board.size(); i++) {
        if(valid(board, row, i)) {
            board[row][i] = 'Q';
            solve(board, ans, row+1);
            board[row][i] = '-';
        }
    }
}

vector<vector<string>> nqueen(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '-'));
    solve(board, ans, 0);
    return ans;
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter n : "; cin >> n;
    vector<vector<string>> ans = nqueen(n);

    if(ans.size() == 0) {
        cout << "No solution possible\n\n";
        return 0;
    }

    for(auto board : ans) {
        for(string s : board) {
            for(char c : s) cout << c << " ";
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}