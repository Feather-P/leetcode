#include <algorithm>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    bool isVowel(char n){
        unordered_set<char> vowels = 
        {'a', 'e', 'i', 'o', 'u'};
        return vowels.count(n) > 0;
    }
    int maxVowels(string s, int k) {
        int max = 0;
        int curr = 0;
        // 处理第一个窗口
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                curr++;
            }
        }
        max = curr;
        // 处理后续窗口
        for (int i = k; i < s.size(); i++) {
            if (isVowel(s[i])) {
                curr++;
            }
            if (isVowel(s[i-k])) {
                curr--;
            }
            max = std::max(max, curr);
        }
        return max;
    }
};