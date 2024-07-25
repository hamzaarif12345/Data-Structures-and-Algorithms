/*
https://www.geeksforgeeks.org/problems/array-to-bst4443/1
*/
class Solution {
public:
    Node* to_bst(vector<int> arr) {
        if (arr.empty()) {
            return nullptr;
        }
        
        int mid = arr.size() / 2;
        Node* root = new Node(arr[mid]);
        
        if (arr.size() == 1) {
            return root;
        }
        
        vector<int> left_arr(arr.begin(), arr.begin() + mid);
        vector<int> right_arr(arr.begin() + mid + 1, arr.end());
        
        root->left = to_bst(left_arr);
        root->right = to_bst(right_arr);
        
        return root;
    }
    
    Node* sortedArrayToBST(vector<int>& nums) {
        return to_bst(nums);
    }
};
