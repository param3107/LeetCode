#include <vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board){
        nextMove(0, 0, board);     
    }

private:
    bool isSafe(int x, int y, int num, vector<vector<char>>& board){
        for(int i = 0 ; i < 9; i++){
            if(board[x][i] != '.' && (board[x][i] - '0') == num) return false;
            if(board[i][y] != '.' && (board[i][y] - '0') == num) return false;
        }
        for(int i = (x/3)*3; i <= (x/3)*3+2; i++){
            for(int j = (y/3)*3; j <= (y/3)*3+2; j++){
                if(board[i][j] != '.' && (board[i][j] - '0') == num) return false;
            }
        }
        return true;
    }

    bool nextMove(int x, int y, vector<vector<char>>& board){
        if (y == 9) {
            x++;
            y = 0;
        }

        if (x == 9) return true;

        if(board[x][y] != '.') return nextMove(x, y + 1, board);

        for(int i = 1; i <= 9; i++){
            if(isSafe(x, y, i, board)){
                board[x][y] = i + '0';
                if(nextMove(x, y + 1, board)) return true;
                board[x][y] = '.';
            }
        }

        return false;
    }
};
