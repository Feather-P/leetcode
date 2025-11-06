#include <unordered_map>
#include <vector>
class Solution {
public:
    static std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        const int INTENTION_BUCKET_SIZE = 10000;
        map.bucket_size(INTENTION_BUCKET_SIZE);

        int purposed_value = 0;

        for (int i = 0; i<nums.size(); i++) {
            int num = nums[i];
            purposed_value = target - num;
            auto map_value = map.find(purposed_value);
            if (map_value != map.end()) {
                std::vector<int> ans = {i, map_value->second};
                return ans;
            } else {
                map.emplace(num, i);
            }
        }
        std::vector<int> null = {0,0};
        return null;
    }
};