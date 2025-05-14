#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> preMaxes(height.size(), 0), postMaxes(height.size(), 0);
        int preMax = -1, postMax = -1, size = height.size();
        for(int i = 0; i < size; i++){
            preMax = max(preMax, height[i]);
            preMaxes[i] = preMax;
            postMax = max(postMax, height[size - i - 1]);
            postMaxes[size - i - 1] = postMax;
        }
        int water = 0;
        for(int i = 0;  i < size; i++){
            water += min(preMaxes[i], postMaxes[i]) - height[i]; 
        }
        return water;
    }
};