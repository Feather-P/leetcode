#include <vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int current_length = 0;
        int max_length = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (nums.at(right) != 1) {
                k--;
            }
            current_length++;
            while (k < 0) {
                if (nums.at(left) != 1) {
                    k++;
                }
                current_length--;
                left++;
            }
            max_length = max(max_length, current_length);
        }
        return max_length;
    }
};