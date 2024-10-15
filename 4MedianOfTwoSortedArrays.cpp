#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) swap(nums1, nums2);
        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m, median = (m+n+1)/2;
        while(left <= right){
            int m1 = (left + right)/2;
            int m2 = median - m1;

            int l1 = (m1 == 0) ? INT_MIN : nums1[m1-1];
            int l2 = (m2 == 0) ? INT_MIN : nums2[m2-1];
            int r1 = (m1 == m) ? INT_MAX : nums1[m1];
            int r2 = (m2 == n) ? INT_MAX : nums2[m2];
        
            if(l1<=r2 && l2<=r1) {
                if((m+n)%2 != 0)
                    return max(l1,l2);
                else 
                    return (max(l1,l2)+min(r1,r2))/2.0;
            }
            else if(l1>r2) right = m1-1;
            else left = m1+1;
        }
        return 0.0;
    }
};