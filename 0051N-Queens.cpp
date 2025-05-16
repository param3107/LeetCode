#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> queens(n, -1);
        moveNext(0, queens, n, ans);
        return ans;
    }
private:
    void insertConfig(vector<vector<string>> &ans, vector<int> &queens, int n){
        vector<string> config;
        string row = "";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(queens[i] == j) row.append("Q");
                else row.append(".");
            }
            config.push_back(row);
            row.clear();
        }
        ans.push_back(config);
        return;
    }

    bool isSafe(pair<int, int> square, vector<int> &queens){
        for(int i = 0; i < square.first; i++){
            if(square.second == queens[i] || 
            abs(square.first - i) == abs(square.second - queens[i])) return false;
        }
        return true;
    }

    void moveNext(int row, vector<int> &queens, int n, vector<vector<string>> &ans){
        for(int i = 0; i < n; i++){
            if(isSafe({row, i}, queens)){
                queens[row] = i;
                if(row == n-1) insertConfig(ans, queens, n);
                else moveNext(row+1, queens, n, ans);
            }
        }
        return;
    }
};

