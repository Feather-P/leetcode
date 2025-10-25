#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_count = 0;
        int length = 1;
        int zeros = 0;
        int left = 0, right = 0;
        while (right < nums.size()) {
            // 当右边是1时，无脑吃
            if (nums.at(right) == 1) {
                length++;
                right++;
                max_count = max(max_count, length);
            } else {
            //当右边是0时，检查是否吃得下，吃不下就挪左指针直到吃得下为止
                if (zeros < 1) {
                    right++;
                    length++;
                    zeros++;
                } else {
                    if (nums.at(left) == 0) {
                        zeros--;
                        length--;
                        left++;
                    } else {
                        length--;
                        left++;
                    }
                }
            }
        }
        return max_count;
    }
};