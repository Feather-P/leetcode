#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int static maximumCount(vector<int>& nums) {
        auto first_non_negative = lower_bound(nums.begin(), nums.end(), 0);
        auto first_positive = upper_bound(nums.begin(), nums.end(), 0);
        
        int negative_count = first_non_negative - nums.begin();
        int positive_count = nums.end() - first_positive;
        
        return max(negative_count, positive_count);
    }
};
