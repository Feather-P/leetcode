#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = 0;
        int current_length = 0;
        int max_length = 0;
        while (right < nums.size()) {
            //把右指针进入窗口
            current_length++;
            while (nums.at(left) < nums.at(right) - 2 * k) {
                current_length--;
                left++;
            }
            max_length = max(max_length, current_length);
            right++;
        }
        return max_length;
    }
};