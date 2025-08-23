class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        if(arr.size()==0) return 0;
        int max=arr[0];
        int mi=0;
        for(int i=1;i<arr.size();i++){
            if(arr[i] > max) {max=arr[i];
            mi=i;}
        }
        if(mi == arr.size()-1) return 0;
        return mi+1;
    }
};
