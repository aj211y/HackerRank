//Highlight Landmarks
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string D,str;
	int L;
	set<string> Landmarks;

	char words[3000];
	char* pch;

	getline(cin,D);
	scanf("%d",&L);
	for(int i=0;i<L;i++){
		cin >> str;
		Landmarks.insert(str);
	}

	strcpy(words,D.c_str());
	pch=strtok(words," ");
	while(pch!=NULL){
		//printf("%s ",pch);
		str=string(pch);
		pch=strtok(NULL," ");
		if(Landmarks.find(str)!=Landmarks.end())
			printf("<b>%s</b>",str.c_str());
		else
			printf("%s",str.c_str());
		if(pch!=NULL)
			printf(" ");
	}
		
	return 0;
}
