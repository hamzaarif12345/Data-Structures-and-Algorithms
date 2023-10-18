#include<bits/stdc++.h>
using namespace std;

/*

Example 1:

Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.
Example 2:

Input: nums = [3,1,3,4,3], k = 6   // [1 3 3 3 4]
Output: 1
Explanation: Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
There are no more pairs that sum up to 6, hence a total of 1 operation.
*/
int maxOperations(vector<int>& num, int k){
    sort(num.begin(),num.end());
    int c=0;
    int i=0,j=num.size()-1;
    while(i<j){
        if(num[i]+ num[j]==k) {c++;i++;j--;}
        else if(num[i]+num[j]<k) i++;
        else j--;
    }
    cout<<c;
}
int findPairs(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int count = 0;
    int i = 0, j = 1;  // Start with two pointers at different positions.

    while (i < nums.size() && j < nums.size()) {
        if (i != j && nums[j] - nums[i] == k) {
            count++;
            i++;  // Move i to avoid duplicates.
            j++;  // Move j to find more pairs.
            // Skip all elements equal to nums[i] and nums[j].
            while (i < nums.size() && nums[i] == nums[i - 1]) i++;
            while (j < nums.size() && nums[j] == nums[j - 1]) j++;
        } else if (nums[j] - nums[i] > k) {
            i++;  // Try to decrease the difference.
            if (i == j) j++;  // Ensure i and j are different.
        } else {
            j++;  // Try to increase the difference.
        }
    }
    cout<<count;
    return count;
}
string minRemoveToMakeValid(string s) {
  stack<int> st;
  for (auto i = 0; i < s.size(); ++i) {
    if (s[i] == '(') st.push(i);
    if (s[i] == ')') {
      if (!st.empty()) st.pop();
      else s[i] = '*';
    }
  }
  while (!st.empty()) {
    s[st.top()] = '*';
    st.pop();
  }
  s.erase(remove(s.begin(), s.end(), '*'), s.end());
  cout<<s;
  return s;
}

int mioperations(vector<int> nums,int x){
    int l=0;
    int r=nums.size()-1;
    if(nums[l] <= nums[r]<= x){
        x=-nums[r];
    }
    else if(nums[r] <nums[l]<= x){
        x=-nums[l];
    }

}

int main()
{
    string s = "lee(t(c)o)de)";
    minRemoveToMakeValid(s);
    return 0;
}
