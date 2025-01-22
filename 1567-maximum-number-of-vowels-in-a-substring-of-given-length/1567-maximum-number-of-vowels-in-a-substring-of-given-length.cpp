class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0, currentVowelCount = 0;

        // Helper function to check if a character is a vowel
        auto isVowel = [](char ch) {
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        };

        // Initial calculation for the first window
        for (int i = 0; i < k; ++i) {
            if (isVowel(s[i])) {
                ++currentVowelCount;
            }
        }
        ans = currentVowelCount;

        // Sliding window: move the window one character at a time
        for (int i = k; i < s.size(); ++i) {
            if (isVowel(s[i])) {
                ++currentVowelCount; // Add the new character
            }
            if (isVowel(s[i - k])) {
                --currentVowelCount; // Remove the character going out of the window
            }
            ans = max(ans, currentVowelCount); // Update the maximum vowels count
        }

        return ans;
    }
};
