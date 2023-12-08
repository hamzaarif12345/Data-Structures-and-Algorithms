// CS For ALL

// exponentiation

// b&1 means set bit which mean in the binary representation the number is set to 1 

#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main(){
	int a=3;
	int b=17;
	int res=1;
	while(b>0){
		if((b&1)>0)
			res=((res%mod)*(a%mod))%mod;
		a=((a%mod)*(a%mod))%mod;
		b=((b>>1));
	}
	cout<<res;
	return 0;
}