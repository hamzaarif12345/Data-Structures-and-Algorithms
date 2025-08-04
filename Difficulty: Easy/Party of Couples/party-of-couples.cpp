// User function Template for C++

class Solution {
  public:
    int findSingle(vector<int> &arr) {
        // code here
        int a=arr[0];
        for(int i=1;i<arr.size();i++){
            a^=arr[i];
        }return a;
    }
};