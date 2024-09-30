class CustomStack {
public:
    int temp = 0;
    int m;
    stack<int> s;

    CustomStack(int maxSize) {
        m = maxSize;
    }

    void push(int x) {
        if (temp < m) {
            s.push(x);
            temp++;
        }
    }

    int pop() {
        if (temp == 0) return -1;
        else {
            int a = s.top();
            s.pop();
            temp--;
            return a;
        }
    }

    void increment(int k, int val) {
        vector<int> arr;
        while (!s.empty()) {
            arr.push_back(s.top());
            s.pop();
        }

        int limit = min(k, (int)arr.size());
        for (int i = 0; i < limit; i++) {
            arr[arr.size() - 1 - i] += val;  // Add 'val' to the first 'k' elements
        }

        // Rebuild the stack
        for (int i = arr.size() - 1; i >= 0; i--) {
            s.push(arr[i]);
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k, val);
 */
