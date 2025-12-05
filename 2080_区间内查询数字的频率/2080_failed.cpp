#include <algorithm>
#include <vector>

using namespace std;

class RangeFreqQuery {
public:
    RangeFreqQuery(vector<int>& arr) {
        inner_array = arr;
    }
    int query(int left, int right, int value) {
        auto it_begin = inner_array.begin() + left;
        auto it_last = inner_array.begin() + right + 1;
        vector<int> tmp_array(it_begin, it_last); 
        sort(tmp_array.begin(), tmp_array.end());
        return
        binarySearchUpper(value, tmp_array) -
        binarySearchLower(value, tmp_array);
    }

private:
    vector<int> inner_array;
    int binarySearchUpper(int target_value, vector<int>& array){
        int array_size = static_cast<int>(array.size());
        int left = 0;
        int right = array_size - 1;
        while (left <= right) {
            int mid = left + ((right - left) / 2);
            if (array.at(mid) <= target_value) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
        int binarySearchLower(int target_value, vector<int>& array){
        int array_size = static_cast<int>(array.size());
        int left = 0;
        int right = array_size - 1;
        while (left <= right) {
            int mid = left + ((right - left) / 2);
            if (array.at(mid) < target_value) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */