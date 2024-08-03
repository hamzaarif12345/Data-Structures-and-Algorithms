//	https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

class Solution {
public:
    int celebrity(vector<vector<int>>& M) {
        int n = M.size();
        vector<int> inDegree(n, 0);
        vector<int> outDegree(n, 0);

        // Count in-degrees and out-degrees
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(M[i][j] == 1) {
                    outDegree[i]++;
                    inDegree[j]++;
                }
            }
        }

        // Check for celebrity
        for(int i = 0; i < n; i++) {
            if(inDegree[i] == n - 1 && outDegree[i] == 0) {
                return i;
            }
        }

        return -1;
    }
};



//optimized
class Solution {
public:
    int celebrity(vector<vector<int>>& M) {
        int n = M.size();
        int candidate = 0;
        
        // Find a potential celebrity
        for(int i = 1; i < n; i++) {
            if(M[candidate][i] == 1) {
                candidate = i;
            }
        }
        
        // Verify the candidate
        for(int i = 0; i < n; i++) {
            if(i != candidate) {
                if(M[candidate][i] == 1 || M[i][candidate] == 0) {
                    return -1;
                }
            }
        }
        
        return candidate;
    }
};