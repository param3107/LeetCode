#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0, minDeviation = INT_MAX;
        for(int i = 0; i < nums.size() - 2; i++){
            int l = i + 1, r = nums.size() - 1;
            while(r > l){
                if(nums[i] + nums[l] + nums[r] > target){
                    if(abs(nums[i] + nums[l] + nums[r] - target) < minDeviation){
                        ans = nums[i] + nums[l] + nums[r];
                        minDeviation = abs(nums[i] + nums[l] + nums[r] - target);
                    }
                    r--;
                }
                else if(nums[i] + nums[l] + nums[r] < target){
                    if(abs(nums[i] + nums[l] + nums[r] - target) < minDeviation){
                        ans = nums[i] + nums[l] + nums[r];
                        minDeviation = abs(nums[i] + nums[l] + nums[r] - target);
                    }
                    l++;
                }
                else{
                    ans = ans = nums[i] + nums[l] + nums[r];
                    return ans;
                }
            }
        }
        return ans;
    }
};