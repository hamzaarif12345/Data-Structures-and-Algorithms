class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        for(int i=0; i< k;i++){
            string temp="";
            for(int i=0;i<s.size();i++){
                temp+= ((s[i]+1));

            }
            s+=temp;
            cout<<s<<" ";
            if(s.size() >=k) return s[k-1]; 
        }
        return -1;
    }
};