#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    public:
    int numberOfSubstrings(string s, int k) {
        unordered_map<char, int> map;
        int left = 0;
        int right = 0;
        int ans = 0;
        while (right < s.size()) {
            map[s[right]]++;
            while (map[s[right]] >= k) {
                map[s[left]]--;
                left++;
            }
            ans += left;
            right++;
        }
        return ans;
    }
};