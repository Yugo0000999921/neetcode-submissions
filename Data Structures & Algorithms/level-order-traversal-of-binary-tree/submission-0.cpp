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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // BFS
        // 深くなるほどに,配列を増やして、そこにpush_backする。
        // 同じ幅での探索ごとにpush_backしていくはず。
        vector<vector<int>> res;
        //base case
        if(!root) return res;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            vector<int> level;
            int size = q.size();
            for(int i = q.size();i>0;i--){
                TreeNode* node = q.front();
                q.pop();
                if(node){
                    //値を入れる
                    level.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if(!level.empty()){
                res.push_back(level);
            }
        }
        return res;
    }
};
