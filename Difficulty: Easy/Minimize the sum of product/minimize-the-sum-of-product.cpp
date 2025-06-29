class Solution {
  public:
    typedef long long int ll;

    long long int minValue(vector<int> &arr1, vector<int> &arr2) {
    sort(arr1.begin(), arr1.end());              // ascending
    sort(arr2.begin(), arr2.end(), greater<int>()); // descending
    
    long long int sum = 0;
    for (int i = 0; i < arr1.size(); i++) {
        sum += arr1[i] * arr2[i]; // use 1LL to prevent overflow
    }
    return sum;
}

};