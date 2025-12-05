#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        // 计算前缀和
        int sum = 0;
        vector<int> sums(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            sum += nums.at(i);
            sums.at(i) = sum;
        }
        vector<int> ans(queries.size(),0);
        for (int i = 0; i < queries.size(); i++) {
            // 进行二分搜索
            int left = 0;
            int right = static_cast<int>(sums.size()) - 1;
            while (left <= right) {
                int mid = left + ((right - left) / 2);
                if (sums.at(mid) <= queries.at(i)) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            ans.at(i) = left;
        }
        return ans;
    }
};