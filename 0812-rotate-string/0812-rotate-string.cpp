class Solution {
public:

    bool rotateString(string s, string goal) {
        int n=s.size();
        for(int i=0;i<=s.size();i++){
            string k=s.substr(1,n) + s[0];
            s=k;
            if(k==goal) return true; 
        }return false;
    }
};