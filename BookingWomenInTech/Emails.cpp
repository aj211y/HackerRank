//Emails
//TLE
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

struct Email{
	string content;
	int urgency,ID;
};
bool cmp(Email a, Email b)
{
	if(a.urgency>b.urgency)
		return true;
	else if(a.urgency<b.urgency)
		return false;
	else if(a.urgency==b.urgency && a.ID<b.ID)
		return true;
	else
		return false;
}
int main()
{
	vector<Email> buffer;
	Email eTmp;
	bool lastMoveIsGet;
	int N,newID=1;
	string str;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		cin >> str;
		if(str=="store"){
			cin >> eTmp.content >> eTmp.urgency;
			eTmp.ID=newID++;
			buffer.push_back(eTmp);
			lastMoveIsGet=false;
		}
		else{//output
			if(buffer.size()==0)
				printf("-1\n");
			else{
				if(!lastMoveIsGet)
					sort(buffer.begin(),buffer.end(),cmp);
				printf("%s\n",buffer[0].content.c_str());
				buffer.erase(buffer.begin());
			}
			lastMoveIsGet=true;
		}
	}
	return 0;
}
