#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> map;
        int score = 0;
        int max_score = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            // 把右指针元素加入窗口
            if (map.find(nums.at(right)) != map.end()) {
                map.at(nums.at(right))++;
            } else {
                map.emplace(nums.at(right), 1);
            }
            score += nums.at(right);
            while (map.at(nums.at(right)) > 1) {
                if (map.at(nums.at(left)) == 1) {
                    map.erase(nums.at(left));
                } else {
                    map.at(nums.at(left))--;
                }
                score -= nums.at(left);
                left++;
            }
            max_score = max(max_score, score);
        }
        return max_score;
    }
};