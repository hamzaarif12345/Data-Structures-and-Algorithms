#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string compressedString(string word) {
        vector<pair<char, int>> countVec;
        string ans;

        // Count occurrences of each character in order
        for (char c : word) {
            // Check if the character is already in the vector
            if (!countVec.empty() && countVec.back().first == c) {
                // Increment the count of the last character
                countVec.back().second++;
            } else {
                // Add a new character to the vector with count 1
                countVec.push_back({c, 1});
            }
        }

        // Build the compressed string from the vector
        for (auto& p : countVec) {
            char ch = p.first;
            int count = p.second;

            if (count <= 9) {
                ans += to_string(count);
                ans += ch;
                  // Convert count to string and append
            } else {
                // For counts greater than 9, add as many '9' chunks as needed
                while (count > 9) {
                    
                    ans += '9';
                    count -= 9;
                    ans += ch;
                }
                // Append remaining count if any
                if (count > 0) {
                    
                    ans += to_string(count);
                    ans += ch;
                }
            }
        }

        return ans;
    }
};
