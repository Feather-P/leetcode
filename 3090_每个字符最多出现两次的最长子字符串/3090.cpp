#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> seen_times;
        int left = 0, right = 0;
        int length = 0, max_lenth = 0;
        while (right < s.size()) {
            // 如果能在map中找到
            if (seen_times.find(s.at(right)) != seen_times.end()) {
                // 如果还没见到两次，可以右移动
                if (seen_times.at(s.at(right)) < 2) {
                    seen_times.at(s.at(right))++;
                    right++;
                    length++;
                    max_lenth = max(max_lenth, length);
                // 不然就移动左指针右移
                } else {
                    if (seen_times.at(s.at(left)) == 1) {
                        seen_times.erase(s.at(left));
                        left++;
                        length--;
                    } else {
                        seen_times.at(s.at(left))--;
                        left++;
                        length--;
                    }
                }
            // 找不到的话
            } else {
                seen_times.emplace(s.at(right), 1);
                right++;
                length++;
                max_lenth = max(max_lenth, length);
            }
        }
        return max_lenth;
    }
};