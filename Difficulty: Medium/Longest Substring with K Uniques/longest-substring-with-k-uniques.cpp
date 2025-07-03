class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        unordered_map<char,int> m;
        int ans=-1;
        int j=0;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
            if(m.size()==k) ans=max(ans,i-j+1);
            else if(m.size() > k) {
                m[s[j]]--;
                if(m[s[j]]==0) m.erase(s[j]);
                j++;
            }
        }return ans;
    }
};