#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string.h>
#define MAX 110
using namespace std;

int ans[MAX][MAX];
void sol(int n,int m,int k)
{
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==0 && j==0)
				ans[i][j]=m;
			else if(i==j)
				ans[i][j]=ans[i-1][j-1]+k;
			else if(i>j)
				ans[i][j]=ans[i-1][j]-1;
			else
				ans[i][j]=ans[i][j-1]-1;
		}
	}
}
int main()
{
	int n,m,k;
	memset(ans,0,sizeof(ans));
	scanf("%d%d%d", &n, &m,&k);
	sol(n,m,k);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j!=0)
				printf(" ");
			printf("%d", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
