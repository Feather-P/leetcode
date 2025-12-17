/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <cstddef>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
    public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        TreeNode* current_node = root;
        stack<TreeNode*> stack;
        vector<int> array;
        while (current_node != nullptr || !stack.empty()) {
            while (current_node != nullptr) {
                stack.push(current_node);
                current_node = current_node->left;
            }
            current_node = stack.top();
            stack.pop();
            array.push_back(current_node->val);

            current_node = current_node->right;
        }
        vector<vector<int>> ans;

        for (int target : queries) {
            auto it = lower_bound(array.begin(), array.end(), target);
            int mn = -1, mx = -1;
            if (it != array.end()) {
                mx = *it;
                if (*it == target) {
                    mn = target;
                } else if (it != array.begin()) {
                    mn = *prev(it);
                }
            } else {
                mn = array.back();
            }
            ans.push_back({mn, mx});
        }
        return ans;
    }
};