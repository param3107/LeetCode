#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common = strs[0], temp = "", s = "";
        for(int i = 0; i < strs.size(); i++){
            s = strs[i];
            temp = "";
            for(int i = 0; i < s.length() && i < common.length(); i++){
                if(s[i] != common[i]) break;
                temp.push_back(s[i]);
            }
            common = temp;
            if(common == "") break;
        }
        return common;
    }
};