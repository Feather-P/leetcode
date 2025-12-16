#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    public:
    static auto maximumBeauty(vector<vector<int>>& items, vector<int>& queries) -> vector<int> {
        unordered_map<int, int> optimized_map;
        // 去重
        for (vector<int> item : items) {
            optimized_map[item[0]] = max(item[1], optimized_map[item[0]]);
        }
        vector<Object> optimized_vector;
        optimized_vector.reserve(optimized_map.size());
        for (auto pair : optimized_map) {
            optimized_vector.push_back(Object{
                pair.first,
                pair.second});
        }
        // 按价格排序
        sort(optimized_vector.begin(), optimized_vector.end(), [](Object a, Object b) {
            return a.value < b.value;
        });
        // 前缀最大
        vector<int> max_beauty(optimized_vector.size(),0);
        max_beauty[0] = optimized_vector[0].beauty;
        for (int i = 1; i < optimized_vector.size(); i++) {
            max_beauty.at(i) = max(optimized_vector.at(i).beauty, max_beauty.at(i-1));
        }
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int query_price = queries[i];
            auto it = upper_bound(
                optimized_vector.begin(), 
                optimized_vector.end(), 
                query_price, 
                [](int val, const Object& item) {
                    return val < item.value;
                }
            );

            if (it == optimized_vector.begin()) {
                ans[i] = 0;
            } else {
                int target_index = static_cast<int>(distance(optimized_vector.begin(), it) - 1);
                ans[i] = max_beauty[target_index]; // 使用修正后的数组名
            }
        }

        return ans;
    }

    private:
    struct Object {
        int value;
        int beauty;
    };
};