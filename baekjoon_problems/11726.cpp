#include <stdio.h>

using namespace std;

int m[1001];

int func(int n){
	if(m[n]>0)
		return m[n];

	if(n<3)
		return m[n];

	m[n] = (func(n-1) + func(n-2))%10007;

	return m[n];
}

int main(){

	int N;
	scanf("%d",&N);
	m[1] = 1;
	m[2] = 2;

	printf("%d",func(N));

	return 0;
}
