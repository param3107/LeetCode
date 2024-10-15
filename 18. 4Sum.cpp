#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans = {};
        if(nums.size() < 4) return ans;
        int l = 0, r = 0, iprev = INT_MAX, jprev = INT_MAX, lprev = INT_MAX, rprev = INT_MAX;
        long long int sum = 0;
        for(int i = 0;  i < nums.size() - 3; i++){
            if(nums[i] == iprev) continue;
            jprev = INT_MAX;
            for(int j = i + 1; j < nums.size() - 2; j++){
                if(nums[j] == jprev) continue;
                l = j + 1, r = nums.size() - 1;
                while(r > l){
                    sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[l] + (long long)nums[r];
                    if(sum > target) r--;
                    else if(sum < target) l++;
                    else{
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        rprev = nums[r], lprev = nums[l];
                        if(nums[r] == nums[l]) break;
                        while(rprev == nums[r]) r--;
                        while(lprev == nums[l]) l++;
                    }
                }
                jprev = nums[j];
            }
            iprev = nums[i];
        }
        return ans;
    }
};