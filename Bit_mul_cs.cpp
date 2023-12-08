// CS For ALL

// exponentiation

// b&1 means set bit which mean in the binary representation the number is set to 1 

#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main(){
	int a=1000;
	int b=17000;
	int res=0;
	while(b>0){
		if((b&1)>0)
			res=((res%mod)+(a%mod))%mod;
		a=((a%mod)*2)%mod;
		b=((b>>1));
	}
	cout<<res;
	return 0;
}