//Manhanttan2
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#define MAX 105
using namespace std;


int map[MAX][MAX];
int candy[MAX][MAX];
void BFS(int startX, int startY, int endX, int endY){
	for(int y=startY+1;y<=endY;y++){
		candy[startX][y]=candy[startX][y-1]+map[startX][y];
	}
	for(int x=startX+1;x<=endX;x++){
		candy[x][startY]=candy[x-1][startY]+map[x][startY];
	}
	for(int x=startX+1;x<=endX;x++){
		for(int y=startY+1;y<=endY;y++){
			if(candy[x-1][y]>=candy[x][y-1])
				candy[x][y]=candy[x-1][y]+map[x][y];
			else
				candy[x][y]=candy[x][y-1]+map[x][y];
		}
	}
}
int main()
{
	int N,M,T;
	int maxX,maxY,maxCandy=0,minP,ans;
	scanf("%d%d%d",&N,&M,&T);
	memset(candy,0,sizeof(candy));
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			scanf("%d",&map[i][j]);
			if(maxCandy<map[i][j]){
				maxCandy=map[i][j];
				maxX=i;
				maxY=j;
			}
			else if(maxCandy==map[i][j] && (maxX+maxY)>(i+j)){
				maxX=i;
				maxY=j;
			}
		}
	}
	//minP=minimum steps to go map[N][M] from map[0][0]
	minP=N-1+M-1;
	if(minP>T)
		printf("Too late\n");
	else{
		candy[1][1]=map[1][1];
		BFS(1,1,maxX,maxY);
		BFS(maxX,maxY,N,M);
		ans=candy[N][M]+(T-minP)*maxCandy;
		printf("%d\n",ans);
	}
	return 0;
}
