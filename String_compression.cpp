#include<bits/stdc++.h>
using namespace std;
vector<char> c = {'a','a','b','b','c','c','c'};
vector<char> c1={'w'};
int sol(vector<char> &v){
	int j=0;
	vector<int> q;
	int l=v.size();
	for(int i=0;i<l;i++){
			if(v[i]!=v[i+1]){
				j++;
				q.push_back(i);
			}
				

		}
	vector<int> w;
	//vector<char> ans;
	vector<pair<char,int>> p;
	for(int i=0;i<j;i++){
		int p1=q[i];
		int k=count(v.begin(),v.end(),v[p1]);
		w.push_back(k);
	}
	for(int i=0;i<j;i++){
		int y=q[i];
		//ans.push_back(v[y]);
		//ans.push_back(w[i]);
		p.push_back(make_pair(v[y],w[i]));
	}
	for(int i=0;i<p.size();i++){
		cout<<p[i].first<<" ";
		cout<<p[i].second<<" ";
	}
	cout<<"\n"<<p.size();
	if(j==1)
		return 1;
	else
		return j*2;

}


int main(){
	//string s="hello";
	int h=sol(c);
	cout<<"\n"<<h;
	//cout<<s[3];
}