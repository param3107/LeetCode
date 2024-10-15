#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> Values;
        Values['I'] = 1, Values['V'] = 5, Values['X'] = 10, Values['L'] = 50, Values['C'] = 100, Values['D'] = 500, Values['M'] = 1000;
        int ans = 0, prev = INT_MAX;
        for(int i = 0; i < s.length(); i++){
            if(prev < Values[s[i]]) ans = ans + Values[s[i]] - 2*prev;
            else ans = ans + Values[s[i]];
            prev = Values[s[i]];
        }
        return ans;
    }
};