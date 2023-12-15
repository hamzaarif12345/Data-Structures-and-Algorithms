/*1436. Destination City
Solved
Easy
Topics
Companies
Hint
You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi. Return the destination city, that is, the city without any path outgoing to another city.

It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.

 

Example 1:

Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
Output: "Sao Paulo" 
Explanation: Starting at "London" city you will reach "Sao Paulo" city which is the destination city. Your trip consist of: "London" -> "New York" -> "Lima" -> "Sao Paulo".
Example 2:

Input: paths = [["B","C"],["D","B"],["C","A"]]
Output: "A"
Explanation: All possible trips are: 
"D" -> "B" -> "C" -> "A". 
"B" -> "C" -> "A". 
"C" -> "A". 
"A". 
Clearly the destination city is "A".
Example 3:

Input: paths = [["A","Z"]]
Output: "Z*/

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        string ans;
        vector<string> help;  // Use a vector of strings instead of integers
        int a = paths.size();
        string start = paths[0][1];
        unordered_map<string, int> m;

        for (int i = 0; i < a; i++) {
            for (int j = 0; j < 2; j++) {
                m[paths[i][j]]++;
                help.push_back(paths[i][1]);
            }
        }

        for (const auto& entry : m) {
            if (entry.second == 1 && find(help.begin(), help.end(), entry.first) != help.end()) {
                ans = entry.first;
                break;
            }
        }

        return ans;
    }
};