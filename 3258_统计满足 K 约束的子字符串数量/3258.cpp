#include <string>

using namespace std;

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int left = 0, right = 0;
        int num_zero_count = 0;
        int count = 0;
        while (right < s.size()) {
            // Add the element at the right pointer to shift window
            if (s.at(right) == '0') {
                num_zero_count++;
            }
            while (left <= right && (num_zero_count > k && right - left + 1 - num_zero_count > k)) {
                if (s.at(left) == '0') {
                    num_zero_count--;
                }
                left++;
            }
            count += right - left + 1;
            right++;
        }
        return count;
    }
};