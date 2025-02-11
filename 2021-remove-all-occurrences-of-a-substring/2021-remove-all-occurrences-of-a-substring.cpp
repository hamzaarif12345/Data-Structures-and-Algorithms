class Solution {
public:
    string removeOccurrences(std::string s, std::string part) {
    int l = part.size();
    std::string temp = "";
    
    for (int i = 0; i < s.size(); i++) {
        temp += s[i]; // Append character to temp

        // Check if last `l` characters of `temp` match `part`
        if (temp.size() >= l && temp.substr(temp.size() - l) == part) {
            //temp.erase(temp.size() - l); // Remove last `l` characters (remove `part`)
            temp=temp.substr(0,temp.size()-l);
        }
    }
    
    return temp;
}

};