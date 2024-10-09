//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *right, *down;

    Node(int x) {
        data = x;
        right = NULL;
        down = NULL;
    }
};


// } Driver Code Ends
/*structure of the node of the linked list is as

struct Node
{
    int data;
    Node* right, *down;

    Node(int x){
        data = x;
        right = NULL;
        down = NULL;
    }
};
*/

// function must return the pointer to the first element of the in linked list i.e. that
// should be the element at arr[0][0]
class Solution {
public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        vector<vector<Node*>> v;
        for (int i = 0; i < mat.size(); i++) {
            vector<Node*> temp;
            for (int j = 0; j < mat[0].size(); j++) {
                Node* n = new Node(mat[i][j]); // Create a new Node with the value from the matrix
                temp.push_back(n); // Add the Node to the row
            }
            v.push_back(temp); // Add the row to the matrix of Node pointers
        }

        // Link the nodes right and down correctly
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[0].size(); j++) {
                if (i + 1 < v.size()) {
                    v[i][j]->down = v[i + 1][j]; // Link the node to the one below
                }
                if (j + 1 < v[0].size()) {
                    v[i][j]->right = v[i][j + 1]; // Link the node to the one on the right
                }
            }
        }

        // Return the top-left node as the head of the linked matrix
        return v[0][0];
    }
};
















//{ Driver Code Starts.

void display(Node* head) {
    Node* Rp;
    Node* Dp = head;
    while (Dp) {
        Rp = Dp;
        while (Rp) {
            cout << Rp->data << " ";
            if (Rp->right)
                cout << Rp->right->data << " ";
            else
                cout << "null ";
            if (Rp->down)
                cout << Rp->down->data << " ";
            else
                cout << "null ";
            Rp = Rp->right;
        }
        Dp = Dp->down;
    }
}

// Driver program
int main() {
    int t;
    cin >> t;
    cin.ignore(); // To handle new line after integer input

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;

        // Read the first row of the matrix
        while (ss >> num) {
            nums.push_back(num);
        }

        int n = nums.size();
        vector<vector<int>> mat(n, vector<int>(n));
        mat[0] = nums;

        // Read the remaining rows of the matrix
        for (int i = 1; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);
            vector<int> nums;
            int num;

            // Read the first row of the matrix
            while (ss >> num) {
                nums.push_back(num);
            }

            mat[i] = nums;
        }

        Solution ob;
        Node* head = ob.constructLinkedMatrix(mat);
        if (!head) {
            cout << "-1\n";
        } else {
            display(head);
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends