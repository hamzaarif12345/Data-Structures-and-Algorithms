class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> a;
        for(auto c: s){
            if(c!='#'){
                a.push(c);
            }
            else{
                if(!a.empty())a.pop();
            }
        }
        stack<char> a1;
        for(auto c: t){
            if(c!='#'){
                a1.push(c);
            }
            else{
                if(!a1.empty())a1.pop();
            }
        }
        return (a==a1);
    }
};
