//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    stack<int> s;
    priority_queue<int, vector<int>, greater<int>> pq;

    Solution() { }

    // Add an element to the top of Stack
    void push(int x) {
        s.push(x);
        pq.push(x);
    }

    // Remove the top element from the Stack
    void pop() {
        if (!s.empty()) {
            int topElement = s.top();
            s.pop();
            
            // Remove the topElement from priority queue
            priority_queue<int, vector<int>, greater<int>> tempPQ;
            while (!pq.empty()) {
                if (pq.top() == topElement) {
                    pq.pop();
                    break; // Remove only the first occurrence
                }
                tempPQ.push(pq.top());
                pq.pop();
            }
            // Restore elements back to pq
            while (!tempPQ.empty()) {
                pq.push(tempPQ.top());
                tempPQ.pop();
            }
        }
    }

    // Returns top element of the Stack
    int peek() {
        return s.empty() ? -1 : s.top();
    }

    // Finds minimum element of Stack
    int getMin() {
        return pq.empty() ? -1 : pq.top();
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends