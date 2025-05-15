#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums){
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        permutations(current, nums, ans, used);
        return ans;
    }
private:
    void permutations(vector<int> &current, vector<int> &options, vector<vector<int>> &ans, vector<bool> &used){
        if(current.size() == options.size()){
            ans.push_back(current);
            return;
        }
        for(int i = 0; i < options.size(); i++){
            if(used[i]) continue;
            if (i > 0 && options[i] == options[i - 1] && !used[i - 1]) continue;
            used[i] = true;
            current.push_back(options[i]);
            permutations(current, options, ans, used);
            current.pop_back();
            used[i] = false;

        }
        return;
    }
};
