#include <algorithm>
#include <climits>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    public:
    int getLargestOutlier(vector<int>& nums) {
        int size = (int)nums.size();
        // first为值，second为出现次数
        unordered_map<int, int> map;
        int sum = 0;
        for (int i = 0; i < size; i++) {
            map[nums[i]]++;
            sum += nums.at(i);
        }

        int ans = INT_MIN;
        for (auto x : nums) {
            map[x]--;
            if ((sum - x) % 2 == 0 && map[(sum-x) / 2] > 0) {
                ans = max(ans, x);
            }
            map[x]++;
        }
        return ans;
    }
};