// Question : https://leetcode.com/problems/count-complete-tree-nodes/description/

// Code

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
    int height(TreeNode * root){
        int i=0;
        while(root){
            root=root->left;
            i++;
        }
        return i;
    }
    int height2(TreeNode * root){
        int i=0;
        while(root){
            root=root->right;
            i++;
        }
        return i;
    }
    int complete(TreeNode * root){
        if(!root){
            return 0;
        }
        int l=height(root);
        int r=height2(root);
        if(l==r){
            int t=0;
            cout<<root->val<<" "<<l<<" "<<r<<" ";
            t=pow(2,l)-1;
            return t;
        }
        // else if(l==2 && r==1){
        //     return 2;
        // }
        
        return complete(root->left)+complete(root->right)+1;
    }
    
    int countNodes(TreeNode* root) {
        int t=0;
        return complete(root);
    }
};
