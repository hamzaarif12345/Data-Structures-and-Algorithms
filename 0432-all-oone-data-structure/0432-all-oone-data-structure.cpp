class AllOne {
public:
    unordered_map<string, int> m;
    string mx = ""; 
    string mn = ""; 
    int mxc = INT_MIN; 
    int mnc = INT_MAX; 

    AllOne() {}
    void inc(string key) {
        m[key]++;

        // Recalculate maximum and minimum if necessary
        if (m[key] > mxc || mx == "") { // Update max key
            mxc = m[key];
            mx = key;
        }
        
        if (m[key] < mnc || mn == "") { // Update min key
            mnc = m[key];
            mn = key;
        }
        
        // In case mnc becomes irrelevant, we need to check after each operation.
        if (m[key] > mnc && mn == key) {
            recalculateMin(); // Find the new minimum
        }
    }

    // Decrement the value of key by 1
    void dec(string key) {
        if (m.find(key) == m.end()) return; // If the key doesn't exist, return
        
        m[key]--;

        if (m[key] == 0) {
            m.erase(key); // Remove key if count reaches 0
        }

        // Recalculate max and min if the key was either the max or min
        if (key == mx) recalculateMax();
        if (key == mn) recalculateMin();
    }

    // Return the key with the maximum value
    string getMaxKey() {
        return mx;
    }

    // Return the key with the minimum value
    string getMinKey() {
        return mn;
    }

private:
    // Helper function to recalculate the key with the maximum value
    void recalculateMax() {
        mxc = INT_MIN;
        mx = "";
        for (const auto &entry : m) {
            if (entry.second > mxc) {
                mxc = entry.second;
                mx = entry.first;
            }
        }
    }

    // Helper function to recalculate the key with the minimum value
    void recalculateMin() {
        mnc = INT_MAX;
        mn = "";
        for (const auto &entry : m) {
            if (entry.second < mnc) {
                mnc = entry.second;
                mn = entry.first;
            }
        }
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
