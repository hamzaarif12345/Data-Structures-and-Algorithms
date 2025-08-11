class Solution {
  public:
    int single(vector<int>& arr) {
        // code here
        if(arr.size()==1) return arr[0];
        int a=arr[0];
        for(int i=1;i<arr.size();i++){
            a^=arr[i];
        }return a;
    }
};