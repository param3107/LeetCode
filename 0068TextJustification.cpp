#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth){
        vector<string> result;
        int index = 0, n = words.size();

        while(index < n){
            int totalChars = words[index].size();
            int last = index + 1;

            while(last < n && totalChars + 1 + words[last].size() <= maxWidth){
                totalChars += 1 + words[last].size();
                last++;
            }

            int numWords = last - index;
            int numSpaces = maxWidth - totalChars + (numWords - 1);
            string line;

            if(last == n || numWords == 1){
                for(int i = index; i < last; i++){
                    line += words[i];
                    if(i != last - 1) line += " ";
                }
                line += string(maxWidth - line.size(), ' ');
            } 
            else{   
                int spacesPerSlot = numSpaces / (numWords - 1);
                int extraSpaces = numSpaces % (numWords - 1);

                for(int i = index; i < last - 1; ++i){
                    line += words[i];
                    line += string(spacesPerSlot + (i - index < extraSpaces ? 1 : 0), ' ');
                }
                line += words[last - 1];
            }
            result.push_back(line);
            index = last;
        }
        return result;
    }
};
