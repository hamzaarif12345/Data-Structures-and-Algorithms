//https://www.geeksforgeeks.org/problems/merge-two-bst-s/1


class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> bfs(Node *root){
        vector<int> v;
        queue<Node *>q;
        q.push(root);
        while(!q.empty()){
            Node *f=q.front();
            v.push_back(f->data);
            q.pop();
            if(f->left) q.push(f->left);
            if(f->right) q.push(f->right);
        }
        // for(auto a:v){
            
        // }
        return v;
    }
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int> a=bfs(root1);
        vector<int> a1=bfs(root2);
        for(auto c: a1) a.push_back(c);
        sort(a.begin(),a.end());
        return a;
    }

};