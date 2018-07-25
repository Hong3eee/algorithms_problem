#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n,m;
int price[20];
int value[20];
int d[10000000];

int sushi()
{
	memset(d,0,sizeof(d));
	int ret = 0;
	for(int i = 1 ; i <= m ; i++)
	{
		for(int j =0 ; j < n; j++)
		{
			if(i >= price[j])
			{
				int tmp = d[i - price[j]];
				d[i] = max(d[i] , tmp + value[j]);
			}
		}
		ret = d[i];
	}
	return ret;
}

int main(){

	int c;
	cin >> c;
	for(int z = 0 ; z<c;z++)
	{
		cin >> n >> m;
		for(int i = 0;i<n;i++)
			cin >> price[i] >> value[i];


		for(int i = 0;i<n;i++)
			price[i] = price[i]/100;
		m = m/100;

		cout << sushi() << endl;
	}

	return 0;
}
