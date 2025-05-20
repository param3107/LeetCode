#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int size = min(a.size(), b.size()), carry = 0, sum = 0;
        for(int pointer = 0; pointer < size; pointer ++){
            sum = a[a.size() - pointer - 1] - '0' + b[b.size() - pointer - 1] - '0' + carry;
            carry = sum/2; 
            ans += (sum % 2) + '0';
        }
        int pointer = a.size() - size - 1;
        while(pointer >= 0){
            sum = a[pointer] - '0' + carry;
            carry = sum/2; 
            ans += (sum % 2) + '0';
            pointer--;
        }
        pointer = b.size() - size - 1;
        while(pointer >= 0){
            sum = b[pointer] - '0' + carry;
            carry = sum/2; 
            ans += (sum % 2) + '0';
            pointer--;
        }
        if(carry) ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};