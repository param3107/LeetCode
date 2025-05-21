#include <vector>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x, mid = 0, ans = 0;
        long long sqr = 0;
        while(l <= r){
            mid = (l + r)/2;
            sqr = (long long) mid*mid;
            if(sqr == x) return mid;
            if(sqr > x) r = mid - 1;
            else{
                ans = mid;
                l = mid + 1;
            }
        }
        return ans;
    }
};