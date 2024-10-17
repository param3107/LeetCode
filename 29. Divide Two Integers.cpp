#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == INT_MIN){
            if(dividend == INT_MIN) return 1;
            return 0;
        }
        if(dividend == INT_MIN){
            if(divisor == 1) return INT_MIN;
            if(divisor == -1) return INT_MAX;
        }
        bool sign = 0;
        if(dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0) sign = 1;
        int count = 0;
        divisor = abs(divisor);
        int temp = divisor;
        if(dividend < 0){
            while(dividend <= -divisor){
                dividend = dividend + divisor;
                count++;
                while(dividend <= -temp){
                    count = count + count;
                    dividend = dividend + temp;
                    if(dividend <= -temp) temp = temp + temp;
                }
            }
            if(sign) return -count;
            return count;
        }
        dividend = abs(dividend);
        while(dividend >= divisor){
            dividend = dividend - divisor;
            count++;
            while(dividend >= temp){
                count = count + count;
                dividend = dividend - temp;
                if(dividend >= temp) temp = temp + temp;
            }
        }
        if(sign) return -count;
        return count;
    }
};