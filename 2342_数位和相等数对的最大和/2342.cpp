#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    public:
    static auto numberSum(int n) -> int {
        int sum = 0;
        while (n / 10 != 0) {
            sum += n % 10;
            n /= 10;
        }
        sum += n;
        return sum;
    }
    static int maximumSum(vector<int>& nums) {
        // 哈希表的first为数位和，second为下标
        unordered_map<int, int> map;
        int ans = -1;
        for (int i = 0; i < nums.size(); i++) {
            auto it = map.find(numberSum(nums.at(i)));
            // 如果在map中找到数位和为指定数的数
            if (it != map.end()) {
                // 更新答案
                ans = max(ans, nums.at(i) + nums.at(it->second));
                // 如果要存入的数的值比原来值大再更新哈希表
                if (nums.at(map[numberSum(nums.at(i))]) < nums.at(i)) {
                    map[numberSum(nums.at(i))] = i;
                }
            } else {
                map[numberSum(nums.at(i))] = i;
            }
        }
        return ans;
    }
};