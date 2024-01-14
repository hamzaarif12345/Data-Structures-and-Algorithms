/* combinations video solve */

#include<bits/stdc++.h>
using namespace std;

int combination(int n,int r){
	vector<int> s;
	s.push_back(1);
	int ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
		s[i]=ans;
	}
	return (s[n]/(s[r]*s[n-r]));
}
int main(){
	int a=combination(10,9);
	cout<<a;
	return 0;
}


/// see the video for the start end question of leetcode