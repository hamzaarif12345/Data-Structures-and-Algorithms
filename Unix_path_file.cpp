#include<bits/stdc++.h>
using namespace std;

string sol(string s){
	int l=s.length();
	vector<int> x;
	for(int i=l;i>=0;i--){
		if(s[i]=='/')
			x.push_back(i);
		if(x.size()==2)
			break;

	}
	string k;
	for(int i=x[1];i!=x[0];i++){
		k+=s[i];
	}
	cout<<k;
	return k;
}
int main(){
	string A = "/a/./b/../../c/";
	string A1 = "/home/";
	sol(A1);
	//cout<<("| /\\  /\\ |\n");
	//cout<<("/");
	return 0;
}