#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() > haystack.length()) return -1;
        int ptr = 0, ans = -1;
        for(int i = 0; i < haystack.length(); i++){
            if(haystack[i] == needle[ptr]){
                if(ptr == 0) ans = i;
                ptr++;
                if(ptr == needle.length()) return ans;
            }
            else{
                ptr = 0;
                if(ans != -1){
                    i = ans;
                    ans = -1;
                }
            }
        }
        return -1;
    }
};