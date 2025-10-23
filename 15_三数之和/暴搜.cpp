#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> set;
    for (int i = 0; i < nums.size() - 2; i++) {
        for (int j = i + 1; j < nums.size() - 1; j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                
                if (i != k && j != k &&
                    i != k && nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> line;
                    line.push_back(nums.at(i));
                    line.push_back(nums.at(j));
                    line.push_back(nums.at(k));
                    sort(line.begin(), line.end());
                    set.insert(line);
                }
            }
        }
    }
    return vector<vector<int>>(set.begin(), set.end());
}

int main() {
    vector<int> input;
    int tmp;
    while (cin >> tmp) {
        input.push_back(tmp);
    }

    for (auto element : input) {
        cout << element<< '\n';
    }
    for (auto line : threeSum(input)) {
        for (auto element : line) {
            cout << element;
        }
        cout << '\n';
    }
}