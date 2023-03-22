#include<bits/stdc++.h>
using namespace std;
int sol(vector<int> &a){
	int count=0;
	int l=0,r=0,i=0,res=0;
	while(r!=a.size()){
		if(a[i]==0)
			count++;
		if(count >1)
			l=i;
		r++;
		i++;
		res=max(res,(r-l));
	}
	cout<<(res-1);
	return r;
	
}
int main(){
	vector<int> a={1,1,1,1,1,1,0,1};
	sol(a);
	return 0;

}

//leet code 1453