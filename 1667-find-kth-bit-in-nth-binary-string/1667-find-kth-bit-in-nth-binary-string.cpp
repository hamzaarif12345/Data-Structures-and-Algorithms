class Solution {
public:
    // Initialize a vector with 21 strings all set to "-1"
    vector<string> store = vector<string>(21, "-1");

    // Function to invert the string by replacing '0' with '1' and vice versa
    string invert(string &s) {
        string s1;
        for (auto a : s) {
            s1 += (a == '0') ? '1' : '0';
        }
        return s1;
    }

    // Function to calculate the string for a given 'n'
    string calc(int n) {
        // If the value is not precomputed, recursively compute it
        if (store[n - 1] == "-1") {
            store[n - 1] = calc(n - 1);
        }

        // Invert and reverse the previous string to form the current string
        string s1 = store[n - 1];
        string s3 = invert(s1);
        reverse(s3.begin(), s3.end());

        // Combine to form the new string
        string s2 = s1 + "1" + s3;

        // Store the result for future use
        store[n] = s2;

        return s2;
    }

    // Function to find the kth bit in the nth sequence
    char findKthBit(int n, int k) {
        // Prepopulate known values for store[1] to store[4]
        store[1] = "0";
        store[2] = "011";
        store[3] = "0111001";
        store[4] = "011100110110001";

        // Calculate the string for nth if it hasn't been precomputed
        if (store[n] == "-1") {
            calc(n);
        }

        // Return the kth bit (1-indexed)
        return store[n][k - 1];
    }
};
