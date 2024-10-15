#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.size() < 2) return false;
        stack<char> Stack;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') Stack.push(s[i]);
            else{
                if(Stack.empty()) return false;
                if(s[i] == ')' && Stack.top() == '(' || s[i] == ']' && Stack.top() == '[' || s[i] == '}' && Stack.top() == '{') Stack.pop();
                else return false;
            }
        }
        if(!Stack.empty()) return false;
        return true;
    }
};