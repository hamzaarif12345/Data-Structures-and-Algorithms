class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return {}; // Handle empty tree case.

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            int m = INT_MIN; // Initialize the max value for the current level.

            for (int i = 0; i < n; i++) {
                TreeNode* t = q.front();
                q.pop();

                m = max(m, t->val); // Update the max value for the level.

                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            ans.push_back(m); // Store the max value of the current level.
        }

        return ans;
    }
};
