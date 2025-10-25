#include <cstdlib>
#include <string>

using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int total_length = s.size();
        int length = 0;
        int max_length = 0;
        int current_cost = 0;
        int left = 0;
        for (int right = 0; right < total_length; right++) {
            // 将右指针添加进窗口
            length++;
            current_cost += abs(s.at(right) - t.at(right));
            while (current_cost > maxCost) {
                length--;
                current_cost -= abs(s.at(left) - t.at(left));
                left++;
            }
            max_length = max(max_length, length);
        }
        return max_length;
    }
};