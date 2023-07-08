/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

Q 238
*/


#include<bits/stdc++.h>
using namespace std;
void sol(vector<int> &array){
	vector<int> ans;
	for (int i=0;i<array.size();i++){
		int prod=1;
		for(int j=0;j<array.size();j++){
			if(j==i)
				continue;
			else
				prod*=array[j];
		}
		ans.push_back(prod);
	}
	//cout<<ans.size();
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";

}
int count(vector<int> &array){
	int count=1;
	for(int i=0;i<array.size();i++){
		if(array[i]==0)
			count++;
	}
	return count;

}
void sol2(vector<int> &array){
	vector<int> ans;
	if(array.size()==0) return ;
	if(count(array)>=2){
		for (int i = 0; i < array.size(); ++i)
		{
			ans.push_back(0);
		}
	} return;
	int prod =1;
	for(int i=0;i<array.size();i++){  //O(n)
		prod*=prod;
	}
	for (int i = 0; i < array.size(); ++i)
	{	
		if(count(array)==1){
			if(array[i]==0){
				ans.push_back(prod);
				return;
			}
			else{
				ans.push_back(0);
				return;
			}
		}
		int k=prod/array[i];
		ans.push_back(k);
	}
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";

}
int main(){
	vector<int> arr={1,3,4,5,0};
	sol(arr);
	return 0;
}