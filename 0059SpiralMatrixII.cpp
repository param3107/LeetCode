#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int posX = 0, posY = 0;
        moveRight(ans, posX, posY, n-1, n-1, 1);
        return ans;
    }
private:
    void moveRight(vector<vector<int>> &ans, int &posX, int &posY, int boundX, int boundY, int n){
        ans[posY][posX] = n;
        if(posX < boundX){
            posX++;
            moveRight(ans, posX, posY, boundX, boundY, n+1);
        }
        else{
            if(posY < boundY){
                posY++;
                moveDown(ans, posX, posY, ans[0].size() - boundX - 1, boundY, n+1);
            }
            else return;
        }
    }

    void moveDown(vector<vector<int>> &ans, int &posX, int &posY, int boundX, int boundY, int n){
        ans[posY][posX] = n;
        if(posY < boundY){
            posY++;
            moveDown(ans, posX, posY, boundX, boundY, n+1);
        }
        else{
            if(posX > boundX){
                posX--;
                moveLeft(ans, posX, posY, boundX, ans.size() - boundY, n+1);
            }
            else return;
        }
    }

    void moveLeft(vector<vector<int>> &ans, int &posX, int &posY, int boundX, int boundY, int n){
        ans[posY][posX] = n;
        if(posX > boundX){
            posX--;
            moveLeft(ans, posX, posY, boundX, boundY, n+1);
        }
        else{
            if(posY > boundY){
                posY--;
                moveUp(ans, posX, posY, ans[0].size() - boundX - 2, boundY, n+1);
            }
            else return;
        }
    }

    void moveUp(vector<vector<int>> &ans, int &posX, int &posY, int boundX, int boundY, int n){
        ans[posY][posX] = n;
        if(posY > boundY){
            posY--;
            moveUp(ans, posX, posY, boundX, boundY, n+1);
        }
        else{
            if(posX < boundX){
                posX++;
                moveRight(ans, posX, posY, boundX, ans.size() - boundY - 1, n+1);
            }
            else return;
        }
    }
};