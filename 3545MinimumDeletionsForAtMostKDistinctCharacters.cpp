#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDeletion(string s, int k) {
        vector<int> freq(26, 0);
        for(int i = 0; i < s.length(); i++){
            freq[s[i]-'a']++;
        }
        sort(freq.begin(), freq.end());
        int sum = 0, end = s.length() - k;
        
        for(int i = 26 - k - 1; i >= 0; i--){
            sum += freq[i];
        }
        return sum;
    }
};