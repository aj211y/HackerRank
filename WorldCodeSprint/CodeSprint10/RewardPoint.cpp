#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int m1,m2,m3,ans=0;
	scanf("%d%d%d",&m1,&m2,&m3);
	if(m1*10>100){
		ans+=100;
	}
	else{
		ans+=m1*10;
	}
	if(m2*10>100){
		ans+=100;
	}
	else{
		ans+=m2*10;
	}
	if(m3*10>100){
		ans+=100;
	}
	else{
		ans+=m3*10;
	}
	printf("%d\n",ans);
	return 0;
}
