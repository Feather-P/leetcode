#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int curr_length = 0, max_length = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            // 加入窗口
            if (freq.find(nums.at(right)) != freq.end()) {
                freq.at(nums.at(right))++;
            } else {
                freq.emplace(nums.at(right), 1);
            }
            curr_length++;
            while (freq.at(nums.at(right)) > k) {
                if (freq.at(nums.at(left)) == 1) {
                    freq.erase(nums.at(left));
                } else {
                    freq.at(nums.at(left))--;
                }
                left++;
                curr_length--;
            }
            max_length = max(max_length, curr_length);
        }
        return max_length;
    }
};