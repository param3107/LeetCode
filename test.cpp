#include <bits/stdc++.h>
using namespace std;

string solve(int i, int j, string s){
    int l = i, r = j;
    while(l >= 0 && r < s.length()){
        if(s[l] == s[r]){
            l--; r++;
        }
        else{
            l++; r--;
            break;
        }
    }
    if(l < 0 || r >= s.length()){
        l++; r--;
    }

    return s.substr(l, r-l+1);
}

int main(){
    int x = 'z';
    // cout << (x < 7.0111) << endl;
    cout << x << endl;
    return 0;
}