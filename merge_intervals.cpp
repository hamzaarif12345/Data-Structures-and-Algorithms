#include<bits/stdc++.h>
using namespace std;

void sol(vector<vector<int>> &arr){
	vector<vector<int>> s;
	vector<int> q;
	sort(arr.begin(),arr.end());
	//cout<<arr.size();
	for(int i=0;i<arr.size()-1;i++){
		if(arr[i][1]>=arr[i+1][0]){
			q.push_back(i);
			//cout<<"pushing";
			s.push_back({arr[i][0],arr[i+1][1]});
			//cout<<"\npush done";
		}
	}
	/*ut<<"\nloop exited\n";
	for(int i=0;i<s.size();i++){
		for(int j=0;j<s[0].size();j++){
			cout<<s[i][j]<<" ";
		}
	}*/
	for(int i=0;i<q.size();i++){
		arr.erase(arr.begin()+i);
		arr.erase(arr.begin()+i);
		//int k=(i+1);
		//arr.erase(arr.begin()+k)
	}
	for (int i=0;i<q.size();i++){
	auto itPos = arr.begin() + q[0];
	auto newIt = arr.insert(itPos,s[0] );
}
	cout<<"\n";
	for(int i=0;i<arr.size();i++){
		for(int j=0;j<arr[0].size();j++){
			cout<<arr[i][j]<<" ";
		}
	}

}

int main(){
	vector<vector<int>> array={{1,3},{2,6},{8,10},{15,18}};
	vector<vector<int>> array2={{1,4},{4,5}};
	sol(array);
	sol(array2);
	return 0;
}
