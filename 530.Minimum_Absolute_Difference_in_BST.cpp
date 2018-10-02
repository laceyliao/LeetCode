/*
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.
Example: 
Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).

Note: There are at least two nodes in this BST. 
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int mindiff = 9999999,pre=-1;
        Inorder(root,mindiff,pre);
        return mindiff;
    }
private:
    void Inorder(TreeNode* root, int &mindiff, int& pre) 
    {
        if(root->left!=NULL) Inorder(root->left,mindiff,pre);
        if(pre!=-1) mindiff = min(mindiff,root->val-pre);
        pre = root->val;
        if(root->right!=NULL) Inorder(root->right,mindiff,pre);
        
    }
};

