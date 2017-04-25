//B.Available
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#define MAX 305
using namespace std;

int P[MAX][MAX],minS[MAX][MAX],maxS[MAX][MAX];
int N,M;
void sol(int C, int L)
{
	int sum=0;
	int cheapest;
	for(int date=C;date<C+L;date++){
		cheapest=5000;
		for(int cato=1;cato<=M;cato++){
			if(minS[cato][date]<=L && L<=maxS[cato][date] && P[cato][date]!=0 && cheapest>P[cato][date]){
				cheapest=P[cato][date];
			}
		}
		if(cheapest==5000){//no available exist
			sum=-1;
			break;
		}
		else
			sum+=cheapest;
	}
	printf("%d\n",sum);
}
int main()
{
	int Q,C,L;
	scanf("%d%d%d",&N,&M,&Q);
	for(int i=1;i<=M;i++){
		for(int j=1;j<=N;j++){
			scanf("%d",&P[i][j]);
		}
	}
	for(int i=1;i<=M;i++){
		for(int j=1;j<=N;j++){
			scanf("%d",&minS[i][j]);
		}
	}
	for(int i=1;i<=M;i++){
		for(int j=1;j<=N;j++){
			scanf("%d",&maxS[i][j]);
		}
	}
	for(int i=1;i<=Q;i++){
		scanf("%d%d",&C,&L);
		sol(C,L);
	}
	return 0;
}
