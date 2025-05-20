#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    const int MOD = 1e9 + 7;
    vector<vector<int>> validStates;
    unordered_map<int, vector<int>> transitions;

    void generateStates(int m, vector<int>& curr, int lastColor) {
        if (curr.size() == m) {
            int code = 0;
            for (int c : curr)
                code = code * 3 + c;
            validStates.push_back(curr);
            return;
        }
        for (int color = 0; color < 3; ++color) {
            if (color != lastColor) {
                curr.push_back(color);
                generateStates(m, curr, color);
                curr.pop_back();
            }
        }
    }

    int stateToCode(const vector<int>& state) {
        int code = 0;
        for (int c : state)
            code = code * 3 + c;
        return code;
    }

    bool isCompatible(const vector<int>& a, const vector<int>& b) {
        for (int i = 0; i < a.size(); i++)
            if (a[i] == b[i])
                return false;
        return true;
    }

public:
    int colorTheGrid(int m, int n) {
        vector<int> temp;
        generateStates(m, temp, -1);

        int total = validStates.size();
        vector<int> codes(total);
        for (int i = 0; i < total; ++i)
            codes[i] = stateToCode(validStates[i]);

        for (int i = 0; i < total; ++i) {
            for (int j = 0; j < total; ++j) {
                if (isCompatible(validStates[i], validStates[j])) {
                    transitions[codes[i]].push_back(codes[j]);
                }
            }
        }

        unordered_map<int, int> dp;
        for (int i = 0; i < total; ++i)
            dp[codes[i]] = 1;

        for (int col = 1; col < n; ++col) {
            unordered_map<int, int> newDp;
            for (auto& [prevCode, count] : dp) {
                for (int nextCode : transitions[prevCode]) {
                    newDp[nextCode] = (newDp[nextCode] + count) % MOD;
                }
            }
            dp = move(newDp);
        }

        int result = 0;
        for (auto& [_, count] : dp)
            result = (result + count) % MOD;

        return result;
    }
};
