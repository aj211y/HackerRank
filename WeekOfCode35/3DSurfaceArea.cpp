#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string.h>
#include<algorithm>
#define MAX 110
using namespace std;

int A[MAX][MAX];
int main()
{
	int H,W;
	int lineMax, area, preMax;
	bool isFirstMax;	
	//var change = if there is a change from large to small

	memset(A,0,sizeof(A));
	scanf("%d%d",&H,&W);

	for(int i=0;i<H;i++)
	{
					for(int j=0;j<W;j++)
					{
									scanf("%d",&A[i][j]);
					}
	}
	area=0;		//initialize

	//front side
	for(int i=0;i<H;i++)
	{																																													
					lineMax=0;					
					isFirstMax=false;
					for(int j=0;j<W;j++)
					{
									if(A[i][j]>lineMax){
													preMax=lineMax;
													lineMax=A[i][j];
													isFirstMax=true;
									}
									else
									{
													isFirstMax=false;
									}
									if(j!=0){ 
													if(A[i][j]>A[i][j-1])//going up
													{
																	if(isFirstMax){//the first high in current situation
																					area+=preMax-A[i][j-1];
																	}
																	else{
																					area+=A[i][j]-A[i][j-1];
																	}
													}
									}
						}
						area+=lineMax;
	}

	//left side
		for(int j=0;j<W;j++)
		{
						lineMax=0;
						isFirstMax=false;
						for(int i=0;i<H;i++)
						{
										if(A[i][j]>lineMax){
														preMax=lineMax;
														lineMax=A[i][j];
														isFirstMax=true;
										}
										else
										{
														isFirstMax=false;
										}
										if(i!=0){
														if(A[i][j]>A[i-1][j])
														{
																		if(isFirstMax){
																						area+=preMax-A[i-1][j];
																		}
																		else{
																						area+=A[i][j]-A[i-1][j];
																		}
														}
											}	
							}
							area+=lineMax;
					}
	
			//up side
			area+=H*W;
			//right side + back side + bottom side
			area=area*2;
			printf("%d\n",area);
			return 0;
}
