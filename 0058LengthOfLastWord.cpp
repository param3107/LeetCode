#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        bool isOn = false;
        int length = 0;
        for(int i = s.length() - 1; i >= 0; i--){
            if(s[i] == ' '){
                if(isOn) return length;
                else continue;
            }
            isOn = true;
            length++;
        }
        return length;
    }
};