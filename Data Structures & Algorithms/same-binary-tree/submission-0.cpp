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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;   // ① 両方null
        if (!p || !q) return false;  // ② 片方null
        if (p->val != q->val) return false; // ③ 値が違う
    
        return isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right); // ④ 再帰
        }
    };
