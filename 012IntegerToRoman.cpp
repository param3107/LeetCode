#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        map<int, char> symbols;
        symbols[1] = 'I', symbols[5] = 'V', symbols[10] = 'X', symbols[50] = 'L', symbols[100] = 'C', symbols[500] = 'D', symbols[1000] = 'M';
        int places = -1, temp = num;
        while(temp){
            places++;
            temp = temp / 10;
        }
        while(places >= 0){
            int digit = (num % (int)(pow(10, places+1)))/((int) pow(10, places));
            if (digit >= 5 && digit <= 8){
                ans.push_back(symbols[(int)5*pow(10, places)]);
                digit -= 5;
            }
            if(digit >= 1 && digit <= 3){
                for(int j = 0; j < digit; j++) ans.push_back(symbols[(int)pow(10, places)]);
            }
            if(digit == 4){
                ans.push_back(symbols[(int)pow(10, places)]);
                ans.push_back(symbols[(int)5*pow(10, places)]);
            }
            if(digit == 9){
                ans.push_back(symbols[(int)pow(10, places)]);
                ans.push_back(symbols[(int)10*pow(10, places)]);
            }
            places--;
        }
        return ans;
    }
};