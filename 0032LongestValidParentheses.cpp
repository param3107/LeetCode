#include <iostream>
#include <stack>
#include <string>
using namespace std;


class Solution {
    public:
    int longestValidParentheses(string s){
        stack<int> st;
        int maxLen = 0;
        int lastInvalid = -1;
    
        for (int i = 0; i < s.length(); ++i){
            if(s[i] == '('){
                st.push(i);
            } 
            else{
                if(st.empty()){
                    lastInvalid = i;  
                } 
                else{
                    st.pop();  
                    if(st.empty()){
                        maxLen = max(maxLen, i - lastInvalid);
                    } 
                    else {    
                        maxLen = max(maxLen, i - st.top());
                    }
                }
            }
        }
        return maxLen;
    }
    };