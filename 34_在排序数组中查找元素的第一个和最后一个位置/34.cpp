#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1;
        int last = -1;
        int left = 0;
        int right = (int)nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums.at(mid) < target) {
                left = mid + 1;
            } else if (nums.at(mid) > target) {
                right = mid - 1;
            } else {
                // mid 等于 target的情况
                first = mid;
                right = mid - 1;
            }
        }
        left = 0;
        right = (int)nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                // mid 等于 target的情况
                last = mid;
                left = mid + 1;
            }
        }
        vector<int> ans;
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};