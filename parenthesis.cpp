/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;
        if(s.size()==0) return true;
        for (auto i:s)
        {
        	if(i=='(' || i=='{' || i=='['){
        		s1.push(i);
        	}
        	else{
						if (s1.empty()) return false;
        		if((s1.top()=='(' && i==')') || (s1.top()=='{' && i=='}') || (s1.top()=='[' && i==']')){
        			s1.pop();
        		}
						else return false;
        	}
    	}
    	return s1.empty();
    }
};
int main(){

	return 0;
}