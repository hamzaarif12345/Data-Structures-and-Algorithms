/*
1609. Even Odd Tree
Solved
Medium
Topics
Companies
Hint
A binary tree is named Even-Odd if it meets the following conditions:

The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, etc.
For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).
Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.

 

Example 1:


Input: root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
Output: true
Explanation: The node values on each level are:
Level 0: [1]
Level 1: [10,4]
Level 2: [3,7,9]
Level 3: [12,8,6,2]
Since levels 0 and 2 are all odd and increasing and levels 1 and 3 are all even and decreasing, the tree is Even-Odd.
*/

#include <queue>
#include <vector>
#include <climits>

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        int level = 0;
        std::queue<TreeNode*> q;

        if (root->val % 2 == 0) {
            return false;
        }

        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            std::vector<TreeNode*> levelNodes;

            for (int i = 0; i < size; ++i) {
                TreeNode* temp = q.front();
                q.pop();

                if (temp->left) {
                    q.push(temp->left);
                }

                if (temp->right) {
                    q.push(temp->right);
                }

                levelNodes.push_back(temp);
            }

            if (level % 2 == 0) {
                int prev = INT_MIN;
                for (TreeNode* node : levelNodes) {
                    if (node->val % 2 == 0 || prev >= node->val) {
                        return false;
                    }
                    prev = node->val;
                }
            } else {
                int prev = INT_MAX;
                for (TreeNode* node : levelNodes) {
                    if (node->val % 2 != 0 || prev <= node->val) {
                        return false;
                    }
                    prev = node->val;
                }
            }

            ++level;
        }

        return true;
    }
};
