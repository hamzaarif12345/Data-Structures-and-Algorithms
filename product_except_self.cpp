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


class Solution {
public:
    int count(vector<int> &array){
        int c=0;
        for(int i=0;i<array.size();i++){
            if(array[i]==0) c++;
        }   return c;}
        
    vector<int> productExceptSelf(vector<int>& array) {
        vector<int> ans;
        int count=0;
        int prod=1;
        if(array.size()==0) return ans;
        for(int i=0;i<array.size();i++){
            if(array[i]==0)
                count++;
            else prod*=array[i];
        }
        if(count ==0){
            for(int i=0;i<array.size();i++){
                int k=prod/array[i];
                ans.push_back(k);
            }
        }
        if(count ==1){
            for(int i=0;i<array.size();i++){
                if(array[i]==0)
                    ans.push_back(prod);
                else ans.push_back(0);
            }
        }
        if(count>=2){
            for(int i=0;i<array.size();i++){
                ans.push_back(0);
            }
        }
        return ans;
        
    }
};
