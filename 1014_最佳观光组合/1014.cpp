#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // 定义了values[i] + values[j] + i - j为对数的值
        // 那么其实要保证 i < j 时,对于每个可能的j，使values[i]+i最大即可
        int m = INT_MIN;
        int ans = INT_MIN;
        for (int j = 0; j < values.size(); j++) {
            ans = max(ans, m + values.at(j) - j);
            m = max(m, values.at(j) + j);
        }
        return ans;
    }
};