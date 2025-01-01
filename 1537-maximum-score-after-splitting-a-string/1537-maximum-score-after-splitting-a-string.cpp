class Solution {
public:
    int maxScore(string s) {
        int ans=0;
        int c=0,d=0;
        if(s[0]=='0') c=1;
        else {c=0;d--;}
        for(auto a: s){
            if(a=='1') d++;
        }
        ans=c+d;
        cout<<" "<< ans<< "  ";
        for(int i=1;i<s.size()-1;i++){
            if(s[i]=='0') c++;
            else d--;
            ans=max(ans,c+d);
        }return ans;
    }
};