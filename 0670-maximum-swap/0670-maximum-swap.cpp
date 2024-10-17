class Solution {
public:
    int maximumSwap(int num) {
        // Store original number for processing
        int original = num;
        // Count frequency of each digit
        vector<int> v(10, 0);  // Changed to size 10 for digits 0-9
        while(num > 0) {
            int a = num % 10;
            num = num / 10;  // Fixed division operator
            v[a]++;
        }
        
        // Create priority queue of {digit, frequency}
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i < v.size(); i++) {
            if(v[i] > 0) pq.push({i, v[i]});  // Push {digit, frequency}
        }
        
        // Convert original number to string
        string s = to_string(original);
        
        // Process each digit
        for(int i = 0; i < s.length(); i++) {
            if(!pq.empty() && (s[i]-'0' < pq.top().first)) {
                // Find the rightmost position of the largest digit
                int maxDigit = pq.top().first;
                int lastPos = s.length() - 1;
                
                while(lastPos > i) {
                    if(s[lastPos] - '0' == maxDigit) {
                        break;
                    }
                    lastPos--;
                }
                
                // Swap the digits
                swap(s[i], s[lastPos]);
                return stoi(s);
            }
            
            // Update priority queue
            int currentDigit = s[i] - '0';
            v[currentDigit]--;
            if(v[currentDigit] == 0) {
                priority_queue<pair<int,int>> temp;
                while(!pq.empty()) {
                    if(pq.top().first != currentDigit) {
                        temp.push(pq.top());
                    }
                    pq.pop();
                }
                pq = temp;
            }
        }
        
        return original;
    }
};