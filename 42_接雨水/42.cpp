#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    static auto trap(vector<int>& height) -> int {
        int size = static_cast<int>(height.size());
        vector<int> left_prefix_sum(size);
        vector<int> right_prefix_sum(size);
        left_prefix_sum[0] = height[0];
        for (int i = 1; i < size; i++) {
            left_prefix_sum[i] = max(height[i], left_prefix_sum[i-1]);
        }
        right_prefix_sum[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            right_prefix_sum[i] = max(height[i], right_prefix_sum[i+1]);
        }
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += min(left_prefix_sum[i], right_prefix_sum[i]) - height[i];
        }
        return sum;
    }
};