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

    bool is_mirror(TreeNode *& left , TreeNode *& right){

        if(left && right && left -> val == right -> val){
            return is_mirror(left -> left , right -> right) && is_mirror(left -> right , right -> left);
        }
        
        if(!left && !right) return true;

        return false;
    }

    bool isSymmetric(TreeNode* root) {
        return is_mirror(root -> left , root -> right);
    }
};