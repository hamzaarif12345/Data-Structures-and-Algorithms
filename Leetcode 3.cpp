#include<bits/stdc++.h>
using namespace std;
void print(vector<char> &q){
	for(int i=0;i<q.size();i++)
		cout<<q[i];
}
void delete1(vector<char> &c, char k){
	int j=0;
	vector<int>::iterator it;
 	it = c.begin();
 	for (auto it = c.begin(); it != c.end();++it){
 		if(k==*it)
 			c.erase(it);
 		//j++;
 	}
        

	/*for(int i=0,i<c.size();i++){
		if(c[i]==k)
			j=i;
	}
	c.erase(j);


    myvector.erase(it);*/
 
    // Printing the Vector
    



}
int sol(string &s){
	vector<char> c;
	int count=0,res=0;
	for(int i=0;i<s.length();i++){
		if(find(c.begin(), c.end(),s[i])!=c.end()){
			//l++;
			//c.clear();
			//c.pop_front();
			reverse(c.begin(),c.end());
			c.pop_back();
			c.push_back(s[i]);
			count =c.size();
			}
		else{
			c.push_back(s[i]);
			count=c.size();
			//r++;
			res=max(res,count);
			//print(c);
			//cout<<"\n";
		}


	}
	cout<<(res);
	//return (r-l);
	
}
int main(){
	string s="pwwkew";
	string s1="bbbbb";
	string s2="dvdf";
	cout<<"\n result is ";
	sol(s);
	cout<<"\n result is ";
	sol(s1);
	cout<<"\n result is ";
	sol(s2);
	return 0;

}

//leet code 3
