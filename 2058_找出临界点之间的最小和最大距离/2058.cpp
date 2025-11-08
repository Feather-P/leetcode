/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <climits>
#include <vector>

using namespace std;
// 提交的时候记得删掉
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
    public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // 定义head为检测范围为3的组中的首个元素
        int prev;
        int target;
        int after;
        int index = 1;
        int last_extreme_point_index;
        int max_distance = INT_MIN;
        int min_distance = INT_MAX;
        int first_extreme_point_index;
        bool extreme_point_exists = false;
        ListNode* current = head;
        // 当current节点之后的第三个节点不为空
        while (current->next->next != nullptr) {
            prev = current->val;
            target = current->next->val;
            after = current->next->next->val;
            // 符合极值点的条件
            if ((prev < target && after < target) || (prev > target && after > target)) {
                if (!extreme_point_exists) {
                    first_extreme_point_index = index;
                }
                if (extreme_point_exists) {
                    max_distance = index - first_extreme_point_index;
                    min_distance = min(min_distance, index - last_extreme_point_index);
                }
                extreme_point_exists = true;
                last_extreme_point_index = index;
            }
            index++;
            current = current->next;
        }
        vector<int> ans = {min_distance == INT_MAX ? -1 : min_distance,
                           max_distance == INT_MIN ? -1 : max_distance};
        return ans;
    }
};