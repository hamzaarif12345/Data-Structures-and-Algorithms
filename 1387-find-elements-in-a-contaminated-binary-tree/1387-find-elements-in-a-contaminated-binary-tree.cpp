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
class FindElements {
public:
    unordered_map<int,bool> m;  
    FindElements(TreeNode* root) {
        m[0]=true;
        //int val=0
        queue<TreeNode* > q;
        q.push(root);
        root->val=0;
        while(!q.empty()){
            TreeNode* temp= q.front();
            q.pop();
            if(temp->left) {
                int a= 2*(temp->val)+1;
                temp->left->val=a;
                q.push(temp->left);
                m[a]=true;
            }
            if(temp->right) {
                int a= 2*(temp->val)+2;
                temp->right->val=a;
                q.push(temp->right);
                m[a]=true;
            }
        }
    }
    bool find(int target) {
        return m[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */