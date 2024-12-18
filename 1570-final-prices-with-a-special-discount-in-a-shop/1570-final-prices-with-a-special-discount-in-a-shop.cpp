class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<=n-1;j++){
                if(ans[i]==-1 && (prices[i] >= prices[j]) ) ans[i]=(prices[i]-prices[j]);
                
            }
            if(ans[i]==-1) ans[i]=prices[i];
        }return ans;
    }
};