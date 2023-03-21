#include<bits/stdc++.h>
using namespace std;
int sol(vector<int> &a){
	int r=0;
	for(int i=0;i<a.size();i++){
		r=r^a[i];
	}
	cout<<r;
	return r;
}
int main(){
	vector<int> a={2,2,4,1,1,3,3};
	sol(a);
	return 0;

}