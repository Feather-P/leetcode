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
        vector<vector<int>> ans_array;

        for (int i = 0; i < queries.size(); i++) {
            TreeNode* current_node = root;
            int best_lower_val = -1;
            int best_higher_val = -1;
            while (current_node != nullptr) {
                int target = queries.at(i);
                if (current_node->val == target) {
                    best_higher_val = target;
                    best_lower_val = target;
                    break;
                }
                if (current_node->val < target) {
                    best_lower_val = current_node->val;
                    current_node = current_node->right;
                } else {
                    best_higher_val = current_node->val;
                    current_node = current_node->left;
                }
            }
            ans_array.push_back({best_lower_val, best_higher_val});
        }
        return ans_array;
    }
};