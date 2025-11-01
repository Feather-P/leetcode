#include <vector>

using namespace std;

class Solution {
    public:
    int solve(vector<int>& nums, int goal) {
        int left = 0;
        int right = 0;
        int curr_sum = 0;
        int ans = 0;
        while (right < nums.size()) {
            curr_sum += nums.at(right);
            while (curr_sum >= goal && left < right) {
                curr_sum -= nums.at(left);
                left++;
            }
            ans += left;
            right++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if (goal == 0) {
            int ans = 0;
            int count = 0;
            for (int num : nums) {
                if (num == 0) {
                    count++;
                } else {
                    ans += count * (count + 1) / 2;
                    count = 0;
                }
            }
            ans += count * (count + 1) / 2;
            return ans;
        } else {
            return solve(nums, goal) - solve(nums, goal + 1);
        }
    }
};