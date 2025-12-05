#include <map>
#include <vector>

using namespace std;

class RangeFreqQuery {
public:
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            my_map[arr[i]].push_back(i);
        }
    }
    int query(int left, int right, int value) {
        int left_index = binarySearchLower(left, my_map[value]);
        int right_index = binarySearchUpper(right, my_map[value]);
        return right_index - left_index;
    }

private:
    // my_map的int是value值，vector是这个值出现的下标列表（天然排序的）
    map<int, vector<int>> my_map;
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