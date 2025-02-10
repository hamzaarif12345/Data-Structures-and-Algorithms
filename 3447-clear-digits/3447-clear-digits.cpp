class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(auto a: s){
            if(a=='1' || a=='2' || a=='3' || a=='4' || a=='5' || a=='6' || a=='7' || a=='8' || a=='9' || a=='0')
            {
                if(!st.empty()) st.pop();
            }
            else {
                st.push(a);
            }
        }
        if(st.empty()) return "";
        string ans="";
        while(!st.empty()){
            char c=st.top();
            st.pop();
            ans+=c;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};