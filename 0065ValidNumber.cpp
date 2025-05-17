#include <string>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        bool isSign = false, isDot = false, isExp = false, isNum = false;
        if(s[0] == '+' || s[0] == '-'){
            isSign = true;
            s.erase(s.begin());
        }
        if(!s.length()) return false;
        for(int i = 0; i < s.size(); i++){
            if(s[i] <= '9' && s[i] >= '0'){
                isNum = true;
                continue;
            };
            if(s[i] == '.'){
                if(isDot) return false;
                if(isExp) return false;
                isDot = true;
                if(s.size() == 1) return false;
            }
            else if(s[i] == 'e' || s[i] == 'E'){
                if(isExp) return false;
                if(!isNum) return false;
                isExp = true;
                if(i == s.size() - 1) return false;
                if(s[i+1] == '+' || s[i+1] == '-'){
                    s.erase(s.begin() + 1  + i);
                    if(i == s.size() - 1) return false;
                };
                
            }
            else return false;
        }
        return true;
    }
};