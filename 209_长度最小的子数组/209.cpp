#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int current_length = 0;
        int sum = 0;
        int min_length = numeric_limits<int>::max();
        while (right < nums.size()) {
            sum += nums.at(right);
            current_length++;
            while (sum >= target) {
                min_length = min(min_length, current_length);
                current_length--;
                sum -= nums.at(left);
                left++;
            }
            right++;
        }
        return min_length == numeric_limits<int>::max() ? 0 : min_length;
    }
};