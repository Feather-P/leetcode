#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            // 如果在map中找到了就直接返回
            auto it = map.find(target - nums.at(i));
            if (it != map.end()) {
                return {i, it->second};
            };
            map[nums.at(i)] = i;
        }
        return {};
    }
};