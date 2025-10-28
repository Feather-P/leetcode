#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> map;
        int left = 0, right = 0;
        int ans = 0;
        map.emplace('a', 0);
        map.emplace('b', 0);
        map.emplace('c', 0);
        while (right < s.size()) {
            if (map.find(s.at(right)) != map.end()) {
                map.at(s.at(right))++;
            }
            while ((map.at('a') >= 1 && map.at('b') >= 1  && map.at('c') >= 1 )) {
                ans += s.size() - right;
                map.at(s.at(left))--;
                left++;
            }
            right++;
        }
        return ans;
    }
};