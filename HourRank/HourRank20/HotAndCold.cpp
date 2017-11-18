#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main()
{
	int a,b,c,d,m,M;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a<b)
		m=b;
	else
		m=a;
	if(c<d)
		M=c;
	else
		M=d;
	if(m<=M)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
