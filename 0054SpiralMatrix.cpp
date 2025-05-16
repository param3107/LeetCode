#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix){
        vector<int> ans;
        int posX = 0, posY = 0, boundX = matrix[0].size() - 1, boundY = matrix.size() - 1;
        moveRight(matrix, ans, posX, posY, boundX, boundY);
        return ans;
    }
private:
    void moveRight(vector<vector<int>> &matrix, vector<int> &ans, int &posX, int &posY, int boundX, int boundY){
        ans.push_back(matrix[posY][posX]);
        if(posX < boundX){
            posX++;
            moveRight(matrix, ans, posX, posY, boundX, boundY);
        }
        else{
            if(posY < boundY){
                posY++;
                moveDown(matrix, ans, posX, posY, matrix[0].size() - boundX - 1, boundY);
            }
            else return;
        }
    }

    void moveDown(vector<vector<int>> &matrix, vector<int> &ans, int &posX, int &posY, int boundX, int boundY){
        ans.push_back(matrix[posY][posX]);
        if(posY < boundY){
            posY++;
            moveDown(matrix, ans, posX, posY, boundX, boundY);
        }
        else{
            if(posX > boundX){
                posX--;
                moveLeft(matrix, ans, posX, posY, boundX, matrix.size() - boundY);
            }
            else return;
        }
    }

    void moveLeft(vector<vector<int>> &matrix, vector<int> &ans, int &posX, int &posY, int boundX, int boundY){
        ans.push_back(matrix[posY][posX]);
        if(posX > boundX){
            posX--;
            moveLeft(matrix, ans, posX, posY, boundX, boundY);
        }
        else{
            if(posY > boundY){
                posY--;
                moveUp(matrix, ans, posX, posY, matrix[0].size() - boundX - 2, boundY);
            }
            else return;
        }
    }

    void moveUp(vector<vector<int>> &matrix, vector<int> &ans, int &posX, int &posY, int boundX, int boundY){
        ans.push_back(matrix[posY][posX]);
        if(posY > boundY){
            posY--;
            moveUp(matrix, ans, posX, posY, boundX, boundY);
        }
        else{
            if(posX < boundX){
                posX++;
                moveRight(matrix, ans, posX, posY, boundX, matrix.size() - boundY - 1);
            }
            else return;
        }
    }
};