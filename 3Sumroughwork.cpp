#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp = {};
        int rprev = 0, lprev = 0, rcount = 0, lcount = 0;
        for(int i = 0; i < nums.size() - 2; i++){
            if(nums[i] > 0) break;
            int l = i + 1, r = nums.size() - 1;
            while(r > l){
                if(nums[i] + nums[l] + nums[r] > 0) r--;
                else if(nums[i] + nums[l] + nums[r] < 0) l++;
                else{
                    temp = {nums[i], nums[l], nums[r]};
                    if(nums[l] == nums[r]){
                        for(int j = 0; j < ((r-l+1)*(r-l))/2; j++){
                            ans.push_back(temp);
                        }
                        break;
                    }
                    rprev = nums[r], lprev = nums[l];
                    rcount = 0, lcount = 0;
                    while(r > l && rprev == nums[r]){
                        rcount++; r--;
                    }
                    while(r > l && lprev == nums[l]){
                        lcount++; l++;
                    }
                    if(nums[r] == lprev) lcount++;
                    for(int j = 0; j < lcount*rcount; j++){
                        ans.push_back(temp);
                    }
                }
            }
        }
        return ans;        
    }
};