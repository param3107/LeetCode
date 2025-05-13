#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        // long long x = y;
        if(x < 0) return false;
        if (x == 0) return true;
        //     int digits = log10(x) + 1;
        // for(int i = 0; i < (digits+1)/2; i++){
        //     int left = (x % (long long)(pow(10, digits - i)))/(long long)(pow(10, digits - i - 1));
        //     int right = (x % (long long)(pow(10, i + 1)))/(long long)(pow(10, i));
        //     if(left != right) return false;
        // }
        string s = "";
        while(x != 0){
            s += char('0' + (x % 10));
            x /= 10;
        }
        int l = s.length();
        for(int i = 0; i < (s.length() + 1)/2; i++){
            if(s[l - i - 1] != s[i]) return false;
        }
        return true;
    }
};