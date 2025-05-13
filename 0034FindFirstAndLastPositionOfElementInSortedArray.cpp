#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            int start = 0;
            int end = nums.size() - 1;
            vector<int> ans = {-1, -1};
            while(start <= end){
                int mid = (start + end)/2;
                if(nums[mid] == target){
                    int l = start, h = mid, lowerEnd;
                    while(l <= h){
                        lowerEnd = (l + h)/2;
                        if(nums[lowerEnd] == target){
                            ans[0] = lowerEnd;
                            h = lowerEnd - 1;
                        }
                        else{
                            l = lowerEnd + 1;
                        }
                    }

                    l = mid, h = end;
                    int higherEnd;
                    while(l <= h){
                        higherEnd = (l + h)/2;
                        if(nums[higherEnd] == target){
                            ans[1] = higherEnd;
                            l = higherEnd + 1;
                        }
                        else{
                            h = higherEnd - 1;
                        }
                    }
                    return ans;
                }
                else if(nums[mid] < target) start = mid + 1;
                else end = mid - 1; 
            }
            return ans;
        }
    };
