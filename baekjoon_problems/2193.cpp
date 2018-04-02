#include <stdio.h>
#include <algorithm>

using namespace std;
long long int d[100];

int main(){
	
	int N;
	scanf("%d",&N);
	
	d[1] = 1;
	d[2] = 1;

	for(int i =3;i<N+1;i++){

		d[i] = d[i-1] + d[i-2];
	}

	printf("%lld\n",d[N]);

	return 0;
}
