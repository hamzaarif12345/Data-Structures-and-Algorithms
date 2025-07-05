// User function template for C++
class Solution {
  public:

string findLargest(vector<int> &arr) {
    vector<string> temp;

    // Convert integers to strings
    for (int num : arr) {
        temp.push_back(to_string(num));
    }

    // Custom comparator: which combination gives bigger number
    sort(temp.begin(), temp.end(), [](const string &a, const string &b) {
        return a + b > b + a;
    });

    // Edge case: all zeros → avoid returning "000..."
    if (temp[0] == "0") return "0";

    // Build the result string
    string result;
    for (const string &s : temp) {
        result += s;
    }

    return result;
}

};