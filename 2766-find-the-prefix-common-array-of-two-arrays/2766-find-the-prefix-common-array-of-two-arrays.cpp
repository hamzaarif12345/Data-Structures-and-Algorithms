class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,pair<bool,bool>> m;
        int c=0;
        int n=A.size();
        vector<int> ans;
        for(int i=0;i< A.size(); i++){
            m[A[i]].first=true;
            m[B[i]].second=true;
            if (m[A[i]] == make_pair(true, true)) c++;
            if (m[B[i]] == make_pair(true, true)) c++;
            if(A[i] == B[i]) c--;

            ans.push_back(c);
        }return ans;
    }
};