/*

Code
Testcase
Testcase
Test Result
623. Add One Row to Tree
Solved
Medium
Topics
Companies
Given the root of a binary tree and two integers val and depth, add a row of nodes with value val at the given depth depth.

Note that the root node is at depth 1.

The adding rule is:

Given the integer depth, for each not null tree node cur at the depth depth - 1, create two tree nodes with value val as cur's left subtree root and right subtree root.
cur's original left subtree should be the left subtree of the new left subtree root.
cur's original right subtree should be the right subtree of the new right subtree root.
If depth == 1 that means there is no depth depth - 1 at all, then create a tree node with value val as the new root of the whole original tree, and the original tree is the new root's left subtree.
 

Example 1:


Input: root = [4,2,6,3,1,5], val = 1, depth = 2
Output: [4,1,1,2,null,null,6,3,1,5]
*/
#include <queue>
using namespace std;

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int currDepth = 1;
        
        while (currDepth < depth - 1) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ++currDepth;
        }
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            TreeNode* leftNode = new TreeNode(val);
            leftNode->left = node->left;
            node->left = leftNode;
            
            TreeNode* rightNode = new TreeNode(val);
            rightNode->right = node->right;
            node->right = rightNode;
        }
        
        return root;
    }
};
