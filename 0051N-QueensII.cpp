#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        vector<int> queens(n, -1);
        moveNext(0, queens, n, ans);
        return ans;
    }
private:
    bool isSafe(pair<int, int> square, vector<int> &queens){
        for(int i = 0; i < square.first; i++){
            if(square.second == queens[i] || 
            abs(square.first - i) == abs(square.second - queens[i])) return false;
        }
        return true;
    }

    void moveNext(int row, vector<int> &queens, const int &n, int &ans){
        for(int i = 0; i < n; i++){
            if(isSafe({row, i}, queens)){
                queens[row] = i;
                if(row == n-1) ans++;
                else moveNext(row+1, queens, n, ans);
            }
        }
        return;
    }
};

