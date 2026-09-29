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

    int sum = 0;

    void add_leaf(TreeNode *& root){
        if(!root) return;

        add_leaf(root -> left);

        // leaf node
        if(!root -> left && !root -> right) return;

        if(root -> left && !root -> left -> left && !root -> left -> right) sum += root -> left -> val;

        add_leaf(root -> right);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        add_leaf(root);
        return sum;
    }
};