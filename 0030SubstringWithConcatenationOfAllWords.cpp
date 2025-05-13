#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words){
    vector<int> result;
    if(words.empty() || s.empty()) return result;

    int word_len = words[0].length();
    int word_count = words.size();
    int total_len = word_len * word_count;

    if(s.length() < total_len) return result;
    

    unordered_map<string, int> freq;
    for(int i = 0; i < words.size(); i++){
        const string &word = words[i];
        freq[word]++;
    }

    for (int i = 0; i < word_len; i++) {
        int left = i, right = i, count = 0;
        unordered_map<string, int> window;

        while (right + word_len <= s.length()) {
            string word = s.substr(right, word_len);
            right += word_len;

            if (freq.count(word)){
                window[word]++;
                count++;

                while (window[word] > freq[word]) {
                    string left_word = s.substr(left, word_len);
                    window[left_word]--;
                    count--;
                    left += word_len;
                }

                if (count == word_count) {
                    result.push_back(left);
                }
            } else {
                window.clear();
                count = 0;
                left = right;
            }
        }
    }

    return result;
}
};