#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int t[20];
int p[20];
int d[20]; // index 까지 봤을때의 최대값.

int main(){
	scanf("%d",&n);
	for(int i =1;i<=n;i++)
		scanf("%d %d",&t[i],&p[i]);


	for(int i =1;i<=n;i++)
		for(int j = i;j>0;j--)
			if( t[j] <= i-j +1)
				d[i] = max(d[i], p[j] + d[j-1]);

	printf("%d\n",d[n]);
	return 0;
}
