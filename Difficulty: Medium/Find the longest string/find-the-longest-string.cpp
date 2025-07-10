class Solution {
  public:
    string longestString(vector<string> &arr) {
    string ans = "";

    // Step 1: Sort by length ascending, and lexicographically ascending for equal lengths
    sort(arr.begin(), arr.end());

    // Step 2: Sort again by descending length, but maintain lex order among equals
    sort(arr.begin(), arr.end(), [](const string &a, const string &b) {
        if (a.size() == b.size()) return a < b; // lex smaller first
        return a.size() > b.size();             // longer strings first
    });

    // Step 3: Put all words into a set for fast lookup
    unordered_set<string> m(arr.begin(), arr.end());

    for (const string &word : arr) {
        bool allPrefixesExist = true;

        // Check if all prefixes of this word exist in set
        for (int j = 1; j < word.size(); ++j) {
            string prefix = word.substr(0, j);
            if (m.find(prefix) == m.end()) {
                allPrefixesExist = false;
                break;
            }
        }

        if (allPrefixesExist) {
            // Since sorted by longer & lex smaller, first match is the answer
            return word;
        }
    }

    return "";
}

};