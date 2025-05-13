#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = INT_MIN, l = 0, r = height.size() - 1, area = 0, prevHeight;
        while(r - l > 0){
            area = (r-l)*min(height[l], height[r]);
            maxArea = max(area, maxArea);
            if(height[l] > height[r]){
                prevHeight = height[r];
                r--;
                while(prevHeight > height[r]) r--;
            }
            else if(height[l] < height[r]){
                prevHeight = height[l];
                l++;
                while(prevHeight > height[l]) l++;
            }
            else{
                l++;
                r--;
            }
        }
        return maxArea;
    }
};