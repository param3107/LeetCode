#include <bits/stdc++.h>
using namespace std;

void func(vector<string> &ans, string &current, int left, int right, int carry){
    if(carry < 0) return;
    if(left == 0 && right == 0){
        ans.push_back(current);
        return;
    }
    current.push_back('(');
    string s1 = current;
    current.pop_back();
    current.push_back(')');
    string s2 = current;
    current.pop_back();
    if(left) func(ans, s1, left - 1, right, carry + 1);
    if(right) func(ans, s2, left, right - 1, carry - 1);
    return;
}
vector<string> generateParenthesis(int n) {
    vector<string> ans = {};
    string str = "";
    func(ans, str , n, n, 0);
    return ans;        
}

int main(){
    int n;
    cin >> n;
    vector<string> ans = generateParenthesis(n);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}
    