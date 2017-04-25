//Emails2
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#define MAX 100005
using namespace std;

//queue<string> buffer[Max];
int main()
{
	queue<string> buffer[MAX];
	set<int> uList;
	set<int>::iterator uIt;
	int N,top=0,urgency;
	string str,content;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		cin >> str;
		if(str=="store"){
			cin >> content >> urgency;
			uList.insert(urgency);
			buffer[urgency].push(content);
			if(urgency>top)
				top=urgency;
		}
		else{//output
			if(top==0)
				printf("-1\n");
			else{
				printf("%s\n",buffer[top].front().c_str());
				buffer[top].pop();
				if(buffer[top].size()==0){
					uList.erase(top);
					if(uList.size()!=0){
						uIt=uList.end();
						uIt--;
						top=*uIt;
					}
					else
						top=0;
				}
			}
		}
	}
	return 0;
}
