#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int arr[100][100];
bool d[100][100];

int main(){

	int t,n;
	scanf("%d",&t);

	for(int i =0;i<t;i++)
	{
		memset(arr,-1,sizeof(arr));
		memset(d,false,sizeof(d));
		d[0][0] = true;
		scanf("%d",&n);
		for(int y=0;y<n;y++)
			for(int x=0;x<n;x++)
				scanf("%d",&arr[y][x]);

		for(int y=0;y<n;y++)
			for(int x=0;x<n;x++)
			{
				if(d[y][x] == true)
				{
					if(x + arr[y][x] > n) ;
					else d[y][x+arr[y][x]] = true;

					if(y + arr[y][x] > n) ;
					else d[y+arr[y][x]][x] = true;
				}
			}

		printf("%s\n",d[n-1][n-1] ? "YES" : "NO");

	}

	return 0;
}
