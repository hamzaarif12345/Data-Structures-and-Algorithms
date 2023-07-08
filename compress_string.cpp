/*Given an array of characters chars, compress it using the following algorithm:

Begin with an empty char s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed char s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.

 

Example 1:

Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
Example 2:

Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]
Explanation: The only group is "a", which remains uncompressed since it's a single character.
Example 3:

Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".*/




#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int countOccurrences(std::vector<char>& array, char a) {
    int count = 0;
    for (int i = 0; i < array.size(); i++) {
        if (array[i] == a)
            count++;
    }
    return count;
}

void sol(std::vector<char>& array) {
    std::map<char, int> map;
    std::sort(array.begin(), array.end());

    for (int i = 0; i < array.size(); i++) {
        if (i == 0 || array[i] != array[i - 1]) {
            char a = array[i];
            int k = countOccurrences(array, a);
            map[a] = k;
        }
    }

    std::map<char, int>::iterator it = map.begin();
    while (it != map.end()) {
        std::cout << it->first <<" "<< it->second <<" ";
        ++it;
    }
}

int main() {
    std::vector<char> arr = { 'a', 'a', 'b', 'b', 'c', 'c', 'c' };
    sol(arr);
    return 0;
}
