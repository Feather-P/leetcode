#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }
        
        vector<bool> seen(256, false);
        int left = 0, right = 0;
        int maxLen = 0;
        
        while (right < s.size()) {
            // 如果没见过，扩展
            if (!seen[s[right]]) {
                seen[s[right]] = true;
                right++;
                maxLen = max(maxLen, right - left);
            } else {
                // 如果见过，收缩左
                seen[s[left]] = false;
                left++;
            }
        }
        return maxLen;
    }
};