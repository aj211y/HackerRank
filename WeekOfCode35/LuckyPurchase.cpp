#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string.h>
#include<cstring>
#define MAX 1000000001
using namespace std;

struct Laptop{
	string name;
	int price;
}laptop;
bool isEqual(int p){
	int cnt=0, m;
	for(int i=0;p>0 ;i++)
	{
		m = p % 10;
		if(m == 7){
			cnt++;
		}
		else if(m == 4){
			cnt--;
		}
		else{
			cnt=MAX;
			break;
		}
		p=p/10;	
	}
	if(cnt==0)
		return true;
	else
		return false;
}
int main()
{
	int n, price;
	string name;
	laptop.name="-1";
	laptop.price=MAX;
	scanf("%d",&n);
	while(n--){
		cin >> name >> price;
		if(isEqual(price) && price < laptop.price){
			laptop.name=name;
			laptop.price=price;
		}
	}
	cout << laptop.name << endl;
	return 0;
}
