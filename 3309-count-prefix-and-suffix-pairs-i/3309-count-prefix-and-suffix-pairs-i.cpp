class Solution {
public:
    bool isPrefixAndSuffix(const string &a, const string &b) {
        if (a.size() > b.size()) return false;
        
        // Check if 'a' is a prefix of 'b'
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) return false;
        }
        
        // Check if 'a' is a suffix of 'b'
        int aSize = a.size();
        int bSize = b.size();
        for (int i = 0; i < aSize; i++) {
            if (a[aSize - i - 1] != b[bSize - i - 1]) return false;
        }
        
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(isPrefixAndSuffix(words[i],words[j])) ans++;
            }
        }return ans;
    }
};