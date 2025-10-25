#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        // 先对输入数组进行排序
        int left=0, right=0;
        int max_length = 0;
        int length = 0;
        for (right = 0; right < nums.size(); right++) {
            length++; // 将right指向的元素加入窗口(计算长度+1)
            while ((long long)nums.at(left) * k < nums.at(right)) { // 如果不符合条件
                length--; // 将left指向的元素移出窗口(计算长度-1)
                left++; // 左指针向右移动一个
            }
            // 此时可以保证length是有效值
            max_length = max(max_length, length);
        }
        return nums.size() - max_length;
    }
};