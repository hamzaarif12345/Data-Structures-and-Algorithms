class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans;
        vector<int> index;
        for(int i=0;i<boxes.size();i++){
            if(boxes[i]=='1') index.push_back(i);
        }
        for(int i=0;i<boxes.size();i++){
            int a=0;
            for(int j=0;j<index.size();j++){
                a+=abs(index[j]-i);
            }
            ans.push_back(a);
        }return ans;
    }
};