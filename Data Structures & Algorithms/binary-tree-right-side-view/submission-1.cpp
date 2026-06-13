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
    vector<int> rightSideView(TreeNode* root) {
        // BFSで葉まで行く。
        // その層の一番右のときにvalを出力
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* rightSide = nullptr;
            int qlen = q.size();
            
            for(int i=0;i<qlen;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node){
                    rightSide = node;

                    // leftに先にいかないと，
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            //qの最後の部分で，出力するようになっている。
            if(rightSide){
                res.push_back(rightSide->val);
            }
        } 
        return res;
    }
};
