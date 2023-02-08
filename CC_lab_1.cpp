#include <bits/stdc++.h>
#include <typeinfo>
using namespace std;
stack<int> st2;
int result1[100];
int prec(char c)
{
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}
int op(char c){
    if(c=='^' || c=='/' || c=='*' || c=='+' || c=='-' || c=='#' )
        return -1;
}
void infixToPostfix(string s)
{

	stack <wchar_t> st; // For stack operations, we are using
					// C++ built in stack
	string result;
    stack <wchar_t> st1;
    for (int i = 0; i < s.length(); i++) {
		char c = s[i];
        if(op(c)==-1){
			    result +=" ";
                auto i=(result).c_str();
                int q=atoi(i);
                st2.push(q);
                //st2.push();
			}
        
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
			result += c;
		    
			
		}
		else if (c == '(')
			st.push('(');

		else if (c == ')') {
			while (st.top() != '(') {
				result += st.top();
				//result += " ";
				st.pop();
			}
			
			st.pop();
		}
        else {
			while (!st.empty()
				&& prec(s[i]) <= prec(st.top())) {
				result += st.top();
				result +=" ";
				st.pop();
			}
			st.push(c);
		}
	}
    while (!st.empty()) {
		result += st.top();
		st.pop();
	}
    cout << result << endl;
}
int main()
{
    
	string exp = "(100+98)-(8/6)";
    infixToPostfix(exp);
	string ex;
	cout<<"\nenter the string:";
	cin>>ex;
	infixToPostfix(ex);
	//cout << typeid(ex).name() << endl;
    int j=0;
    while (!st2.empty()) {
        int w=st2.top();
        st2.pop();
		result1[j] += w;
        j++;
    }
    cout<<j;
	return 0;
}



