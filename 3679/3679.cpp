#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        unordered_map<int, int> map;
        vector<short int> is_accpeted(arrivals.size(),0);
        int dispose_count = 0;

        for (int i = 0; i < w; i++) {// 处理前w个窗口
            if (map.find(arrivals.at(i)) != map.end()) { //如果map不为空
                if (map.at(arrivals.at(i)) < m) { // 如果有空间装下下一个数
                    is_accpeted.at(i) = 1;
                    map.at(arrivals.at(i))++;
                } else {
                    dispose_count++;
                }
            } else {
                is_accpeted.at(i) = 1;
                map.emplace(arrivals.at(i), 1);
            }
        }

        for (int i = w; i < arrivals.size(); i++) { // 处理后续窗口
            // 优先维护逻辑
            if (is_accpeted.at(i - w) == 1) {
                if (map.at(arrivals.at(i - w)) == 1) {
                    map.erase(arrivals.at(i - w));
                } else {
                    map.at(arrivals.at(i - w))--;
                }
            }
            // 添加逻辑
            if (map.find(arrivals.at(i)) != map.end()) { //如果map不为空
                if (map.at(arrivals.at(i)) < m) { // 如果有空间装下下一个数
                    is_accpeted.at(i) = 1;
                    map.at(arrivals.at(i))++;
                } else {
                    dispose_count++;
                }
            } else {
                is_accpeted.at(i) = 1;
                map.emplace(arrivals.at(i), 1);
            }
        }
        return dispose_count;
    }
};