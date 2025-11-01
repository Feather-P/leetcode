#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        for (int i = 0; i < spells.size(); i++) {
            int left = 0;
            int right = (int)potions.size() - 1;
            while (left <= right) {
                int mid = left + ((right - left) / 2);
                if ((long long)potions.at(mid) * spells.at(i) < success) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            ans.push_back((int)potions.size() - left);
        }
        return ans;
    }
};