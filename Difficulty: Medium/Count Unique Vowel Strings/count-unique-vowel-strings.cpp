class Solution {
  public:
    int vowelCount(string& s) {
        // code here
        unordered_map<char,int> m;
        for(auto a: s){
            if(a=='a' || a=='i'|| a=='o'|| a=='e'|| a=='u') m[a]++;
        }
        if(m.size()==0) return 0;
        int ans=1;
        for(int i=1;i<=m.size();i++){
            ans*=i;
        }
        for(auto a: m) ans*=a.second;
        return ans;
    }
};