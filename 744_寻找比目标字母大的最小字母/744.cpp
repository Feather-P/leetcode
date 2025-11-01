#include <vector>

using namespace std;

class Solution {
    public:
    char static nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = (int)letters.size() - 1;
        char ans = letters.at(0);
        while (left <= right) {
            int mid = left + ((right - left) / 2);
            if (letters.at(mid) <= target) {
                left = mid + 1;
            } else if (letters.at(mid) > target) {
                ans = letters.at(mid);
                right = mid - 1;
            }
        }
        return ans;
    }
};