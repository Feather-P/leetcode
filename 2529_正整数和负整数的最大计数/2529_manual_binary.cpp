#include <vector>

using namespace std;

class Solution {
public:
    enum Orient {
        LAST_NEGATIVE,  // 找最后一个负数
        FIRST_POSITIVE  // 找第一个正数
    };
    
    int binarySearch(vector<int>& nums, Orient orient) {
        int left = 0;
        int right = (int)nums.size() - 1;
        int ans = -1;
        
        while (left <= right) {
            int mid = left + ((right - left) / 2);
            
            if (orient == LAST_NEGATIVE) {
                // 找最后一个负数
                if (nums[mid] < 0) {
                    ans = mid;        // 记录当前位置
                    left = mid + 1;   // 继续向右找
                } else {
                    right = mid - 1;  // 向左找
                }
            } else { // FIRST_POSITIVE
                // 找第一个正数
                if (nums[mid] > 0) {
                    ans = mid;        // 记录当前位置
                    right = mid - 1;  // 继续向左找
                } else {
                    left = mid + 1;   // 向右找
                }
            }
        }
        return ans;
    }
    
    int maximumCount(vector<int>& nums) {
        int last_negative_index = binarySearch(nums, LAST_NEGATIVE);
        int first_positive_index = binarySearch(nums, FIRST_POSITIVE);
        
        int negative_count = (last_negative_index == -1) ? 0 : last_negative_index + 1;
        int positive_count = (first_positive_index == -1) ? 0 : (int)nums.size() - first_positive_index;
        
        return max(negative_count, positive_count);
    }
};
