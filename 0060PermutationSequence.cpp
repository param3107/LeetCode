#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n+1, 0);
        int product = 1;
        for(int i = 0; i <+ n; i++){
            factorial[i] = product;
            product *= i + 1;
        }
        string nums = "", ans = "";
        for(int i = 1; i <= n; i++) nums += i + '0';
        int times = 0;
        while(k){
            times = k/factorial[nums.size() - 1];
            k -= times*factorial[nums.size() - 1];
            if(k){
                ans += nums[times];
                nums.erase(nums.begin() + times);
            }
            else{
                ans += nums[times - 1];
                nums.erase(nums.begin() + times - 1);
                for(int i = nums.size() - 1; i >= 0; i--) ans += nums[i];
            }
        }
        return ans;
    }
};