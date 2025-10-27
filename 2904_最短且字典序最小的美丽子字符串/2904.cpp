#include <string>

using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int num_one_count = 0;
        int left = 0;
        string ans;
        
        for (int right = 0; right < s.size(); right++) {
            if (s[right] == '1') {
                num_one_count++;
            }
            
            while (num_one_count >= k && left <= right) {
                string current = s.substr(left, right - left + 1);
                
                // 如果当前子字符串更短，或者长度相同但字典序更小，则更新答案
                if (ans.empty() || current.size() < ans.size() || 
                    (current.size() == ans.size() && current < ans)) {
                    ans = current;
                }
                
                if (s[left] == '1') {
                    num_one_count--;
                }
                left++;
            }
        }
        
        return ans;
    }
};
