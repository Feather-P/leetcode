#include <vector>

using namespace std;


class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int product = 0;
        int count = 0;
        while (right < nums.size()) {
            if (right == 0) {
                product = nums.at(right);
            } else {
                product *= nums.at(right);
            }
            while (left <= right && !(product < k)) {
                product /= nums.at(left);
                left++;
            }
            count += right - left + 1;
            right++;
        }
        return count;
    }
};