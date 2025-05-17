#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0, sum = 0;
        for(int i = digits.size()-1; i >= 0; i--){
            sum = digits[i] + 1;
            digits[i] = sum % 10;
            carry = sum / 10;
            if(carry == 0) break; 
        }
        if(carry) digits.insert(digits.begin(), carry);
        return digits;
    }
};