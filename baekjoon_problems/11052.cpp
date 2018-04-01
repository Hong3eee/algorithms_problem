#include <stdio.h>
#include <algorithm>

using namespace std;

int p[10001];
int d[10001];

int main(){
	int N;
	scanf("%d",&N);

	for(int i=1;i<N+1;i++)
		scanf("%d",&p[i]);

	d[0]=0;

	for(int i=1;i<N+1;i++)
		for(int j=1;j<i+1;j++)
			d[i] = max(d[i],max(p[i],d[i-j]+d[j]));

	printf("%d\n",d[N]);

	return 0;
}


