/*
2192. All Ancestors of a Node in a Directed Acyclic Graph
Solved
Medium
Topics
Companies
Hint
You are given a positive integer n representing the number of nodes of a Directed Acyclic Graph (DAG). The nodes are numbered from 0 to n - 1 (inclusive).

You are also given a 2D integer array edges, where edges[i] = [fromi, toi] denotes that there is a unidirectional edge from fromi to toi in the graph.

Return a list answer, where answer[i] is the list of ancestors of the ith node, sorted in ascending order.

A node u is an ancestor of another node v if u can reach v via a set of edges.

 

Example 1:


Input: n = 8, edgeList = [[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]
Output: [[],[],[],[0,1],[0,2],[0,1,3],[0,1,2,3,4],[0,1,2,3]]
Explanation:
The above diagram represents the input graph.
- Nodes 0, 1, and 2 do not have any ancestors.
- Node 3 has two ancestors 0 and 1.
- Node 4 has two ancestors 0 and 2.
- Node 5 has three ancestors 0, 1, and 3.
- Node 6 has five ancestors 0, 1, 2, 3, and 4.
- Node 7 has four ancestors 0, 1, 2, and 3.
Example 2:
*/

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n); // Initialize the result vector with 'n' empty vectors
        unordered_map<int, set<int>> m; // Use set to store ancestors

        // Create the adjacency list
        for(int i = 0; i < edges.size(); i++) {
            m[edges[i][1]].insert(edges[i][0]);
        }

        // Use BFS to propagate ancestors
        for(int i = 0; i < n; i++) {
            queue<int> q;
            vector<bool> visited(n, false);
            q.push(i);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int ancestor : m[node]) {
                    if (!visited[ancestor]) {
                        ans[i].push_back(ancestor);
                        q.push(ancestor);
                        visited[ancestor] = true;
                    }
                }
            }
            sort(ans[i].begin(), ans[i].end()); // Sort the vector
        }
        return ans;
    }
};
