#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";

        string input = countAndSay(n - 1);
        string output = "";

        for(int i = 0; i < input.length(); ) {
            char c = input[i];
            int count = 0;
            
            while(i < input.length() && input[i] == c) {
                count++;
                i++;
            }

            output += to_string(count) + c;
        }

        return output;
    }
};
