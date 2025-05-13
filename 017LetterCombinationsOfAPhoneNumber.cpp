#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        map<char, string> letters;
        vector<string> ans = {""}, newAns = {""};
        string newStr = "";
        letters['2'] = "abc", letters['3'] = "def", letters['4'] = "ghi", letters['5'] = "jkl", letters['6'] = "mno", letters['7'] = "pqrs", letters['8'] = "tuv", letters['9'] = "wxyz";
        for(int i = 0; i < digits.length(); i++){
            string lets = letters[digits[i]];
            newAns.clear();
            for(int j = 0; j < ans.size(); j++){
                for(int k = 0; k < lets.length(); k++){
                    newStr = ans[j];
                    newStr.push_back(lets[k]);
                    newAns.push_back(newStr);
                }
            }
            ans = newAns;
        }            
        return newAns;
    }
};