#include<bits/stdc++.h>
using namespace std;

int decode_string(string s){	
	vector<pair<char,int>> p={{'A',1},{'B',2},{'C',3},{'D',4},{'E',5},{'F',6},{'G',7},{'H',8},{'I',9},{'J',10},{'K',11},{'L',12},{'M',13},{'N',14},{'O',15},{'P',16},{'Q',17},{'R',18},{'S',19},{'T',20},{'U',21},{'V',22},{'W',23},{'X',24},{'Y',25},{'Z',26}};
	int n=s.length();
	/*vector<int> q;
	for(int i=0;i<s;i++){
		int k=s[i]
	}*/
}
int isSubstring(string s1, string s2)
{
    // using find method to check if s1 is
    // a substring of s2
    if (s2.find(s1) != string::npos)
        return s2.find(s1);
    return -1;
}

bool wordBreak(string s, vector<string>& wordDict){
	string y="";
	for(int i=0;i<wordDict.size();i++){
		y+=wordDict[i];
	}
	
	if(isSubstring(y,s)==-1  && isSubstring(s,y)==-1)
		return false;
	else
		return true;
	
}
int main(){
	vector<string> w={"apple","pen"};
	string k="applepenapple";
	int p=wordBreak(k,w);
	cout<<p;
	return 0;
}