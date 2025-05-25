class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
    unordered_map<int, bool> m;
    
    for (int a : arr) {
        m[a * a] = true;
    }
    
    int n = arr.size();
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int sum = arr[i]*arr[i] + arr[j]*arr[j];
            if(m[sum]) return true;
        }
    }
    
    return false;
}

};