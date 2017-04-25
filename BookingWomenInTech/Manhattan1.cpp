//Manhatton1-solution2
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAX 1000005
using namespace std;

struct position{
	long long int x,y;
}Hotel[MAX];
int main()
{
	long long int X,Y,L,H;
	long long int minID;
	long long int x, y, sumX=0, sumY=0, minDis=-1, distance;
	scanf("%lld%lld%lld%lld",&X,&Y,&L,&H);
	for(int i=0;i<L;i++){
		scanf("%lld%lld",&x,&y);
		sumX+=x;
		sumY+=y;
	}
	for(int i=1;i<=H;i++){
		scanf("%lld%lld",&Hotel[i].x,&Hotel[i].y);
	}
	for(long long int i=1;i<=H;i++){
		distance=abs(L*Hotel[i].x-sumX)+abs(L*Hotel[i].y-sumY);
		if(minDis<0 || distance<minDis){
			minDis=distance;
			minID=i;
		}
	}
	printf("%lld\n",minID);
	return 0;
}
