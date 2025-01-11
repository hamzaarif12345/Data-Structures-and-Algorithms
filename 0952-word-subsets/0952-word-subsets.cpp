#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;

        // Step 1: Create a frequency vector `v1` for the maximum character frequencies in words2
        vector<int> v1(26, 0);
        for (const string& word : words2) {
            vector<int> freq(26, 0);
            for (char c : word) {
                freq[c - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                v1[i] = max(v1[i], freq[i]); // Take the maximum frequency for each character
            }
        }

        // Step 2: Check each word in words1 against `v1`
        for (const string& word : words1) {
            vector<int> freq(26, 0);
            for (char c : word) {
                freq[c - 'a']++;
            }

            bool isSubset = true;
            for (int i = 0; i < 26; ++i) {
                if (freq[i] < v1[i]) { // If the word doesn't satisfy the requirement
                    isSubset = false;
                    break;
                }
            }

            if (isSubset) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};
