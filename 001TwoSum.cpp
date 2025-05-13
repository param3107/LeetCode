#include <bits/stdc++.h>
using namespace std;
#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> initial(nums.size());
        for(int i = 0; i < nums.size(); i++){
            initial[i] = nums[i];
        }
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.size()-1;
        while(low < high){
            if(nums[low] + nums[high] == target) break;
            if(nums[low] + nums[high] > target) high--;
            else low++;
        }
        int first = INT_MIN, second = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(initial[i] == nums[low] || initial[i] == nums[high]){
                if(first == INT_MIN) first = i;
                else{
                    second = i;
                    break;
                }
            }
        }
        return {first, second};
    }
};