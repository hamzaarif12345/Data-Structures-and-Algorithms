#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> sol(vector<int> &arr){
	sort(arr.begin(), arr.end());
	set<vector<int>> s;
	vector<vector<int>> output;
	for(int i=0;i<arr.size();i++){
		int j=i+1;
		int k=arr.size()-1;
		while(j<k){
			int sum=arr[i]+arr[j]+arr[k];
			if(sum==0){
				s.insert({arr[i], arr[j], arr[k]});
				j++;
				k--;
			}else if(sum<0){
				j++;
			}
			else{
				k--;
			}
		}
	}
	for(auto triplets : s)
            output.push_back(triplets);
    for(int i=0;i<output.size();i++){
    	for(int j=0;j<output[0].size();j++){
    		cout<<output[i][j]<<" ";
    	}
    	cout<<"\n";
    }


    return output;

}

int main(){
	vector<int> array={-1,0,1,2,-1,-4};
	sol(array);
	return 0;
}


/*
//Optimized Approach - O(n^2 logn + nlogn) - o(n^2 logn) time and O(n) space
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0;
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> output;
        for (int i = 0; i < nums.size(); i++){
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        for(auto triplets : s)
            output.push_back(triplets);
        return output;
    }
};
*/