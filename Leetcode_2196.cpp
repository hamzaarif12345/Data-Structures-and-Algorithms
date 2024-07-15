/*
2196. Create Binary Tree From Descriptions
Solved
Medium
Topics
Companies
Hint
You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

If isLefti == 1, then childi is the left child of parenti.
If isLefti == 0, then childi is the right child of parenti.
Construct the binary tree described by descriptions and return its root.

The test cases will be generated such that the binary tree is valid.

 

Example 1:


Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
Output: [50,20,80,15,17,19]
Explanation: The root node is the node with value 50 since it has no parent.
The resulting binary tree is shown in the diagram.
Example 2:


Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
Output: [1,2,null,null,3,4]
Explanation: The root node is the node with value 1 since it has no parent.
The resulting binary tree is shown in the diagram.
 
*/
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, pair<TreeNode*, bool>> m; // map value to pair of TreeNode* and bool indicating if it's a root candidate

        for (auto a : descriptions) {
            int parentVal = a[0];
            int childVal = a[1];
            int isLeft = a[2];

            // Ensure the parent node exists in the map
            if (m.find(parentVal) == m.end()) {
                m[parentVal].first = new TreeNode(parentVal);
                m[parentVal].second = true; // initially, every node is a root candidate
            }

            // Ensure the child node exists in the map
            if (m.find(childVal) == m.end()) {
                m[childVal].first = new TreeNode(childVal);
                m[childVal].second = false; // children are not root candidates
            } else {
                m[childVal].second = false; // mark as not a root candidate
            }

            // Assign the child to the correct position (left or right) of the parent
            if (isLeft) {
                m[parentVal].first->left = m[childVal].first;
            } else {
                m[parentVal].first->right = m[childVal].first;
            }
        }

        // Find the root node (the node which is still a root candidate)
        TreeNode* root = nullptr;
        for (auto& entry : m) {
            if (entry.second.second == true) {
                root = entry.second.first;
                break;
            }
        }

        return root;
    }
};  