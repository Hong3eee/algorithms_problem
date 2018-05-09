#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

//	vector<int> v;
	int v[N];

	int N,K;
	scanf("%d",&N);
	scanf("%d",&K);

	int x;
	for(int i =0;i<N;i++)
	{
		scanf("%d",&v[i]);
//		scanf("%d",&x);
//		v.push_back(x);
	}

//	sort(v.begin(),v.end());
	sort(&v[0],&v[N]);

	printf("%d\n",v[K-1]);
	return 0;
}
