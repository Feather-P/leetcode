#include <vector>

using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int span = n / 4;     
        for (int i = 0; i <= n - span - 1; ++i) {
            if (arr[i] == arr[i + span]) {
                return arr[i];
            }
        }
        return -1; 
    }
};