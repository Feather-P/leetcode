#include <vector>
#include <unordered_map>

using namespace std;

/// 不妨尝试找到所有的j - i == nums[j] - nums[i] 的“好数对”
/// 移项后可以得到： nums[i] - i == nums[j] - j
/// 使用“枚举左维护右”的枚举办法来换取更低的时间复杂度

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long good_pairs = 0;
        int size = (int)nums.size();
        // first定义为nums[i] - i的值，second定义为等于该值的数减去其下标的数量(nums[i] - i)
        unordered_map<int, int> map;
        for (int i = 0; i < size; i++) {
            // 先加“好数对”的数目：小于i的数中nums[j] - j == nums [i] - i 的数目即为和当前遍历的数成对的对数
            good_pairs += map[nums[i] - i];
            // 再把哈希表中记录数的数量加1
            map[nums[i] - i] ++;
        }
        // 因为可能会存在大数超出int的表示范围，开long long防止溢出
        return ((long long)size * (size - 1) / 2) - good_pairs;
    }
};