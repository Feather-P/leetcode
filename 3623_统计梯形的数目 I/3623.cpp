#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    public:
    static int countTrapezoids(vector<vector<int>>& points) {
        // first为y坐标，second为在y坐标上的点的数量
        unordered_map<int, int> points_y_map;
        // first为y坐标，second为在y坐标上的线的数量
        unordered_map<int, long long int> lines_y_map;
        for (auto point : points) {
            // 将当前遍历的点加到点计数哈希表里
            points_y_map[point[1]]++;
        }
        for (auto point : points_y_map) {
            // 计算每个y上的线的数量
            lines_y_map[point.first] = (long long)(point.second - 1) * point.second / 2;
        }
        long long int ans = 0;
        long long int sides = 0;
        for (auto line : lines_y_map) {
            // 逐步计算矩形的数量
            ans += sides * line.second;
            sides += line.second;
        }

        return int(ans % 1000000007);
    }
};