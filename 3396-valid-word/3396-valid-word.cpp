class Solution {
public:

    // Helper to check if a character is alphanumeric (digit or lowercase letter)
    bool check(char c) {
        // Check if it's a digit
        if (isdigit(c)) return true;

        // Check if it's a letter
        if (isalpha(c) ) return true;

        return false;
    }

    // Helper to check that the word has at least one vowel and one consonant
    bool check2(const string& word) {
        int v = 0, c = 0;

        for (char a : word) {
            char ch = tolower(a);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                v++;
            } else if (isdigit(ch)) {
                continue;  // skip digits
            } else if (isalpha(ch)) {
                c++;
            }
        }

        return (v > 0 && c > 0);
    }

    bool isValid(string word) {
        // Condition 1: Word should have at least 3 characters
        if (word.size() < 3) return false;

        // Condition 2: All characters must be digits or lowercase letters
        for (char a : word) {
            if (!check(a)) return false;
        }

        // Condition 3: Must contain at least one vowel and one consonant
        if (!check2(word)) return false;

        return true;
    }
};
