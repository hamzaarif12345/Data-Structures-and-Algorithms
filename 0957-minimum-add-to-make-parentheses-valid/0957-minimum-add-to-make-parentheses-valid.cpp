class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0;
        int c=0;
        for(auto a : s){
            if(a=='(') c++;
            else {
                if(c>0) c--;
                else ans++;
            }
        }return ans+c;
    }
};