class Solution {
public:
    string trim(const string& s) {
        int i = 0;
        while (i < s.size() && isspace(s[i])) {
            i++;
        }

        int j = s.size() - 1;
        while (j >= 0 && isspace(s[j])) {
            j--;
        }

        // Check if there are any characters left after trimming
        if (i > j) {
            return "";  // The string is entirely whitespace
        }

        // Corrected to return the substring from i to j (inclusive)
        return s.substr(i, j - i + 1);
    }

    bool isCircularSentence(string sentence) {
        string s = trim(sentence);
        if (s.empty() || s[0] != s[s.size() - 1]) {
            return false;
        }
        
        for (int i = 0; i < s.size(); i++) {
            if (isspace(s[i])) {
                if (s[i - 1] != s[i + 1]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};