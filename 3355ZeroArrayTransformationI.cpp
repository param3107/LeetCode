#include <vector>
using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries){
        int n = nums.size(), sum = 0;
        vector<int> check(n, 0);
        for(int i = 0; i < queries.size(); i++){
            check[queries[i][0]]++;
            if(queries[i][1] < n - 1) check[queries[i][1] + 1]--;
        }
        for(int i = 0; i < n; i++){
            sum += check[i];
            if(sum < nums[i]) return false;
        }
        return true;
    }
};