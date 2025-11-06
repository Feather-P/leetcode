#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    public:
    static int maxOperations(vector<int>& nums, int k) {
        int operations = 0;
        // 哈希表fist为值，second为计数
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            // 去寻找哈希表的目标数字
            auto it = map.find(k - nums.at(i));
            // 如果找到了目标数字,并且减去1后不为负
            if (it != map.end() && map.at(k - nums.at(i)) > 0) {
                map.at(k - nums.at(i))--;
                operations++;
            } else {
                map[nums[i]]++;
            }
        }
        return operations;
    }
};