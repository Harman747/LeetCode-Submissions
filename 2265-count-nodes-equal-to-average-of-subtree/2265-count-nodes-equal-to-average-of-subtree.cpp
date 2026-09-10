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
class Solution {
public:

    int ans = 0;

    pair<int , int> get_avg(TreeNode * root){
        if(!root){
            return {0 , 0};
        }

        pair<int , int> left_tree_pair = get_avg(root -> left);
        pair<int , int> right_tree_pair = get_avg(root -> right);

        int sum = left_tree_pair.first + right_tree_pair.first + root -> val;
        int nodes = left_tree_pair.second + right_tree_pair.second + 1;

        pair<int , int> current_p = make_pair(sum , nodes);

        if(sum / nodes == root -> val) ans++;

        return current_p;

    }

    int averageOfSubtree(TreeNode* root) {
        get_avg(root);
        return ans;
    }
};