/*

Given an array of integers citations where citations[i] is the number of citations a researcher 
received for their ith paper, return the researcher's h-index.

According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of 
h such that the given researcher has published at least h papers that have each been cited at least h times.

 

Example 1:

Input: citations = [3,0,6,1,5]
Output: 3
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.*/

#include <bits/stdc++.h>
using namespace std;
void sol(vector<int> &array){
	sort(array.begin(),array.end()); // 0 1 3 5 6
	int ans=0;
	for(int i=0;i<array.size();i++){
		if(array[i]<=array.size()-i)
			ans=array[i];
		
	}
	cout<<ans;
}
int main(){
	vector<int> array={1,3,1};
	sol(array);
	return 0;
}
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int ans = 0;
        sort(citations.begin(), citations.end(), greater<int>());
        for (int i = 1; i <= citations.size(); i++) {
            if (citations[i-1] < i) break;
            ans = i;
        }
        return ans;
    }
};