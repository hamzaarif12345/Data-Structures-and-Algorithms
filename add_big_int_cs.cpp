// addition of big integers cs for all
#include<bits/stdc++.h>
using namespace std;
string add(string s1,string s2){
	int i=s1.size()-1;
	int j=s2.size()-1;
	int carry=0;
	vector<int> ans;
	while(i>=0 && j>=0){
		ans.push_back(((s1[i]-'0')+(s2[j]-'0'))%10);
		carry=(((s1[i]-'0')+(s2[j]-'0'))/10);
		i--;
		j--;
	}
	while(i>=0){
		ans.push_back(((s1[i]-'0')+carry)%10);
		carry=(((s1[i]-'0')+carry)/10);
		i--;
	}
	while(j>=0){
		ans.push_back(((s2[j]-'0')+carry)%10);
		carry=(((s2[j]-'0')+carry)/10);
		j--;
	}
	if(carry!=0) ans.push_back(carry);
	reverse(ans.begin(),ans.end());
	for(auto it :ans)
		cout<<it;
	return "hello";
}
int main(){
	string s1="123456789022562";
	string s2="987654446466";
	add(s1,s2);
	return 0;
	
}