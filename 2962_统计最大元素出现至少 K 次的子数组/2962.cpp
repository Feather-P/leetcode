#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    long long countSubarrays(vector<int>& nums, int k) {
        int       max_num = *max_element(nums.begin(), nums.end());
        int       left    = 0;
        int       right   = 0;
        int       count   = 0;
        long long ans     = 0;
        while (right < nums.size()) {
            if (nums.at(right) == max_num) {
                count++;
            }
            while (count >= k) {
                if (nums.at(left) == max_num) {
                    count--;
                }
                left++;
            }
            ans += left;
            right++;
        }
        return ans;
    }
};