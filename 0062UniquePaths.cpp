#include <algorithm>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1, denom = 1;
        if(m < n) swap(m, n);
        for(int i = 1; i < n; i++){
            ans *= (m + n - 1 - i);
            denom *= i;
            if(ans % denom == 0){
                ans /= denom;
                denom = 1;
            }
        }
        ans /= denom;   
        return ans;
    }
};