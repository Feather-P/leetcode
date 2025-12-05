#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        sort(words.begin(), words.end(), [this](string& a, string& b) -> bool {
            return theUnamedFunction(a) < theUnamedFunction(b);
        });
        // 二分查找
        vector<int> ans(queries.size(), 0);
        for (int i = 0; i < queries.size(); i++) {
            int left = 0;
            int right = static_cast<int>(words.size()) - 1;
            while (left <= right) {
                int mid = left + ((right - left) / 2);
                if (theUnamedFunction(words.at(mid)) <= theUnamedFunction(queries.at(i))) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            ans.at(i) = static_cast<int>(words.size()) - left;
        }
        return ans;
    }

    private:
    static int theUnamedFunction(const string& word) {
        char smallest_char = word.at(0);
        for (int i = 1; i < word.size(); i++) {
            smallest_char = min(smallest_char, word.at(i));
        }
        int smallest_char_count = 0;
        for (auto c : word) {
            if (c == smallest_char) {
                smallest_char_count++;
            }
        }
        return smallest_char_count;
    }
};