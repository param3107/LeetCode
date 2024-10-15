#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if(x == 0) return x;
        int ans = 0;
        int sign = x/abs(x);
        x = abs(x);
        while(x){
            if(ans <= 214748364.7 && ans >= -214748364.8) ans *= 10;
            else return 0;
            ans += x%10;
            x /= 10;
        }
        
        ans *= sign;
        return ans;
    }
};