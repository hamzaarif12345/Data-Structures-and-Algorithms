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
    int maxLevelSum(TreeNode* root) {
        if(root==nullptr) return{};
        int in = -1;
        int ans = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        int i=0;
        //ans.push_back(root->val);
        while(!q.empty()){
            int n=q.size();
            int a=0;
            while(n--){
                TreeNode* temp=q.front();
                a+=temp->val;
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                
            }
            i++;
            if(a==ans) continue;
            ans=max(ans,a);
            if(ans==a)  in=i;
            
        }
        return in;
    }
};