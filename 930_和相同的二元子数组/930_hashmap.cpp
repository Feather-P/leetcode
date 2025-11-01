#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0;
        unordered_map<int, int> cnt;
        int ans = 0;
        for (int num : nums) {
            cnt[sum]++;
            sum += num;
            ans += cnt[sum - goal];
        }
        return ans;
    }
};