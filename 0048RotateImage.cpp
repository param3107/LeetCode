#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        rotateMatrix(matrix, matrix.size(), matrix.size());
        return;
    }
private:
    void rotateMatrix(vector<vector<int>> &mat, int n, int m){
    int carry1, carry2, startI = 0, startJ = 0;
    while((n - startI > 1) && (m - startJ > 1)){
        carry1 = mat[startI][startJ];
        carry2 = mat[startI][m-1];
        for(int j = m-1; j > startJ+1; j--){
            mat[startI][j] = mat[startI][j-1];
        }
        mat[startI][startJ+1] = carry1;
        
        carry1 = carry2;
        carry2 = mat[n-1][m-1];
        for(int i = n-1; i > startI+1; i--){
            mat[i][m-1] = mat[i-1][m-1];
        }
        mat[startI+1][m-1] = carry1;

        carry1 = carry2;
        carry2 = mat[n-1][startJ];
        for(int j = startJ; j < m-2; j++){
            mat[n-1][j] = mat[n-1][j+1];
        }
        mat[n-1][m-2] = carry1;

        for(int i = startI; i < n-2; i++){
            mat[i][startJ] = mat[i+1][startJ];
        }
        mat[n-2][startJ] = carry2;
        startI++; startJ++; n--; m--;
    }
}
};