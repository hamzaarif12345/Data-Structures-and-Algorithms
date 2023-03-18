#include<bits/stdc++.h>
using namespace std;

int Sol(vector<int> &a,vector<int> &b){
	int q=a.size();
	int w=b.size();
	vector<int> d;
	for(int i=0;i<a.size();i++)
		d.push_back(a[i]);
	for(int i=0;i<b.size();i++)
		d.push_back(b[i]);
	int r=d.size();
	sort(d.begin(),d.end());
	int mid=(r/2);
	int ans;
	if(r%2!=0)
		cout<<d[mid-1];
	else
		cout<<d[mid-1]<<" "<<d[mid];
	return 0;
}
int main(){
	vector<int> a={1,2,3,4,6};
	vector<int> b={0,4,5,8,9};
	Sol(a,b);
	return 0;

}