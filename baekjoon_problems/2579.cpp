#include <stdio.h>
#include <algorithm>
using namespace std;

long long int a[301];
long long int d[301];

int main(){
	int n;
	scanf("%d",&n);

	for(int i = 1; i<n+1;i++)
		scanf("%lld",&a[i]);

	d[1] = a[1];
	d[2] = a[1]+a[2];
	for(int i = 3; i<n+1;i++)
	{
		d[i] = max(d[i-2]+a[i] , d[i-3]+a[i-1]+a[i]);
	}

	printf("%lld\n",d[n]);

	return 0;
}
