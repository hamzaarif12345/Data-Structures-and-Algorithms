/*
981. Time Based Key-Value Store
Attempted
Medium
Topics
Companies
Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

Implement the TimeMap class:

TimeMap() Initializes the object of the data structure.
void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".
 

Example 1:

Input
["TimeMap", "set", "get", "get", "set", "get", "get"]
[[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
Output
[null, null, "bar", "bar", null, "bar2", "bar2"]

Explanation
TimeMap timeMap = new TimeMap();
timeMap.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
timeMap.get("foo", 1);         // return "bar"
timeMap.get("foo", 3);         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
timeMap.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
timeMap.get("foo", 4);         // return "bar2"
timeMap.get("foo", 5);         // return "bar2"
*/

class TimeMap {
public:
    unordered_map<string, unordered_map<string, int>> m;
    TimeMap() {

    }
    void set(string key, string value, int timestamp) {
        m[key][value] = timestamp;
    }
    string get(string key, int timestamp) {
        string ans;
        for (auto a : m[key]) {
            if (a.second == timestamp) return a.first;
            else {
                int min = INT_MAX;
                bool flag=false;
                auto c = m[key].begin(); // Initialize 'c' with the beginning of the map
                for (auto b : m[key]) {
                    if ((abs(b.second - timestamp) < min )  &&(timestamp >=b.second)) { min = abs(b.second - timestamp); c = m[key].find(b.first);flag=true; }
                }
                if(flag==false) return "";
                return c->first;
            }
        }
        return ""; // Return an empty string or handle the case when no match is found
    }
};
