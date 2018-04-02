#include <stdio.h>

using namespace std;

int m[11];

int func(int n){

	if(m[n]>0)
		return m[n];

	m[n] = func(n-3) + func(n-2) + func(n-1);

	return m[n];
}

int main(){

	int T;
	scanf("%d",&T);
	m[1] =1;
	m[2] =2;
	m[3] =4;

	for(int i=0;i<T;i++){
		int n;
		scanf("%d",&n);
		printf("%d\n",func(n));
	}
	return 0;
}
