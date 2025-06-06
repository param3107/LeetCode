#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(sum < 0) sum = nums[i];
            else sum += nums[i];
            ans = max(sum, ans);
        }
        return ans;
    }
};