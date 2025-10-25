#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int length = 0;
        int max_length = 0;
        unordered_map<int, int> map;
        for (int right = 0; right < fruits.size(); right++) {
            // 把右指针的存入窗口
            if (map.find(fruits.at(right)) == map.end()) {
                map.emplace(fruits.at(right), 1);
            } else {
                map.at(fruits.at(right))++;
            }
            length++;
            while (map.size() > 2) {
                if (map.at(fruits.at(left)) == 1) {
                    map.erase(fruits.at(left));
                } else {
                    map.at(fruits.at(left))--;
                }
                length--;
                left++;
            }
            max_length = max(max_length, length);
        }
        return max_length;
    }
};