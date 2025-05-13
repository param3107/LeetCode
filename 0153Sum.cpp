#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp = {};
        int rprev = 0, lprev = 0, iprev = INT_MIN;
        for(int i = 0; i < nums.size() - 2; i++){
            if(nums[i] > 0) break;
            if(nums[i] == iprev) continue;
            int l = i + 1, r = nums.size() - 1;
            while(r > l){
                if(nums[i] + nums[l] + nums[r] > 0) r--;
                else if(nums[i] + nums[l] + nums[r] < 0) l++;
                else{
                    ans.push_back({nums[i], nums[l], nums[r]});
                    rprev = nums[r], lprev = nums[l];
                    if(nums[l] == nums[r]) break;
                    while(nums[r] == rprev) r--;
                    while(nums[l] == lprev) l++;
                }
            }
            iprev = nums[i];
        }
        return ans;        
    }
};