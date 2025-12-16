#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    static long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long length = static_cast<int>(nums.size());
        sort(nums.begin(), nums.end());
        long long sum = 0;
        for (int i = 0; i < length; i++) {
            int up = binarySearchUpper(upper - nums.at(i), nums, i + 1);
            int lo = binarySearchLower(lower - nums.at(i), nums, i + 1);
            sum += up - lo;
        }
        return sum;
    }

private:
    // 此二分搜索寻找下届
    static int binarySearchLower(int&& target, vector<int>& data, int&& start) {
        int left = start;
        int right = static_cast<int>(data.size()) - 1;
        while (left <= right) {
            int mid = left + ((right - left) / 2);
            if (data.at(mid) < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
    static int binarySearchUpper(int&& target, vector<int>& data, int&& start) {
        int left = start;
        int right = static_cast<int>(data.size()) - 1;
        while (left <= right) {
            int mid = left + ((right - left) / 2);
            if (data.at(mid) <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};