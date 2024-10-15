    #include <bits/stdc++.h>
    using namespace std;

    class Solution {
    public:
        string solve(int i, string &s){
            int l = i, r = i;
            while(l >= 0 && r < s.length()){
                if(s[l] == s[r]){
                    l--; r++;
                }
                else{
                    l++; r--;
                    break;
                }
            }
            if(l < 0 || r >= s.length()){
                l++; r--;
            }
            return s.substr(l, r-l+1);
        }
        string solve(int i, int j, string &s){
            int l = i, r = j;
            while(l >= 0 && r < s.length()){
                if(s[l] == s[r]){
                    l--; r++;
                }
                else{
                    l++; r--;
                    break;
                }
            }
            if(l < 0 || r >= s.length()){
                l++; r--;
            }

            return s.substr(l, r-l+1);
        }
        string longestPalindrome(string s){
            if(s.length() == 1) return s;
            string ans = "", temp;
            if(s[0] == s[1]) ans = s.substr(0, 2);
            for(int i = 1; i < s.length() - 1; i++){
                if(s[i] == s[i+1]){
                    temp = solve(i, i+1, s);
                    if(temp.length() > ans.length()) ans = temp;
                }
                if(s[i-1] == s[i+1]){
                    temp = solve(i, s);
                    if(temp.length() > ans.length()) ans = temp;
                }
            }
            if(ans.length() == 0) return ans + s[0];
            return ans;
        }
    };