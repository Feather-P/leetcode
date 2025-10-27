#include <cstddef>
#include <vector>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long int sum = 0;
        int left = 0, right = 0;
        long long count = 0;
        while (right < nums.size()) {
            sum += nums.at(right);
            while (sum * (right - left + 1) >= k) {
                sum -= nums.at(left);
                left++;
            }
            count += right - left + 1;
            right++;
        }
        return count;
    }
};