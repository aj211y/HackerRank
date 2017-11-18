#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string.h>
#include <cstring>
#define MOD 1000000007
using namespace std;

long long int Cal(long long int A, long long int B)
{
	long long int mid,ret=0,retA,retB,curA,curB,rounds;

	if(A<B)
		rounds=A;
	else
		rounds=B;
	
	retA=A;
	retB=B;
	ret=((retA%MOD)*(retB%MOD))%MOD;
	curA=A-1;
	curB=B-1;
	for(long long int r=2;r<=rounds;r++,curA--,curB--){
		retA=((((retA%MOD)*(curA%MOD))%MOD)/r)%MOD;
		retB=((((retB%MOD)*(curB%MOD))%MOD)/r)%MOD;
		ret=(ret+((retA%MOD)*(retB%MOD))%MOD)%MOD;
	}
	return ret;
}
int main()
{
	int q;
	long long int a,b,c,d,numAB,numCD,ans;
	string s;
	scanf("%d",&q);
	while(q--){
		cin >> s;
		a=0;
		b=0;
		c=0;
		d=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='a')
				a++;
			else if(s[i]=='b')
				b++;
			else if(s[i]=='c')
				c++;
			else
				d++;
		}
		numAB=Cal(a,b)+1;//+1 means without a and b
		numCD=Cal(c,d)+1;//+1 means without c and d

		ans=(((numAB%MOD)*(numCD%MOD))%MOD-1)%MOD;
		printf("%lld\n",ans);
	}
	return 0;
}
