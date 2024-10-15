#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s){
        int ans = 0;
        if(s.length() == 0) return ans;
        int digits = 0;
        bool isPositive = true;
        bool signSet = false;
        bool spaceIgnored = false;
        char c;
        for(int i = 0; i < s.length(); i++){
            c = s[i];
            if(c == ' '){if(spaceIgnored){
                if(!isPositive) return - ans;
                return ans;
                }
            }
            else if(c >= '0' && c <= '9'){
                if(digits >= 9){
                    long long temp = ans;
                    temp = temp*10;
                    temp = temp + (c - '0');
                    if(temp > INT_MAX){
                        if(!isPositive) return INT_MIN;
                        return INT_MAX;
                    }
                    if(temp == INT_MAX){
                        if(!isPositive) return - INT_MAX;
                        return INT_MAX;
                    }
                }
                spaceIgnored = true;
                signSet = true;
                ans = ans*10;
                ans = ans + (c - '0');
                digits++;
            }
            else if(c == '+' || c == '-'){
                if(signSet){
                    if(!isPositive) return - ans;
                    return ans;
                }
                isPositive = (c == '+');
                signSet = true;
                spaceIgnored = true;
            }
            else{
                if(!isPositive) return - ans;
                return ans;
            }
        }
        if(!isPositive) return - ans;
        return ans;
    }
};
