#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int index[95];
        for(int i = 0; i < 95; i++) index[i] = -1;
        int Max = 0, start = 0;
        for(int i = 0; i < s.length(); i++){
            if(index[s[i]-' '] != -1){
                start = start > index[s[i]-' '] ? start : index[s[i]-' ']+1;
            }
            index[s[i]-' '] = i;
            Max = max(Max, i - start+1);
        }
        return Max;        
    }
};