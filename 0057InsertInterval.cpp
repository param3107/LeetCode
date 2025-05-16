#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0;
        while(i < intervals.size()){
            if(intervals[i][1] < newInterval[0]){
                ans.push_back(intervals[i]);
                i++;
            }
            else break;
        }
        ans.push_back(newInterval);
        int last = ans.size() - 1;
        while(i < intervals.size()){
            if(intervals[i][0] <= ans[last][1]){
                ans[last][0] = min(intervals[i][0], ans[last][0]);
                ans[last][1] = max(intervals[i][1], ans[last][1]);
            }
            else{
                ans.push_back(intervals[i]);
                last++;
            }
            i++;
        }
        return ans;
    }
};