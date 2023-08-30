// quick sort implementation in cpp
//https://medium.com/algo-101/quick-sort-explained-c-stl-c8d105cbaade
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int partition(vector<int>& nums,int low, int high)
    {
        int i=low-1;
        int pivot=nums[high];
        for(int j=low;j<high;j++)
        {
            if(nums[j]<=pivot)
            {
                i++;
                swap(nums[i],nums[j]);
            }
        }
        swap(nums[i+1],nums[high]);
        return i+1;
    }
    
    void quicksort(vector<int>& nums,int low, int high)
    {
        if(low<high)
        {
            int pivot=partition(nums,low,high);
            quicksort(nums,low,pivot-1);
            quicksort(nums,pivot+1,high);
            
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
         quicksort(nums,0,nums.size()-1);
         return nums;
    }
};


int main(){
	vector<int> a={4,7,8,9,10,5};
	Solution s;
	vector<int> b=s.sortArray(a);
	for(int i=0;i<b.size();i++) cout<<b[i]<<" ";
	return 0;
}