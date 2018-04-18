#include <stdio.h>
#include <algorithm>
using namespace std;

long long int a[100001];
long long int d[100001][2];

int main(){
	int n;
	scanf("%d",&n);

	for(int i = 1; i<n+1;i++)
		scanf("%lld",&a[i]);

	d[0][0] = -1001;
	d[0][1] = -1001;

	for(int i = 1; i<n+1;i++)
	{
		d[i][0] = max(d[i-1][0],d[i-1][1]);
		d[i][1] = max(max(d[i-1][1],a[i-1]) + a[i],a[i]);
	}

	printf("%lld\n",max(d[n][0],d[n][1]));

	return 0;
}
