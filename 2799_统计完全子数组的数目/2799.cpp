#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
    public:
    int static countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> global_odd_set;
        int global_odd_count = 0;
        for (auto element : nums) {
            if (global_odd_set.find(element) == global_odd_set.end()) {
                global_odd_count++;
                global_odd_set.insert(element);
            }
        }
        // 得到全局的不同元素为global_odd_count
        int left = 0;
        int right = 0;
        unordered_map<int, int> curr_map;
        int ans = 0;
        while (right < nums.size()) {
            curr_map[nums.at(right)]++;
            while (curr_map.size() == global_odd_count) {
                if (curr_map[nums.at(left)] == 1) {
                    curr_map.erase(nums.at(left));
                } else {
                    curr_map.at(nums.at(left))--;
                }
                left++;
            }
            ans += left;
            right++;
        }
        return ans;
    }
};