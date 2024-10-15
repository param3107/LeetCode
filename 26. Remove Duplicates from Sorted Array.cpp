#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0, current = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != current){
                nums[k] = nums[i];
                k++;
                current = nums[i];
            }
        }
        return k;
    }
};