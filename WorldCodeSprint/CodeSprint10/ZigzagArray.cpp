#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int arr[105],inc[105],dec[105];
	int n,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	memset(inc,0,sizeof(inc));
	memset(dec,0,sizeof(dec));
	//check for increase and decrease
	for(int i=1;i<n;i++){
		if(arr[i]>arr[i-1])
			inc[i]=inc[i-1]+1;
		if(arr[i]<arr[i-1])
			dec[i]=dec[i-1]+1;
	}
	for(int i=1;i<n;i++){
		if(inc[i]>=2 && inc[i]>inc[i-1] && (i==n-1 || inc[i]>inc[i+1]))
			ans+=inc[i]-1;
		if(dec[i]>=2 && dec[i]>dec[i-1] && (i==n-1 || dec[i]>dec[i+1]))
			ans+=dec[i]-1;

	}
	printf("%d\n",ans);
	
	return 0;
}
