class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans=0;
        for(auto a: words){
            bool f=true;
            for(int i=0;i<pref.size();i++) {
                if(pref[i]!=a[i]) {f=false; break;}
            }
            if(f) ans++;
        }return ans;
    }
};