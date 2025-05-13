#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int sp = s.length()-1, pp = p.length()-1;
        while(true){
            if(p[pp] >= 97 && p[pp] <= 122){
                if(s[sp] != p[pp]) return false;
            sp--; pp--;
            }
            elif(p[pp] == '.'){
                sp--, pp--;
            }
            else{
                char prev = p[pp+1];
                if(pp == 0){
                    if(sp == -1) return true;
                    if(prev == '.') return true;
                    while(sp != -1){
                        if(s[sp] == prev) sp--;
                        else break;
                    }
                    if(sp == -1) return true;
                    else return false;
                }
                if(prev != '.'){
                    if(sp == -1) return false;
                    scount = 0;
                    pcount = 0;
                    pp--;
                    while(p[pp] == prev || p[pp] == '*'){
                        if(p[pp] == '*') continue;
                        pp--;
                        pcount++;
                        if(pp == -1) break;
                    }
                    while(s[sp] == prev){
                        sp--;
                        scount++;
                        if(sp == -1) break;
                    }

                }
            }
        }
    }
};