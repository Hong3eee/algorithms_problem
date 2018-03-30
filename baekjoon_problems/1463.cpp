#include <stdio.h>
#include <algorithm>

using namespace std;

int m[1000001];

int func(int n){

	if(n==1)
		return 0;

	if(m[n]>0)
		return m[n];

	int tmp=1000000,tmp2=1000000,tmp3=1000000;
	
	if(n%3 == 0)
		tmp = func(n/3);
	if(n%2 == 0)
		tmp2 = func(n/2);

	tmp3 = func(n-1);

	m[n] = min(min(tmp,tmp2),tmp3) +1;

	return m[n];
}

int main(){
	m[1]=0;
	m[2]=1;
	m[3]=1;

	int N;
	scanf("%d",&N);

	printf("%d\n",func(N));

	return 0;
}
