//Manhatton
//WA
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAX 1000005
using namespace std;

struct position{
	double x,y;
}Hotel[MAX];
int main()
{
	long long int X,Y,L,H;
	long long int minID;
	double x, y, sumX=0, sumY=0, midX, midY, minDis=MAX, distance;
	scanf("%lld%lld%lld%lld",&X,&Y,&L,&H);
	for(int i=0;i<L;i++){
		scanf("%lf%lf",&x,&y);
		sumX+=x;
		sumY+=y;
	}
	midX=sumX/L;
	midY=sumY/L;
	for(int i=1;i<=H;i++){
		scanf("%lf%lf",&Hotel[i].x,&Hotel[i].y);
	}
	for(long long int i=1;i<=H;i++){
		distance=abs(Hotel[i].x-midX)+abs(Hotel[i].y-midY);
		if(distance<minDis){
			minDis=distance;
			minID=i;
		}
	}
	printf("%lld\n",minID);
	return 0;
}
