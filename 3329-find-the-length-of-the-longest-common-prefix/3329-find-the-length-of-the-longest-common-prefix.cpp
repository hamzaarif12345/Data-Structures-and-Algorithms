class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string,int> m;
        for(auto a: arr1){
            string s=to_string(a);
            string temp="";
            for(auto ch:s){
                temp+=ch;
                m[temp]++;
            }
        }
        int ans=0;
        for(auto a: arr2){
            string s=to_string(a);
            string temp="";
            for(auto ch:s){
                temp+=ch;
                if(m.find(temp)!=m.end()) {
                    int a=temp.size();
                    ans=max(ans,a);
                }
            }
        }return ans;

    }
};