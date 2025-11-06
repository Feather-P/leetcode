#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
    public:
    static int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int count = 0;
        for (auto element : arr1) {
            int left = 0;
            int right = (int)arr2.size() - 1;
            while (left <= right) {
                int mid = left + ((right - left) / 2);
                // 如果mid已经符合条件，直接跳出循环
                if (abs(element - arr2[mid]) <= d) {
                    count++;
                    break;
                }
                if (arr2[mid] < element) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return (int)arr1.size() - count;
    }
};