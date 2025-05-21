#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> words;
        string word = "";
        for(int i = 0; i < path.size(); i++){
            if(path[i] == '/'){
                if(word.size()){
                    if(word == "."){}
                    else if(word == ".."){
                        if(words.size()) words.erase(words.end());
                    } 
                    else words.push_back(word);
                    word = "";  
                }
                continue;
            };
            word += path[i];
        }
        if(word.size()){
            if(word == "."){}
            else if(word == ".."){
                if(words.size()) words.erase(words.end());
            } 
            else words.push_back(word);
            word = "";  
        }
        if(!words.size()) return "/";
        string ans = "";
        for(int i = 0; i < words.size(); i++) ans += '/' + words[i];
        return ans;
    }
};