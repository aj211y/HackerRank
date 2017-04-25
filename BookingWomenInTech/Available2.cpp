//B.Available2
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#define MAX 305
using namespace std;

struct Hotel{
	int price, minStay, maxStay; 
};
vector<Hotel> day[MAX];
int P[MAX][MAX],minS[MAX][MAX],maxS[MAX][MAX];
int N,M;
void sol(int C, int L)
{
	int sum=0;
	int cheapest;
	for(int date=C;date<C+L;date++){
		cheapest=5000;
		for(int cato=0;cato<day[date].size();cato++){
			if(day[date][cato].minStay<=L && L<=day[date][cato].maxStay && cheapest>day[date][cato].price){
				cheapest=day[date][cato].price;
				break;
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
bool cmp(Hotel a, Hotel b)
{
	return a.price<b.price;
}
int main()
{
	int Q,C,L;
	Hotel hTmp;
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
	for(int i=1;i<=M;i++){
		for(int j=1;j<=N;j++){
			if(P[i][j]!=0 && maxS[i][j]!=0){
				hTmp.price=P[i][j];
				hTmp.minStay=minS[i][j];
				hTmp.maxStay=maxS[i][j];
				day[j].push_back(hTmp);
			}
		}
	}
	for(int i=1;i<=N;i++){
		sort(day[i].begin(),day[i].end(),cmp);
	}
	for(int i=1;i<=Q;i++){
		scanf("%d%d",&C,&L);
		sol(C,L);
	}
	return 0;
}
