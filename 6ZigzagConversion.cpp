#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(s.length() <= numRows || numRows == 1) return s;
        string ans = "";
        int rep = 2*numRows - 2;
        int j = 0;
        while(j < s.length()){
            ans += s[j];
            j += rep;
        }
        bool flag;
        for(int i = 1; i < numRows-1; i++){
            int j = i;
            flag = true;
            while(j < s.length()){
                ans += s[j];
                if(flag){
                    j += rep - 2*i;
                }
                else j += 2*i;
                flag = !flag;
            }
        }
        j = numRows-1;
        while(j < s.length()){
            ans += s[j];
            j += rep;
        }
        return ans;
    }
};